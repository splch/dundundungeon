#include "init.h"
#include "main.h"

static inline void init_hardware();
static inline void init_game();
static inline void check_input();

void main()
{
  // prepare hardware
  init_hardware();
  // prepare game on START
  init_game();

  // main game loop
  while (true)
  {
    check_input();   // check for player input
    wait_vbl_done(); // wait until VBLANK to avoid corrupting memory
  }
}

static inline void init_hardware()
{
  DISPLAY_OFF;    // prevent visual bugs
  init_sgb();     // display sgb border
  init_font();    // load font for printf
  init_palette(); // set colors for cgb
  // init_tiles();   // decompress tiles
  init_sound(); // begin playing music
  DISPLAY_ON;   // game is ready!
}

static inline void init_game()
{
  printf("Dun\nDun\nDungeon!");
}

static inline void check_input()
{
}
