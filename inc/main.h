/*
 * main.h
 *
 *  Created on: Mar 10, 2019
 *      Author: iansc
 */

#ifndef MAIN_H_
#define MAIN_H_

#ifdef LINUX
//limit allocation to max value that can be inputed in allocate function
#define MAX_ALLOC (INT32_MAX)

#define TICKS_PER_SEC (CLOCKS_PER_SEC)

#include <stdio.h>
#include <time.h>

extern clock_t t;

#else
//FRDM board specific macros, variables, and headers
#define CORE_CLOCK (SystemCoreClock/1000)
// set number of clock cycles per second to equal internal clock of FRDM board
#define TICKS_PER_SEC (CORE_CLOCK)

// Max memory we can allocate on board
#define MAX_ALLOC (100)
// header file that includes PRINTF and SCANF statements
#include "fsl_debug_console.h"
// clock value counter used for interrupt
extern uint32_t clk;
#endif

#include <stdint.h>

// Suppress in-function warnings when false (0)
#define WARN (0)

// Value of time when memory is allocated. Used for psuedo random function.
extern uint32_t t;
// Global varaible pointer passed around memory manipulation functions
extern uint32_t *ptr;
// Number of elements in global variable pointer
extern uint32_t len;

uint32_t get_clk(void);

#endif /* MAIN_H_ */
