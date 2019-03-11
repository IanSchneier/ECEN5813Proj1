/*
 * free_mem.c
 *
 *  Created on: Mar 9, 2019
 *      Author: iansc
 */

#include "free_mem.h"

void free_mem(void)
{
	free(ptr);
	ptr=NULL;
	len=0;
	PRINTF("Memory freed\r\n");
}
