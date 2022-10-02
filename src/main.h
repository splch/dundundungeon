#ifndef MAIN_H_INCLUDE
#define MAIN_H_INCLUDE

#include <gbdk/platform.h>
#include <gbdk/console.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// --- GB VALUES --- //
#define SEED_LENGTH 3
#define FLOOR_LEGNTH 3
#define AUTH_LENGTH 1
#define PASSWORD_LENGTH SEED_LENGTH + FLOOR_LEGNTH + AUTH_LENGTH + 1
#define FONT_MEMORY 102 // prevents writing over font memory
// ----------------- //

#define bool uint8_t
#define true 1
#define false 0

#define ARR_SIZE 256
extern uint8_t arr[ARR_SIZE]; // for used items and decompression
extern uint8_t SEED;
extern uint8_t FLOOR;

extern enum state {
    menu,
    game,
} STATE;

#endif
