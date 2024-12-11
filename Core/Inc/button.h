/*
 * button.h
 *
 *  Created on: Nov 2, 2024
 *      Author: HOME
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"

#define NORMAL_STATE 1
#define PRESS_STATE 0

extern int buttonFlag[3];

void getKeyinput();
int isButtonPress(int);


#endif /* INC_BUTTON_H_ */
