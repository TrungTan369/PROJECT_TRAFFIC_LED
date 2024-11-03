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

// --- AUTO MODE--------
#define auto_init 0
#define auto_red_green 1
#define auto_red_yellow 2
#define auto_green_red 3
#define auto_yellow_red 4

extern int time_red_green;
extern int time_red_yellow;

extern int auto_mode;
extern int status;

extern int counter_debug;
//--- MANUAL MODE ------
//#define manual_init 0
//#define manual_red_green 1
//#define manual_red_green 2
//
//extern int manual_mode;  // FLAG MANUAL



//----SETTING MODE-------
//
//
//#define setting_init 0
//#define setRed 1
//#define setYellow 2
//#define setGreen 3
//#define checkout 4;
//extern int setting_mode; //FLAG SETTING

#endif /* INC_GLOBAL_H_ */
