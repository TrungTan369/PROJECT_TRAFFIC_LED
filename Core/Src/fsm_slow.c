/*
 * fsm_slow.c
 *
 *  Created on: Nov 8, 2024
 *      Author: xjkpr
 */


void fsm_slow_run(){
	if(status == SLOW){
		if(timer_flag[0]==1){
			HAL_GPIO_TogglePin(Y0_GPIO_Port, Y0_Pin);
			HAL_GPIO_TogglePin(Y1_GPIO_Port, Y1_Pin);
			set_timer(0, 500);
		}
		if(isButtonPress(0)==1){
			lcd_clear_display();
			lcd_goto_XY(1, 0);
			lcd_send_string("MODE: AUTO      ");
			lcd_goto_XY(0, 0);
			lcd_send_string("PLEASE SLOW DOWN");
			status = auto_red_green;
			count0 = (time_red_green + time_red_yellow)/1000;
			count1 = time_red_green / 1000;
			setTimer(0, time_red_green);
		}
	}
	else
		return;
}
