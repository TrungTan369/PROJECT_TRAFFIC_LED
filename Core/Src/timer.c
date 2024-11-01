/*
 * timer.c
 *
 *  Created on: Nov 2, 2024
 *      Author: HOME
 */
#include "timer.h"

int counter[4] = {0, 0, 0, 0};  // set timer
int flag[4] = {0, 0, 0, 0};

void setTimer(int timer, int duration){
	counter[timer] = duration / 10;
	flag[timer] = 0;
}

void timer_run(){
	if(counter[0] > 0){   // TIMER LINE 1
		counter[0]--;
		if(counter[0] == 0)
			flag[0] = 1;
	}
	if(counter[1] > 0){ // TIMER LINE 2
		counter[1]--;
		if(counter[1] == 0)
			flag[1] = 1;
	}
	if(counter[2] > 0){   //1 S
		counter[2]--;
		if(counter[2] == 0)
			flag[2] = 1;
	}
	if(counter[3] > 0){   //250 MS
		counter[3]--;
		if(counter[3] == 0)
			flag[3] = 1;
	}
}



