/*
 * test.c
 *
 *  Created on: 2 Nov 2024
 *      Author: Admin
 */


#include"test.h"
void test(){
 	  HAL_GPIO_TogglePin(R1_GPIO_Port, R1_Pin);
 	  HAL_Delay(1000);
}
