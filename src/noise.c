#include "main.h"

uint8_t prng(uint8_t x, uint8_t y)
{
    y ^= x >> 1;
    x ^= y << 3;
    return (x + y) ^ SEED;
}
