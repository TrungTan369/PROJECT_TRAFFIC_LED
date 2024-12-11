/*
 * fsm_setting.c
 *
 *  Created on: Nov 3, 2024
 *      Author: HOME
 */

#include "fsm_setting.h"

int increment[5] = {1000,2000,5000,10000,20000};
int i = 0;
int temp =0 ;
void fsm_setting(){
	switch (status) {
		case set_green:
			if(isButtonPress(0) == 1){  // TIME INCREASE
				time_red_green += increment[i];
				temp = time_red_green;
				if(time_red_green > 98000){
					time_red_green = 0;
				}
				updateClockBuffer(time_red_green/1000, increment[i]/1000);
			}
			if(isButtonPress(2) == 1){
				i = 0;
				updateClockBuffer(time_red_yellow/1000, increment[i]/1000);
				temp = time_red_yellow;
				status = set_yellow;
				HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, SET);
				HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
				HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET);
				HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
				i = 0;
			}
			break;
		case set_yellow:
			if(isButtonPress(0) == 1){
				time_red_yellow += increment[i];
				temp = time_red_yellow;
				updateClockBuffer(time_red_yellow/1000, increment[i]/1000);
			}
			if(isButtonPress(2) == 1){
				if( ( (time_red_yellow + time_red_green) >= 100000)  && (time_red_green == 0) ){
					HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, SET);
					HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, SET);
					HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);
					HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
					status = set_green;
					i = 0;
				}
				else {
					i = 0;
					status = auto_init;
					SCH_Delete_Task(fsm_setting);
					SCH_Add_Task(fsm_auto_run, 10, 10);
					SCH_Add_Task(count_1_second, 1010, 1000);
					return;
				}
			}
			break;
		default:
			return;
	}
	if(isButtonPress(1) == 1){
		 ++i;
		 if(i >= 5) i = 0;
		 updateClockBuffer(temp/1000, increment[i]/1000);
	}
}
