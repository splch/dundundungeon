# Dun Dun Dungeon!

A roguelike GameBoy game that could have been released in 1989.

## File Structure

1. `src/` contains source code for building the game

2. `res/` stores resources in the game

3. `tools/` clones various development tools:

- [tile designer](https://github.com/gbdk-2020/GBTD_GBMB/releases/) to edit the `res/*.gbr` files

- [emulicious](https://emulicious.net/) to run the GameBoy ROM.

- [hUGETracker](https://nickfa.ro/index.php/HUGETracker) to compose `res/*.uge`

- [romusage](https://github.com/bbbbbr/romusage) to view the GameBoy ROM bank space `./romusage game.map -gA`

4. `build/` has the most recent ROMs for different systems

## Installation

1. To play the game, move the release or `build/gb/Dun Dun Dungeon.gb` ROM into your emulator / flash cart.

2. To build it from source, follow [GBDK's guide](https://github.com/gbdk-2020/gbdk-2020#build-instructions).

3. Run `export GBDK_HOME=/path/to/gbdk-2020`

Once the environment has been built, run:

```shell
make gb
```

There should now be a new `Dun Dun Dungeon.gb` file in the `build/gb/` directory.

Alternatively, you can upload the ROM to an emulator site like @Juchi's [GameBoy emulator](https://juchi.github.io/gameboy.js/) and run it. To use `Emulicious.jar`, install the Java runtime (`openjdk-*-jre`) and run `java -jar Emulicious.jar`.

## Features

Features:

- [ ] Custom tileset
  - [x] Color palette
  - [x] Super GameBoy background
- [ ] 16×16 Metatiles (sprites and backgrounds)
- [ ] Music
- [ ] Start screen
- [ ] Menu
- [ ] Items
  - [ ] Weapons
  - [ ] Potions
  - [ ] Equipment
- [ ] Enemies

## Generation

This game uses [xorshift](https://wikipedia.org/wiki/Xorshift) noise to generate its maps. The algorithm is based on [Hugo Elias'](https://web.archive.org/web/20160303203643/http://freespace.virgin.net/hugo.elias/models/m_perlin.htm) tutorial.

## Misc

- SGB Border Generation: `png2asset res/border.png -map -bpp 4 -max_palettes 4 -pack_mode sgb -use_map_attributes -c res/border_data.c`

- ROM Usage Analysis: `./tools/romusage/romusage build/gb/*.map`
