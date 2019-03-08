#include "globals.h"

void invert(void)
{
	size_t i;
	clock_t t0, tf;
	printf("enter memory location offset value of the number to invert:\n");
	scanf("%ld",&i);
	if(i<len)
	{
		//get initial time
		t0=clock();
		// perform inverting operation
		*(ptr+i) = ~*(ptr+i);
		// get time after operation
		tf=clock();
		//print how logn it took for operation to execute
		printf("Inversion complete. Time elapsed: %f seconds\n", 
				(double)(tf - t0) / CLOCKS_PER_SEC);
	}
	else printf("invalid memory location.\n");
}
