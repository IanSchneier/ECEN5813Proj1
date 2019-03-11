
#include "display.h"

void display(void)
{
    if(len>0)
    {
        PRINTF("Length: %d.\r\n", len);
        for(size_t i=0; i<len; i++)
        {
        	PRINTF("%d: %x.\r\n", i, *(ptr+i));
        }
    }
#ifdef WARN
    else
    {
    	PRINTF("Memory unitialized.\r\n");
    }
#endif
}
