#include "verify.h"

void verify(void)
{
	uint32_t mi;
	uint32_t ma;
	uint32_t t0, tf;
	uint32_t val;
	uint32_t seed;

	PRINTF("enter location:\r\n");

	PRINTF("enter minimum value of range of numbers to invert:\r\n");
	PRINTF("cmd> ");
	if((SCANF("%d",&mi)==1)&&(mi<len))
	{
		PRINTF("enter maximum value of range of numbers to invert:\r\n");
		PRINTF("cmd> ");
		if((SCANF("%d",&ma)==1) && (ma<len) && (mi<ma))
		{
			PRINTF("enter seed value:\r\n");
			if((SCANF("%d",&seed)==1)&&(seed<=UINT32_MAX))
			{
				t0=get_clk();
				for(size_t i=mi; i<ma;i++)
				{
					val = (uint32_t)(t^seed^((uintptr_t)(ptr+i) & (uintptr_t)0xffffffff));
					if(*(ptr+i)!=val)
					{
						PRINTF("wrong value at %p, expecting %x.\r\n",(ptr+i),val);
					}
				}
				tf=get_clk();
				//print how long it took for operation to execute
				PRINTF("Pattern validation complete. Time elapsed: %d "
						"milli-seconds\r\n",(tf - t0));
			}
#ifdef WARN
			else
			{
				PRINTF("invalid seed value.\r\n");
			}
#endif
		}
	}
#ifdef WARN
	else
	{
		PRINTF("invalid memory location.\r\n");
	}
#endif
}
