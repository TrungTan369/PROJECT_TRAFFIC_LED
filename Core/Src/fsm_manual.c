/*
 * fsm_manual.c
 *
 *  Created on: 3 Nov 2024
 *      Author: Admin
 */

#include "fsm_manual.h"

void fsm_manual(){
	switch (status) {
		case manual_red_green:
			if(isButtonPress(1) == 1){
				status = manual_green_red;
				HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, SET);
				HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, SET);
				HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET);
				HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
			}
			if(isButtonPress(0) == 1){
				SCH_Add_Task(fsm_auto_run, 10, 10);
				SCH_Add_Task(Scan7SEG, 10, 20);
				SCH_Delete_Task(fsm_manual);
				status = auto_red_green;
				count0 = (time_red_green + time_red_yellow)/1000;
				count1 = time_red_green / 1000;
				updateClockBuffer(count0, count1);
				SCH_Add_Task(fsm_switch_state_auto_red_yellow, time_red_green, 0);

				lcd_clear_display();
				lcd_goto_XY(1, 0);
				lcd_send_string("MODE: AUTO");
				lcd_goto_XY(0, 0);
				lcd_send_string("PLEASE SLOW DOWN");
				return;
			}
			break;
		case manual_green_red:
			if(isButtonPress(1) == 1){
				status = manual_red_green;
				HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, SET);
				HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
				HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
				HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);
			}
			if(isButtonPress(0) == 1){
				SCH_Add_Task(fsm_auto_run, 10, 10);
				SCH_Add_Task(Scan7SEG, 10, 20);
				SCH_Delete_Task(fsm_manual);
				status = auto_green_red;
				count0 = time_red_green/1000;
				count1 =   (time_red_green + time_red_yellow)/1000;
				updateClockBuffer(count0, count1);
				SCH_Add_Task(fsm_switch_state_auto_yellow_red, time_red_green, 0);

				lcd_clear_display();
				lcd_goto_XY(1, 0);
				lcd_send_string("MODE: AUTO");
				lcd_goto_XY(0, 0);
				lcd_send_string("PLEASE SLOW DOWN");

				return;
			}
			break;
		default:
			return;
	}
	// -------SWITCHING SETTING MODE ------------
	if(isButtonPress(2) == 1){
		time_red_yellow = 0;
		time_red_green = 0;
		updateClockBuffer(0, 1);
		status = set_green;
		SCH_Delete_Task(fsm_manual);
		SCH_Delete_Task(count_1_second);
		SCH_Add_Task(fsm_setting, 100, 10);
		SCH_Add_Task(Scan7SEG, 10, 20);
		single_LED_off();
		HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, 1);
		HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, 1);
	}
}
