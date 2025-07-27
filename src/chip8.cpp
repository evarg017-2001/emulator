#include "chip8.hpp"
#include <fstream>
#include <iostream>

Chip8::Chip8() {
    pc = 0x200;
    opcode = 0;
    I = 0;
    sp = 0;

    memset(memory, 0, sizeof(memory));
    memset(V, 0, sizeof(V));
    memset(gfx, 0, sizeof(gfx));
    memset(stack, 0, sizeof(stack));
    memset(key, 0, sizeof(key));
}

void Chip8::LoadROM(const char* filename) {
    std::ifstream rom(filename, std::ios::binary | std::ios::ate);
    if (!rom.is_open()) {
        cout << "failed to open ROM\n";
        return;
    }

    std::streampos size = rom.tellg();
    rom.seekg(0, std::ios::beg);
    rom.read(buffer, size);
    rom.close();

    for (int i=0; i<size; ++i) {
        memory[0x200 + i] = buffer[i];
    }

    delete[] buffer;
}

void Chip8::EmulateCycle(){
    opcode = memory[pc] << 8 | memory[pc + 1];
    std::cout << "Fetched opcode: " << std::hex << opcode << "\n"
    pc += 2;
}