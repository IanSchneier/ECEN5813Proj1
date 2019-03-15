
#include "display.h"

void display(void)
{
    if(len>0)
    {
        PRINTF("Length: %d.\r\n", len);
        for(size_t i=0; i<len; i++)
        {
#ifdef linux
        	PRINTF("%ld: %x.\r\n", i, *(ptr+i));
#else
        	PRINTF("%d: %x.\r\n", i, *(ptr+i));
#endif
        }
    }
#ifdef WARN
    else
    {
    	PRINTF("Memory unitialized.\r\n");
    }
#endif
}
