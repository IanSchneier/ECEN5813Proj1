#include "pattern.h"

void pattern(void)
{
	//first value of range
	uint32_t mi;
	//last value of range
	uint32_t ma;
	//initial and final times of operation
	double t0, tf;
	//seed value for psuedo random funciton
	uint32_t seed;

	if(len>0)
	{
		PRINTF("enter minimum value of range of numbers to invert:\r\n");
		PRINTF("cmd> ");
		if((SCANF("%d",&mi)==1)&&(mi<len))
		{
			PRINTF("enter maximum value of range of numbers to invert:\r\n");
			PRINTF("cmd> ");
			if((SCANF("%d",&ma)==1) && (ma<len) && (mi<=ma))
			{
				// perform inverting operation
				PRINTF("enter seed value:\r\n");
				//check if seed value is valid by checking if scanf returns
				//a valid input and the value is 32-bits or less
				if((SCANF("%d",&seed)==1)&&(seed<=UINT32_MAX))
				{
					//get initial time
					t0=get_clk();
					for(size_t i=mi; i<=ma;i++)
					{
						*(ptr+i)=(uint32_t)(t^seed^((uintptr_t)(ptr+i)
								& (uintptr_t) 0xffffffff));
					}
					// get time after operation
					tf=get_clk();
					//print how lon it took for operation to execute
					PRINTF("Pattern generation complete. Time elapsed: "
							"%f milli-seconds\r\n",
							(double)((tf - t0)/TICKS_PER_SEC));
				}
#ifdef WARN
				else
				{
					PRINTF("invalid seed value.\r\n");
				}
#endif
			}
#ifdef WARN
			else
			{
				PRINTF("invalid memory range.\r\n");
			}
#endif
		}
#ifdef WARN
		else
		{
			PRINTF("invalid memory location.\r\n");
		}
#endif
	}
#ifdef WARN
	else
	{
		PRINTF("Memory unitialized.\r\n");
	}
#endif

}
