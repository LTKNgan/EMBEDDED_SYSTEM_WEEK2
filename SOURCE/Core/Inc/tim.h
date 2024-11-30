/*
 * tim.h
 *
 *  Created on: Nov 20, 2024
 *      Author: Ngan la
 */

#ifndef INC_TIM_H_
#define INC_TIM_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"


extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim13;

//void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);


#ifdef __cplusplus
}
#endif

#endif /* INC_TIM_H_ */
