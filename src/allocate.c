#include "allocate.h"

// Formal Declaration of these pointers located in this file as it is where these values are set
uint32_t *ptr;
uint32_t len;

void allocate( void )
{
	t=clk;
	PRINTF("%f\r\n",t);
	//signed length varible for size checking, caps max value at INT32_MAX
	int32_t words;
	PRINTF("Type the number of words you wish to allocate then press enter/return:\r\n");
	PRINTF("cmd> ");
	SCANF("%d", &words);
	if( (words>0) && (words<MAX_ALLOC))
	{
		len=words;
		if(ptr!=NULL)
		{
			ptr = (uint32_t*) realloc(ptr, len * sizeof(uint32_t));
		}
		else
		{
			ptr = (uint32_t*) calloc( len, sizeof(uint32_t));
		}

		len=words;
		PRINTF("Allocated %d words at address %p\r\n",len, ptr);

	}
#ifdef WARN
	else
	{
		PRINTF("Invalid memory allocation size.\r\n");
	}
#endif
}
