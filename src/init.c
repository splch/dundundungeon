#include <gb/cgb.h>
#include <gbdk/font.h>
#include <gbdk/gbdecompress.h>
#include <gbdk/metasprites.h>
#include "main.h"
#include "sgb_border.h"
#include "../res/border_data.h"
#include "../res/hUGEDriver.h"

// extern const hUGESong_t song;
uint8_t arr[ARR_SIZE];
uint8_t SEED;

static inline void init_sgb()
{
    // Wait 4 frames
    // For SGB on PAL SNES this delay is required on startup, otherwise borders don't show up
    for (uint8_t i = 0; i < 4; i++)
        wait_vbl_done();
    SHOW_BKG;
    set_sgb_border(border_data_tiles, sizeof(border_data_tiles), border_data_map, sizeof(border_data_map), border_data_palettes, sizeof(border_data_palettes));
}

static inline void init_font()
{
    font_init();                   // initialize font system
    font_set(font_load(font_ibm)); // set and load the font
}

static inline void init_palette()
{
    // set color palette for compatible ROMs
    set_bkg_palette_entry(0, 0, RGB8(255, 255, 255)); // lightest color
    set_bkg_palette_entry(0, 1, RGB8(0, 255, 0));
    set_bkg_palette_entry(0, 2, RGB8(0, 0, 255));
    set_bkg_palette_entry(0, 3, RGB8(0, 0, 0)); // darkest color

    set_sprite_palette_entry(0, 0, RGB8(255, 255, 255));
    set_sprite_palette_entry(0, 1, RGB8(127, 127, 127));
    set_sprite_palette_entry(0, 2, RGB8(255, 0, 0));
    set_sprite_palette_entry(0, 3, RGB8(0, 0, 0));
}

static inline void init_tiles()
{
    // use metasprite sizes
    SPRITES_8x16;
    // decompress background and sprite data
    // and load them into memory
    set_bkg_data(FONT_MEMORY, gb_decompress(NULL, arr) >> 4, arr);
    set_sprite_data(0, gb_decompress(NULL, arr) >> 4, arr);
}

static inline void init_sound()
{
    // #ifdef NINTENDO // only defined for nintendo
    NR52_REG = 0x80;
    NR51_REG = 0xFF;
    NR50_REG = 0x77;

    hUGE_init(NULL);
    add_VBL(hUGE_dosound);

    LYC_REG = 152;
    STAT_REG = 0b01000000;
    set_interrupts(VBL_IFLAG | LCD_IFLAG);
    // #endif
}

void init_hardware()
{
    DISPLAY_OFF;    // prevent visual bugs
    init_sgb();     // display sgb border
    init_font();    // load font for printf
    init_palette(); // set colors for cgb
    // init_tiles();   // decompress tiles
    init_sound(); // begin playing music
    DISPLAY_ON;   // game is ready!
}

void init_game()
{
    printf("ready");
    // generate random seed
    waitpad(0xFF); // accept any input to continue
    SEED = DIV_REG;
}
