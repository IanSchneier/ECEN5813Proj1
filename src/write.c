#include "globals.h"

void write( char* opt )
{
    uint32_t val;
    uint32_t offset;
    if(len>0)
    {
        if((opt!=NULL) && (opt[0]=='-') && (opt[1]=='o'))
        {
            printf("Type the offset value and press enter/return:\n");
            scanf("%d", &offset);
        }
        else offset = 0;
        //move val back here when it becomes fn
        printf("Type the value you wish to write in hex then press enter/return:\n");
        if(scanf("%x", &val)>0)
        {
            *(ptr+offset) = val & 0xffffffff;
            printf("%x written to %p\n", val, (ptr + offset));
            val=0;
            offset=0;
        }
        else printf("invalid numerical value detected.\n");
    }
    else printf("Memory unitialized.\n");
}
