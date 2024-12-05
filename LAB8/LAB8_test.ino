#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

// set up wifi
#define WLAN_SSID "KN"
#define WLAN_PASS "nganxinhdep"

// set up Adafruit
#define AIO_SERVER "io.adafruit.com"
#define AIO_SERVERPORT 1883

// user set up
#define AIO_USERNAME "LTKNgan"
#define AIO_KEY "aio_yFAu41CXUOeqpQ2r5ixxRKPAkQCO"

// set up MQTT
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

// set publish
Adafruit_MQTT_Publish light_pub = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/lab8-led");
Adafruit_MQTT_Publish temperature_pub = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/temperature");
// set up subcribe 
Adafruit_MQTT_Subscribe light_sub = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/lab8-led", MQTT_QOS_1);


int led_counter = 0;
int led_status = HIGH;

void lightcallback(char* value, uint16_t len){
  if (value[0] == '0') Serial.print ('a');
  if (value[0] == '1') Serial.print ('A');
}

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);

  digitalWrite(5, HIGH);

  Serial.begin(115200);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

// subscribe light feed
  light_sub.setCallback(lightcallback);
  mqtt.subscribe(&light_sub);

// connect MQTT
  while (mqtt.connect() != 0) {
    mqtt.disconnect();
    delay(500);
  }
  digitalWrite(5, LOW);
}

void loop() {
  mqtt.processPackets(1) ;

  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    int msg = Serial.read();
    if (msg == 'o') Serial.print("O");
    else if (msg == 'a') light_pub.publish(0);
    else if (msg == 'A') light_pub.publish(1);
  }

  // if (Serial.available() > 0) {
  //   String tempData = Serial.readStringUntil('#'); 
  //   if (tempData.startsWith("!TEMP:")) { 
  //     String temperature = tempData.substring(6); 
  //     temperature_pub.publish(temperature.toFloat()); 
  //     // Serial.print(temperature);
  //     // Serial.print("\t");
  //     // Serial.print(temperature.toFloat());
  //     // Serial.print("\n");
  //   } 
  // }

  led_counter++;
  if (led_counter  == 100) {
    led_counter = 0;
    if (led_status == HIGH) led_status = LOW;
    else led_status = HIGH;

    digitalWrite(2, led_status);
  }
  delay(10);
}
