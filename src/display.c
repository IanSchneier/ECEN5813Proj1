#include "globals.h"

void display(void)
{
    if(len>0)
    {
        printf("Length: %d.\n", len);
        for(size_t i=0; i<len; i++)
        {
            printf("%ld: %x.\n", i, *(ptr+i));
        }
    }
    else printf("Memory unitialized.\n");
}
