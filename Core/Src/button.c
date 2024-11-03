/*
 * button.c
 *
 *  Created on: Nov 2, 2024
 *      Author: HOME
 */
#include "button.h"


int buttonFlag[3] = {0,0,0};

void getKeyinput(){
	//-----PROCESS BUTTON 1------------

	// BEGIN: timer_flag[1] == 1
	if((timer_flag[3] == 1) && (HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin) == 0)){
		//HAL_GPIO_TogglePin(R0_GPIO_Port, R0_Pin);
		//counter_debug++;
		buttonFlag[0] = 1;
		setTimer(3, 200);  //Không đọc nút nhấn trong 200ms sau khi nhấn lần đầu tiên
	}
	// không đọc tiếp nút nhấn trong 200ms

	// ----PROCESS BUTTON 2-----------

	if((timer_flag[3] == 1) && (HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin) == 0)){
		//HAL_GPIO_TogglePin(Y0_GPIO_Port, Y0_Pin);
		//counter_debug++;
		buttonFlag[1] = 1;
		setTimer(3, 200);
	}

	// ----- PROCESS BUTTON 3 -----------
	if((timer_flag[3] == 1) && (HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin) == 0)){
		//HAL_GPIO_TogglePin(G0_GPIO_Port, G0_Pin);
		//counter_debug++;
		setTimer(3, 200);
		buttonFlag[2] = 1;
	}

}
int isButtonPress(int i){
	if(buttonFlag[i] == 1){
		buttonFlag[i] = 0;
		return 1;
	}
	return 0;
}
