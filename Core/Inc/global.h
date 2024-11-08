/*
 * global.h
 *
 *  Created on: Nov 2, 2024
 *      Author: HOME
 */
#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "timer.h"
#include "button.h"
#include "led_display.h"
#include "i2c-lcd.h"
// --- AUTO MODE--------
#define auto_init 0
#define auto_red_green 1
#define auto_red_yellow 2
#define auto_green_red 3
#define auto_yellow_red 4

//-----MANUAL MODE -------
#define manual_red_green 5
#define manual_green_red 6
//----SETTING MODE -------
#define set_yellow 7
#define set_green 8
//---- SLOW MODE --------
#define SLOW	25
//---- TIME LED --------
extern int time_red_green;
extern int time_red_yellow;
extern int count0, count1;
extern int status;

extern int counter_debug;


#endif /* INC_GLOBAL_H_ */
