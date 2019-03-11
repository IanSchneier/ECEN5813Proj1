#include "help.h"

void help( void )
{
    PRINTF("Usage: [command]\r\n");
    PRINTF("Commands : Description\r\n");
    PRINTF("---------:-------------------------------------------------------------\r\n");
    PRINTF("Allocate : Allocate a amount of bytes of memory that the user specifies\r\n");
    PRINTF("Free     : Release memory from allocated block\r\n");
    PRINTF("Display  : Display memory contents in hexidecimal format\r\n");
    PRINTF("Write    : Write a 32-bit value to a specified memroy address\r\n");
    PRINTF("Invert   : Invert memory bits at specified location via a XOR operation\r\n");
    PRINTF("Pattern  : Write a Psuedo-random pattern to a specified address\r\n");
    PRINTF("Verify   : Validate Psuedo-random pattern using specified seed value\r\n");
    PRINTF("Exit     : Exit the program\r\n");
}

