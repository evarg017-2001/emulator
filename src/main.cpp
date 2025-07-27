#include "chip8.hpp"

int main() {
    Chip8 chip8;
    chip8.loadROM("roms/pong.ch8");
    chip8.EmulateCycle();
    return 0;
}