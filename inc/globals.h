#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>


// Suppress in-function warnings
#define WARN (1)

// Time initializaiton macro 
#define TIME_INIT(t) (t = clock())





clock_t t;

uint32_t *ptr;
uint32_t len;

