/*
 * timer.h
 *
 *  Created on: Nov 2, 2024
 *      Author: HOME
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "global.h"

extern int counter[4];   // blink dot 1hz
extern int timer_flag[4];

void setTimer(int, int);
void timer_run();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *);

#endif /* INC_TIMER_H_ */

