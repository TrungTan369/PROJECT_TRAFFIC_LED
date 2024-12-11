/*
 * led_display.c
 *
 *  Created on: 2 Nov 2024
 *      Author: Admin
 */
#include "led_display.h"

int led_buffer[4] = {0,0,0,0};
int led_index = 0;
void Diable_7SEG(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
}
void Scan7SEG(){
	Diable_7SEG();
	switch(led_index){
		case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			display7SEG(led_buffer[0]);
			break;
		case 1:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			display7SEG(led_buffer[1]);
			break;
		case 2:
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			display7SEG(led_buffer[2]);
			break;
		case 3:
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[3]);
			break;
		default:
			break;
	}
	if((++led_index) >= 4) led_index = 0;
}
void display7SEG(int num){
	switch(num){
		case 0:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, RESET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, SET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, RESET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, SET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, SET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, SET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, RESET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, SET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, SET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, SET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, RESET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, SET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, SET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, SET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, SET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, SET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, RESET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, RESET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, SET);
			break;
		case 9:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, SET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, SET);
			break;
		default:
			break;
	}
}
void updateClockBuffer(int num1, int num2){
	led_buffer[0] = num1 / 10;
	led_buffer[1] = num1 % 10;
	led_buffer[2] = num2 / 10;
	led_buffer[3] = num2 % 10;
}
void single_LED_off(){
	HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, SET);
	HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, SET);
	HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, SET);
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, SET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, SET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
}
