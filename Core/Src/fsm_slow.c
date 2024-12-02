/*
 * fsm_slow.c
 *
 *  Created on: Nov 8, 2024
 *      Author: xjkpr
 */
#include "fsm_slow.h"

void fsm_slow_run(){
	HAL_GPIO_TogglePin(Y0_GPIO_Port, Y0_Pin);
	HAL_GPIO_TogglePin(Y1_GPIO_Port, Y1_Pin);
	if(isButtonPress(0) == 1){
		SCH_Add_Task(fsm_auto_run, 10, 10);
		SCH_Add_Task(Scan7SEG, 10, 20);
		SCH_Delete_Task(fsm_slow_run);
		status = auto_init;
	}
}
