#ifndef MAIN_H_INCLUDE
#define MAIN_H_INCLUDE

#include <gbdk/platform.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// --- GB VALUES --- //
#define FONT_MEMORY 102 // prevents writing over font memory
// ----------------- //

#define bool uint8_t
#define true 1
#define false 0

#define ARR_SIZE 256
extern uint8_t arr[ARR_SIZE]; // for used items and decompression

#endif
