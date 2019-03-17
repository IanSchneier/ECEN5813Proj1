/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#ifndef linux
// FRDM board specific headers that are only required for code in this file
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"
#endif

#include "main.h"

#include "allocate.h"
#include "display.h"
#include "exit_pgm.h"
#include "free_mem.h"
#include "help.h"
#include "invert.h"
#include "pattern.h"
#include "verify.h"
#include "write.h"

//Ugly macro to return 0 if the position index is not one of these numbers
#define POS_VALID(x) (x==0)? (1) : \
		( (x==3) ? (1) : \
		( (x==4) ? (1) : \
		( (x==5) ? (1) : \
		( (x==7) ? (1) : \
		( (x==8) ? (1) : \
		((x==15) ? (1) : \
		((x==21) ? (1) : \
		((x==22) ? (1) : (0)))))))))

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#ifdef linux
uint32_t t;

#else
uint32_t t;
uint32_t clk;
#endif

typedef void (*fn)();

typedef struct {
	char *list;
	fn func;
} command;

static const command cmd[] = {
		[0]  = {"allocate", &allocate},
		[3]  = {"display", &display},
		[4]  = {"exit", &exit_pgm},
		[5]  = {"free", &free_mem},
		[7]  = {"help",&help},
		[8]  = {"invert",&invert},
		[15] = {"pattern",&pattern},
		[21] = {"verify",&verify},
		[22] = {"write",&write}
};

/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/
#ifndef linux
void Init_Systick()
{
	//Configure to trigger interrupt every millisecond
#ifdef WARN
	if(SysTick_Config(CORE_CLOCK)>0)
	{
		PRINTF("Warning, timer initialization failed.\r\n");
	}
#endif
}

void SysTick_Handler()
{
	//increment count every millisecond
	clk = (clk + 1) & UINT32_MAX;
}
#endif

double get_clk(void)
{
#ifdef linux
	return (1000*clock());
#else
	return (double)clk;
#endif
}

void sanitize_input(char *str, size_t len)
{
	size_t i=0;
	while(i<len)
	{
		// force the char to lowercase value
		*(str+i) = ((*(str+i)>='A') && (*(str+i) <= 'Z')) ? (*(str+i)+32) : *(str+i);
		i++;
	}
}

/*!
 * @brief Main function
 */

int main (void)
{
	uint8_t pos;
	// stores user inputted strings
	char str[36];


#ifndef linux
	//FRDM board specific initialization functions
	BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();
	//initialize clock
	Init_Systick();
#endif

	//set the stay variable to one to keep program running
	stay=1;

	PRINTF("Project 1:\r\n");
	PRINTF("-----------------------------------------------------------------------\r\n");
	PRINTF("For list of commands type help\r\n");

	while (stay)
	{

		PRINTF("cmd> ");
		//get command
		SCANF("%s",str);
		//force all letters of command to lowercase
		sanitize_input(str, strlen(str));
		// get array element position by using first letter of input command
		pos = (str[0]-'a');
		// confirm that there's a array element with same starting letter as
		// one of the function names and that the command matches function name
		if((POS_VALID(pos)) && \
				(strncmp(str,cmd[pos].list,strlen(cmd[pos].list)) == 0))
		{
			cmd[pos].func();
		}
		//suppress warning if WARN is set to 0
#ifdef WARN
		else
		{
			PRINTF("Invalid Commdand: Type help for how to run program\r\n");
		}
#endif
	}

	return 0;
}
