#include "main.h"
#include "noise.h"

bool isNew = true;

void start_game()
{
    STATE = game;
    if (isNew)
        SEED = DIV_REG; // set random seed
    else
        ; // input password
}

void handle_state()
{
    const uint8_t j = joypad();
    switch (STATE)
    {
    case menu:
        if (j & J_UP)
            isNew = true; // start selection
        if (j & J_DOWN)
            isNew = false; // continue selection
        if (j & J_A || j & J_START)
            start_game();
        break;
    case game:
        if (j & J_B)
        {
            set_bkg_tiles(0, 0, DEVICE_SCREEN_WIDTH, DEVICE_SCREEN_HEIGHT, NULL);
            printf("%d", prng(DIV_REG, LY_REG));
        }
        break;
    }
}