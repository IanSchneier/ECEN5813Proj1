#include "globals.h"


void allocate( void )
{
    //signed length varible for size checking, caps max value at INT32_MAX
    int32_t words;
    printf("Type the number of words you wish to allocate then press enter/return:\n");
    if((words<0) || (words>INT32_MAX) || (scanf("%d", &words)==0))
    {
        printf("Invalid memory allocation size, try again.\n");
        scanf("%d", &words);
    }
    else
    {
        //precautionary freeing of memeory
        if(ptr!=NULL)
        {
            free(ptr);
        }
        ptr = (uint32_t*) malloc( len * sizeof(uint32_t));
        len=words;
        printf("Allocated %d words at address %p\n",len, ptr);
        // when allocating memory sometimes random values appear in when displaying
        // this loop ensures no junk values are present
        for(size_t i=0;i<len;i++)
        {
            *(ptr+i)=0;
        } 
    }
}
