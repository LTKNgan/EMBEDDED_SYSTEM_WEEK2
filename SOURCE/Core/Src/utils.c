/*
 * utils.c
 *
 *  Created on: Dec 1, 2024
 *      Author: Ngan La
 */


#include "utils.h"

uint8_t BCD2DEC(uint8_t data) {
	return (data >> 4) * 10 + (data & 0x0f);
}

uint8_t DEC2BCD(uint8_t data) {
	return (data / 10) << 4 | (data % 10);
}
