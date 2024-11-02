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
			count0 = time_red_green/1000; // 5s
			count1 = (time_red_green + time_red_yellow)/1000;  // 7s

			updateClockBuffer(count0, count1);
			setTimer(0, time_red_green);
			setTimer(2, 1000); // count 1s
			setTimer(3, 10);  // scan led
			return;
		case auto_red_green:
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET); // red0 on
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET); // green1 on

			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, SET); // yellow 0 off
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, SET); // red 1 on
			if(flag[0] == 1){
				status = auto_red_yellow;
				setTimer(0, time_red_yellow);
				// count0 = 0s
				// count1 = 2s
				count0 = time_red_yellow;
				updateClockBuffer(count0, count1);
			}
			break;
		case auto_red_yellow:
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET); // yellow1 on
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET); // green1 off
			if(flag[0] == 1){
				status = auto_green_red;
				count0 = (time_red_green + time_red_yellow)/1000; // 7s
				count1 = (time_red_green)/1000;  // 5s
				updateClockBuffer(count0, count1);
				setTimer(0, time_red_green);
			}
			break;
		case auto_green_red:
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET); // green 0 on
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET); // red 1 on

			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, SET); // red 0 off
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, SET); // yellow 1 off
			if(flag[0] == 1){
				status = auto_yellow_red;
				count1 = (time_red_green + time_red_yellow)/1000;
				//count 0 = 2s
				//count1 = 0s
				updateClockBuffer(count0, count1);
				setTimer(0, time_red_green);
			}
		case auto_yellow_red:
			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET); // yellow 0 on

			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, SET); // green 0 off
			if(flag[0] == 1){
				status = auto_red_green;
				count0 = (time_red_green + time_red_yellow)/1000;
				count1 = time_red_yellow / 1000;
				//count 0 = 7s
				//count1 = 5s
				updateClockBuffer(count0, count1);
				setTimer(0, time_red_green);
			}
			break;
		default:
			break;
	}

	if(flag[2] == 1){
		setTimer(2, 1000);
		count0 --; count1 --;
		updateClockBuffer(count0, count1);
	}
	if(flag[3] == 1){
		setTimer(3, 10);
		Scan7SEG();
	}
}
