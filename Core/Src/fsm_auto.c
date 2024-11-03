/*
 * fsm_auto.c
 *
 *  Created on: Nov 2, 2024
 *      Author: HOME
 */

#include "fsm_auto.h"

int count0 = 0;
int count1= 0;

void fsm_auto_run(){
	// ---------- CHECK MANUAL ---------------
	//if(manual_mode == 1) return;
	// ------ CHECK SETTING -------------
	//if(setting_mode == 1) return;
	// ---------- AUTO RUN ---------------------

	switch (status) {   // LINE 1
		case auto_init:
			// ------- ALL LED OFF -------------
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, SET);
			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, SET);
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, SET);
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, SET);
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, SET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);

			status = auto_red_green;
			count0 = (time_red_green + time_red_yellow)/1000;  // 15s
			count1 = time_red_green/1000; // 10s
			setTimer(0, time_red_green);
			setTimer(1, 1000); // count 1s
			setTimer(2, 10);  // scan led
			break;
		case auto_red_green:
			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, SET); // yellow 0 off
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, SET); // red 1 on
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET); // red0 on
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET); // green1 on
			if(timer_flag[0] == 1){
				status = auto_red_yellow;
				setTimer(0, time_red_yellow);
				// count0 = 5s
				// count1 = 0s
				count1 = time_red_yellow/1000;
				// count0 = 5s
				// count1 = 5s
			}
			break;
		case auto_red_yellow:
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET); // green1 off
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET); // yellow1 on

			if(timer_flag[0] == 1){
				status = auto_green_red;
				// count0 = 0s
				// count1 = 0s
				count0 = (time_red_green)/1000;
				count1 = (time_red_green + time_red_yellow)/1000;
				// count0 = 10s
				// count1 = 15s
				//updateClockBuffer(count0, count1);
				setTimer(0, time_red_green);
			}
			break;
		case auto_green_red:
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, SET); // red 0 off
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, SET); // yellow 1 off
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET); // green 0 on
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET); // red 1 on

			if(timer_flag[0] == 1){
				status = auto_yellow_red;
				count0 = time_red_yellow/1000;
				//count 0 = 0s
				//count1 =  5s
				setTimer(0, time_red_yellow);
				//count 0 = 5s
				//count1 =  5s
			}
			break;
		case auto_yellow_red:
			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET); // yellow 0 on
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, SET); // green 0 off
			if(timer_flag[0] == 1){
				status = auto_red_green;
				//count 0 = 0s
				//count1 =  0s
				count0 = (time_red_green + time_red_yellow)/1000;
				count1 = time_red_green / 1000;
				//count 0 = 15s
				//count1 =  10s
				//updateClockBuffer(count0, count1);
				setTimer(0, time_red_green);
			}
			break;
		default:
			break;
	}
	updateClockBuffer(count0, count1);
	if(timer_flag[2] == 1){
		setTimer(2, 10);
		Scan7SEG();
	}
	if(timer_flag[1] == 1){
		setTimer(1, 1000);
		count0 --; count1 --;
	}
}
