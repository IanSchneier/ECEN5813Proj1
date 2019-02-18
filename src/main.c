#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void sanitize_input(char *str, size_t len)
{
    size_t i=0;
    while(i<len)
    {
        // force the char to lowercase value
        *(str+i)= ( (*(str+i)>='A') && (*(str+i) <= 'Z') ) ? (*(str+i)+32) : *(str+i);
        i++;
    }
}

int main (void)
{
    char cmd[36];
	
    printf("Project 1:\n");
    printf("-----------------------------------------------------------------------\n");
    printf("For list of commands type help\n");
    while (1)
    {
        scanf("%s", cmd);
        sanitize_input(cmd, strlen(cmd));

		if(strncmp(cmd,"help",4)==0)
		{
            printf("Usage: [command]\n\n");
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
		}
		else if(strncmp(cmd,"allocate",8)==0)
        {
            printf("allocate coming soon.\n");
        }
		else if(strncmp(cmd,"free",4)==0)
        {
            printf("free coming soon.\n");
        }
		else if(strncmp(cmd,"display",7)==0)
        {
            printf("display coming soon.\n");
        }
        else if(strncmp(cmd,"write",5)==0)
        {
            printf("write coming soon.\n");
        }
        else if(strncmp(cmd,"invert",6)==0)
        {
            printf("invert coming soon.\n");
        }
        else if(strncmp(cmd,"pattern",7)==0)
        {
            printf("pattern coming soon.\n");
        }
        else if(strncmp(cmd,"verify",6)==0)
        {
            printf("verify coming soon.\n");
        }
        else if(strncmp(cmd,"exit",4)==0)
		{
			printf("Exiting\n");
            exit(0);
		}
        else
        {
            printf("Invalid Commdand: Type help for how to run program\n");
        }
	}

	return 0;
}
