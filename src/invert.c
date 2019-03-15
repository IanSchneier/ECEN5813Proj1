#include "invert.h"

void invert(void)
{
	uint32_t mi;
	uint32_t ma;
	double t0, tf;
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
					//get initial time
					t0=get_clk();
					// perform inverting operation
					for(size_t i=mi;i<=ma;i++) *(ptr+i) = ~*(ptr+i);
					// get time after operation
					tf=get_clk();
					//print how logn it took for operation to execute
					PRINTF("Inversion complete. Time elapsed: %f milli-seconds\r\n",
							(double)((tf - t0)/TICKS_PER_SEC));
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
