/*
 * free_mem.h
 *
 *  Created on: Mar 9, 2019
 *      Author: iansc
 */

#ifndef FREE_MEM_H_
#define FREE_MEM_H_

#ifdef linux
#include <stdio.h>
#else
//stuff for when on the FRDM board
#include "fsl_debug_console.h"
#endif

#include <stdlib.h>
#include <stdint.h>

#include <main.h>

void free_mem(void);

#endif /* FREE_MEM_H_ */
