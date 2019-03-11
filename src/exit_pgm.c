/*
 * exit_pgm.c
 *
 *  Created on: Mar 10, 2019
 *      Author: iansc
 */
#include "exit_pgm.h"

uint8_t stay;

void exit_pgm(void)
{
	PRINTF("Exiting...\r\n");
	stay=0;
}
