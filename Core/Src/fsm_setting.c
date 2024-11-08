/*
 * fsm_setting.c
 *
 *  Created on: Nov 3, 2024
 *      Author: HOME
 */

#include "fsm_setting.h"

int increment[5] = {1000,2000,5000,10000,20000};
int i = 0;

void fsm_setting(){
	switch (status) {
		case set_green:
			if(timer_flag[0] == 1){
				setTimer(0, 100);
				HAL_GPIO_TogglePin(G0_GPIO_Port, G0_Pin);
				HAL_GPIO_TogglePin(G1_GPIO_Port, G1_Pin);
			}
			if(isButtonPress(0) == 1){  // TIME INCREASE
				time_red_green += increment[i];
				if(time_red_green > 98000){
					time_red_green = 0;
				}
			}
			if(isButtonPress(2) == 1){
				status = set_yellow;
				HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, SET);
				HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
				i = 0;
			}
			updateClockBuffer(time_red_green/1000, increment[i]/1000);
			break;
		case set_yellow:
			if(timer_flag[0] == 1){
				setTimer(0, 100);
				HAL_GPIO_TogglePin(Y0_GPIO_Port, Y0_Pin);
				HAL_GPIO_TogglePin(Y1_GPIO_Port, Y1_Pin);
			}
			if(isButtonPress(0) == 1){
				time_red_yellow += increment[i];
			}
			if(isButtonPress(2) == 1){
				if( ( (time_red_yellow + time_red_green) >= 100000)  && (time_red_green == 0) ){
					HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, SET);
					HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, SET);
					status = set_green;
					i = 0;
				}
				else {
					status = auto_init;
					lcd_clear_display();
					return;
				}
			}
			updateClockBuffer(time_red_yellow/1000, increment[i]/1000);
			break;
		default:
			return;
	}

	if(isButtonPress(1) == 1){
		 ++i;
		 if(i >=5) i = 0;
	}
	if(timer_flag[2] == 1){
		setTimer(2, 20);
		Scan7SEG();
	}

}
