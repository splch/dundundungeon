#include "main.h"
#include "noise.h"

void handle_input()
{
    const uint8_t j = joypad();
    if (j & J_RIGHT)
        printf("right\n");
    if (j & J_LEFT)
        printf("left\n");
    if (j & J_UP)
        printf("up\n");
    if (j & J_DOWN)
        printf("down\n");
    if (j & J_A)
        printf("prn: %d\n", prng(DIV_REG, LY_REG));
    if (j & J_B)
        printf("b\n");
    if (j & J_START)
        printf("seed: %d\n", SEED);
    if (j & J_SELECT)
        printf("select\n");
}