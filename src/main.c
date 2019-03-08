
#include "globals.h"

#include "allocate.h"
#include "display.h"
#include "help.h"
#include "invert.h"
#include "pattern.h"
#include "verify.h"
#include "write.h"


#define LINUX (1)

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

uint32_t cmd_lut( char *str, uint8_t len )
{
    sanitize_input(str, len);
    // get array element position by using first letter of input command
    uint8_t pos = (str[0]-'a');
    // confirm that there's a array elemnt with same starting letter as input then coompare the strings
    return ((cmd_list[pos]!=NULL) && 
            strncmp(str,cmd_list[pos],strlen(cmd_list[pos])) == 0) ? pos : 26;
}


int main (void)
{
    char cmd[36];
    char *opt;

    TIME_INIT(t);
#if LINUX
    printf("linux\n");
#else
    printf("FRDM\n");
#endif

    printf("Project 1:\n");
    printf("-----------------------------------------------------------------------\n");
    printf("For list of commands type help\n");
    while (1)
    {
        //cmd[0]='\0';
        scanf(" %[^\n]%*c",cmd);
        // get option flags
        opt = strtok(cmd," ");
        opt = strtok(NULL, " ");
        switch(cmd_lut(cmd, strlen(cmd)))
        {
            case 0://allocate
                allocate();
                break;
            case 3: // display
                display();
                break;
            case 4: //exit
                printf("Exiting\n");
                exit(0);
                break;
            case 5: //free
                //free();
                //len=0;
                printf("memory freedom achieved\n");
                break;
            case 7: //help
                help();
                break;
            case 8: //Invert
                invert();//TODO: add functionality to invert words over a range
                break;
            case 15: //pattern
                pattern();
                break;
            case 21://verify
                verify();
                //XOR with pattern value to confirm if seed is same
                break;
            case 22://write
                write(opt);
                break;
            case 26://TODO: figure out how to suppress this when exiting a function due to invalid entry
                printf("Invalid Commdand: Type help for how to run program\n"); 
                break;
            default:
                break;
        }
	}

	return 0;
}
