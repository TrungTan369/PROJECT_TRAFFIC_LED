/*
 * button.h
 *
 *  Created on: Nov 2, 2024
 *      Author: HOME
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE 1
#define PRESS_STATE 0

extern int buttonFlag1;

void getKeyinput();
int isButtonPress1();

#endif /* INC_BUTTON_H_ */
