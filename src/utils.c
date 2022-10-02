#include "main.h"
#include "noise.h"

bool isNew = true;
const uint8_t BASE = 10;

static inline void new_game()
{
    SEED = DIV_REG; // set random seed
    FLOOR = 0; // set floor to lowest
}

static inline void encode(char *str)
{
    uint8_t *key = (uint8_t *)0xC094; // Bank 0: 0xC000
    for (uint8_t i = 0; i < 6; i++)
        str[i] += (key[i] % BASE);
}

static inline void shuffle(char *str)
{
    char temp;
  	temp = str[0];
  	str[0] = str[2];
  	str[2] = temp;
  	temp = str[1];
  	str[1] = str[4];
  	str[4] = temp;
  	temp = str[3];
  	str[3] = str[5];
  	str[5] = temp;
}

static inline char *concat()
{
    SEED = 135;
    FLOOR = 246;
    
    const uint8_t AUTH = prng(SEED, FLOOR);
    char seed[4], floor[4], auth[4], str[7];
  	itoa(SEED, seed, BASE);
  	itoa(FLOOR, floor, BASE);
  	itoa(AUTH, auth, BASE);
  	strcat(strcat(strcat(str, seed), floor), auth);
  	return str;
}

static inline char *make_password()
{
    char *password = concat();
    shuffle(password);
    encode(password);
    printf("%d", password[6] == '\0');
  	return password;
}

static inline void load_password()
{
    char *password = make_password();
    printf("%s", password);
    // if (auth[0] == password[0])
    //     FLOOR = floor;
    // else
    //     new_game();
}

static void set_seed()
{
    if (isNew)
        new_game();
    else
        load_password(); // input password
    STATE = game;
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
            set_seed();
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
