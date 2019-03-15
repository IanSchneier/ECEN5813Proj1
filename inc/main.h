/*
 * main.h
 *
 *  Created on: Mar 10, 2019
 *      Author: iansc
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>

// Linux platform definitions
#ifdef linux

#include <stdio.h>
#include <time.h>

#define PRINTF (printf)
#define SCANF  (scanf)

//limit allocation to max value that can be inputed in allocate function
#define MAX_ALLOC (INT32_MAX)
// Clock Cycles per second
#define TICKS_PER_SEC (CLOCKS_PER_SEC)

#else
//FRDM board specific macros, variables, and headers
#define CORE_CLOCK (SystemCoreClock/1000)
// set number of clock cycles per second to equal internal clock of FRDM board
#define TICKS_PER_SEC (CORE_CLOCK)

// Max memory we can allocate on board
#define MAX_ALLOC (750)
// header file that includes PRINTF and SCANF statements
#include "fsl_debug_console.h"

#endif



// Suppress in-function warnings when false (0)
#if 1
#define WARN
#endif
// Value of time when memory is allocated. Used for psuedo random function.
extern uint32_t t;
// Global varaible pointer passed around memory manipulation functions
extern uint32_t *ptr;
// Number of elements in global variable pointer
extern uint32_t len;

double get_clk(void);

#endif /* MAIN_H_ */
