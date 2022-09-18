#include "init.h"
#include "utils.h"
#include "main.h"

void main()
{
  // prepare hardware
  init_hardware();
  // prepare game
  init_game();

  // main game loop
  while (true)
  {
    handle_state();  // logic for game state
    wait_vbl_done(); // wait until VBLANK to avoid corrupting memory
  }
}
