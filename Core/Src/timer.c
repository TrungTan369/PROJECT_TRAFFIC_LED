/*
 * timer.c
 *
 *  Created on: Nov 2, 2024
 *      Author: HOME
 */
#include "timer.h"

int counter[4] = {0, 0, 0, 0};
int timer_flag[4] = {0, 0, 0, 1};// FLAG[3] = 1 TO CHECK BUTTON PRESS( GO TO FUNCTION getKeyinput())

void setTimer(int timer, int duration){
	counter[timer] = duration / 10;
	timer_flag[timer] = 0;
}
void timer_run(){
	for(int i = 0; i < 4; i++){ // 4 timer
		if(counter[i] > 0){
			counter[i]--;
			if(counter[i] <= 0)
				timer_flag[i] = 1;
		}
	}
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim){
	getKeyinput();
	timer_run();
}



