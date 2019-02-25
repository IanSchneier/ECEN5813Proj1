#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "invert.h"


void sanitize_input(char *str, size_t len)
{
    size_t i=0;
    while(i<len)
    {
        // force the char to lowercase value
        *(str+i) = ( (*(str+i)>='A') && (*(str+i) <= 'Z') ) ? (*(str+i)+32) : *(str+i);
        i++;
    }
}

void assign_null(uint32_t **x)
{
    *x = NULL;
}

static const char *cmd_list[] ={
    [0]  = "allocate",
    [3]  = "display",
    [4]  = "exit",
    [5]  = "free",
    [7]  = "help",
    [8]  = "invert",
    [15] = "pattern",
    [21] = "verify",
    [22] = "write"
    
};

int cmd_lut( char *str, uint8_t len )
{
    sanitize_input(str, len);
    // get array element position by using first letter of input command
    uint8_t pos = (str[0]-'a');
    // confirm that there's a array elemnt with same starting letter as input then coompare the strings
    return ((cmd_list[pos]!=NULL) && 
            strncmp(str,cmd_list[pos],strlen(cmd_list[pos])) == 0) ? pos : -1;
}

uint32_t *ptr;
size_t len;

size_t i;

int main (void)
{
    // folowing functions will be migrated to their respective functions
    uint32_t words;//todo: migrate
    uint32_t val;//todo migrate
    uint32_t offset;//migrate

    char cmd[36];
    char *opt;
	//size_t i;
    printf("Project 1:\n");
    printf("-----------------------------------------------------------------------\n");
    printf("For list of commands type help\n");
    while (1)
    {
        scanf(" %[^\n]%*c",cmd);
        // get option flags
        opt=strtok(cmd," ");
        opt = strtok(NULL, " ");
        switch(cmd_lut(cmd, strlen(cmd)))
        {
            case 0://allocate
                printf("Type the number of words you wish to allocate then press enter/return:\n");
                //put words dec here when moving to fn
                scanf("%d", &words);
                len=words;
                free(ptr);
                ptr = (uint32_t*) malloc(words * sizeof(uint32_t));
                printf("Allocated %d words or %d bytes of memory\n",words, 8*words);
                break;
            case 3: // display
                if(len>0)
                {
                    printf("Len: %ld.\n", len);
                    for(i=0; i<len; i++)
                    {
                        printf("%ld: %x.\n", i, *(ptr+i));
                    }
                }
                else printf("Memory unitialized.\n");
                break;
            case 4: //exit
                printf("Exiting\n");
                exit(0);
                break;
            case 5: //free
                free(ptr);
                len=0;
                printf("memory freedom achieved\n");
                break;
            case 7: //help
                printf("Usage: [command]\n");
                printf("Commands : Description\n");
                printf("---------:-------------------------------------------------------------\n");
                printf("Allocate : Allocate a amount of bytes of memory that the user specifies\n");
                printf("Free     : Release memory from allocated block\n");
                printf("Display  : Display memory contents in hexidecimal format\n");
                printf("Write    : Write a 32-bit value to a specified memroy address\n");
                printf("Invert   : Invert memory bits at specified location via a XOR operation\n");
                printf("Pattern  : Write a Psuedo-random pattern to a specified address\n");
                printf("Verify   : Validate Psuedo-random pattern using specified seed value\n");
                printf("Exit     : Exit the program\n");
                break;
            case 8: //Invert
                invert(ptr,len);
                break;
            case 15: //pattern
                break;
            case 21://verify
                break;
            case 22://write
                // todo: asl ta if we have to clean inputs
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
                break;
            default:
                printf("Invalid Commdand: Type help for how to run program\n"); 
                break;
        }
	}

	return 0;
}
