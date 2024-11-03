/*
 * led_display.h
 *
 *  Created on: 2 Nov 2024
 *      Author: Admin
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"

extern int led_buffer[4];
extern int led_index;
void Scan7SEG();
void display7SEG(int);
void updateClockBuffer(int, int);
void Diable_Led();
void single_LED_off();
#endif /* INC_LED_DISPLAY_H_ */
