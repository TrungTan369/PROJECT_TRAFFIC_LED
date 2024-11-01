/*
 * button.c
 *
 *  Created on: Nov 2, 2024
 *      Author: HOME
 */
#include "button.h"
int key1_temp0 = NORMAL_STATE;
int key1_temp1 = NORMAL_STATE;
int key1_temp2 = NORMAL_STATE;
int key1_temp3 = NORMAL_STATE;

int buttonFlag1 = 0;
int timePress = 0;

void getKeyinput(){
	//-----PROCESS BUTTON 1------------
	key1_temp0 = key1_temp1;
	key1_temp1 = key1_temp2;
	key1_temp2 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);

	if((key1_temp0 == key1_temp1) && (key1_temp1 == key1_temp2)){
		if(key1_temp3 != key1_temp2){
			key1_temp3 = key1_temp2;
			if(key1_temp2 == PRESS_STATE){
				buttonFlag1 = 1;
				HAL_GPIO_TogglePin(Y1_GPIO_Port, Y1_Pin); // DEBUG
				timePress = 200;
			}
		}
		else{
			timePress--;
			if(timePress <= 0){
				key1_temp3 = NORMAL_STATE;
				timePress = 200;
			}
		}
	}
}

int isButtonPress1(){
	if(buttonFlag1 == 1){
		buttonFlag1 = 0;
		return 1;
	}
	return 0;
}

