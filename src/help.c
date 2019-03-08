#include <stdio.h>

void help( void )
{
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
}
