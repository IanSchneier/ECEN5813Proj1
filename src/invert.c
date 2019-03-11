#include "invert.h"

void invert(void)
{
	uint32_t mi;
	uint32_t ma;
	uint32_t t0, tf;
	if(len>0)
	{
		PRINTF("enter minimum value of range of numbers to invert:\r\n");
			PRINTF("cmd> ");
			if((SCANF("%d",&mi)==1)&&(mi<len))
			{
				PRINTF("enter maximum value of range of numbers to invert:\r\n");
				PRINTF("cmd> ");
				if((SCANF("%d",&ma)==1) && (ma<len) && (mi<ma))
				{
					//get initial time
					t0=get_clk();
					// perform inverting operation
					for(size_t i=mi;i<=ma;i++) *(ptr+i) = ~*(ptr+i);
					// get time after operation
					tf=get_clk();
					//print how logn it took for operation to execute
					PRINTF("Inversion complete. Time elapsed: %d milli-seconds\r\n",
							(tf - t0));
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
