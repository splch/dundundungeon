#include "init.h"
#include "utils.h"
#include "main.h"

void main()
{
  // prepare hardware
  init_hardware();
  // prepare game on START
  init_game();

  // main game loop
  while (true)
  {
    handle_input();  // handle player input
    wait_vbl_done(); // wait until VBLANK to avoid corrupting memory
  }
}
