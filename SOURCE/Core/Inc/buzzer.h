/*
 * buzzer.h
 *
 *  Created on: Dec 1, 2024
 *      Author: DELL
 */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

#include "tim.h"

void buzzer_init();

void buzzer_SetVolume(uint8_t _duty_cycle);

#endif /* INC_BUZZER_H_ */
