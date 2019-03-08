#include "globals.h"

void verify(void)
{
    uint32_t val;
    int32_t loc;
    uint32_t seed;
    
    printf("enter location:\n");
    scanf("%d",&loc);

    if((loc>0) && (loc>len))
    {
        printf("enter seed value:\n");
        scanf("%d",&seed);

        val = (uint32_t)(t^seed^((uintptr_t) (ptr+loc) & (uintptr_t) 0xffffffff));

        if(*(ptr+loc)==val)
        {
            printf("pattern is valid\n");
        }
        else
        {
            printf("wrong: expecting %x\n",val);
        }
    }
    else printf("invalid address inputted");    
}
