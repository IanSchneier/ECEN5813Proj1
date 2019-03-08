#include "globals.h"

void pattern(void)
{
    uint32_t loc;
    uint32_t seed;

    printf("%ld\n",t);
    printf("enter location:\n");
    scanf("%d",&loc);
    printf("enter seed value:\n");
    scanf("%d",&seed);

    *(ptr+loc)=(uint32_t)(t^seed^((uintptr_t)(ptr+loc) & (uintptr_t) 0xffffffff));
}
