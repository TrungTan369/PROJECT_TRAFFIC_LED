/*
 * button.c
 *
 *  Created on: Nov 2, 2024
 *      Author: HOME
 */
#include "button.h"

//int key1_temp0 = NORMAL_STATE;
//int key1_temp1 = NORMAL_STATE;
//int key1_temp2 = NORMAL_STATE;
//int get_key1 = NORMAL_STATE;
//
//int key2_temp0 = NORMAL_STATE;
//int key2_temp1 = NORMAL_STATE;
//int key2_temp2 = NORMAL_STATE;
//int get_key2 = NORMAL_STATE;
//
//int key3_temp0 = NORMAL_STATE;
//int key3_temp1 = NORMAL_STATE;
//int key3_temp2 = NORMAL_STATE;
//int get_key3 = NORMAL_STATE;

int buttonFlag[3] = {0,0,0};

void getKeyinput(){
	//-----PROCESS BUTTON 1------------
//	key1_temp0 = key1_temp1;
//	key1_temp1 = key1_temp2;
//	key1_temp2 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
//
//	key2_temp0 = key2_temp1;
//	key2_temp1 = key2_temp2;
//	key2_temp2 = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
//
//	key3_temp0 = key3_temp1;
//	key3_temp1 = key3_temp2;
//	key3_temp2 = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);


	// BEGIN: timer_flag[1] == 1
	if((timer_flag[3] == 1) && (HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin) == 0)){
		//HAL_GPIO_TogglePin(R0_GPIO_Port, R0_Pin);
		//counter_debug++;
		buttonFlag[0] = 1;
		setTimer(3, 200);  //Không đọc nút nhấn trong 200ms sau khi nhấn lần đầu tiên
	}
	// không đọc tiếp nút nhấn trong 200ms

//	if((key1_temp0 == key1_temp1) && (key1_temp1 == key1_temp2)){
//		if(get_key1 != key1_temp2){
//			get_key1 = key1_temp2;
//			if(key1_temp2 == PRESS_STATE){
//				buttonFlag1 = 1;
//				HAL_GPIO_TogglePin(R0_GPIO_Port, R0_Pin);
//			}
//		}
//	}
	// ----PROCESS BUTTON 2-----------

	if((timer_flag[3] == 1) && (HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin) == 0)){
		//HAL_GPIO_TogglePin(Y0_GPIO_Port, Y0_Pin);
		//counter_debug++;
		buttonFlag[1] = 1;
		setTimer(3, 200);
	}
//	if((key2_temp0 == key2_temp1) && (key2_temp1 == key2_temp2)){
//		if(get_key2 != key2_temp2){
//			get_key2 = key2_temp2;
//			if(key2_temp2 == PRESS_STATE){
//				buttonFlag2 = 1;
//				HAL_GPIO_TogglePin(R0_GPIO_Port, R0_Pin);
//			}
//		}
//	}
	// ----- PROCESS BUTTON 3 -----------
	if((timer_flag[3] == 1) && (HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin) == 0)){
		//HAL_GPIO_TogglePin(G0_GPIO_Port, G0_Pin);
		//counter_debug++;
		setTimer(3, 200);
		buttonFlag[2] = 1;
	}
//	if((key3_temp0 == key3_temp1) && (key3_temp1 == key3_temp2)){
//		if(get_key3 != key3_temp2){
//			get_key3 = key3_temp2;
//			if(key3_temp2 == PRESS_STATE){
//				buttonFlag3 = 1;
//				HAL_GPIO_TogglePin(R0_GPIO_Port, R0_Pin);
//			}
//		}
//	}
}
int isButtonPress(int i){
	if(buttonFlag[i] == 1){
		buttonFlag[i] = 0;
		return 1;
	}
	return 0;
}
