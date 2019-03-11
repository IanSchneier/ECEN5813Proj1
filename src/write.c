#include "write.h"

void write( void )
{
    uint32_t val;
    uint32_t offset;
    if(len>0)
    {
    	// take in offset value which is the address of the allocated register
    	// some distance away from ptr[0]
    	PRINTF("Type the offset value and press enter/return:\r\n");
    	PRINTF("cmd> ");
    	// validate input
        if((SCANF("%d", &offset)>0) && (offset<len))
        {
        	PRINTF("Type the value you wish to write in hex then press enter/return:\r\n");
        	PRINTF("cmd> ");
        			// Check if value is valid
        	        if((SCANF("%x", &val)==1)&& (val<=UINT32_MAX))
        	        {
        	            *(ptr+offset) = val;
        	            //report new value of memory block and its location
        	            PRINTF("%x written to %p\r\n", val, (ptr + offset));
        	        }
//Suprress error warnings if mandated in main.h file
#ifdef WARN
        	        else PRINTF("invalid numerical value detected.\r\n");
#endif
        }
#ifdef WARN
        else PRINTF("Invalid offset value\r\n");
#endif
    }
#ifdef WARN
    else PRINTF("Memory unitialized.\r\n");
#endif
}


