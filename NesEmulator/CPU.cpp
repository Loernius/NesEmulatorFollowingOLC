#include "CPU.h"

CPU::CPU()
{
}

CPU::~CPU()
{
}

uint8_t CPU::read(uint16_t addr) 
{
	return bus->read(addr, false);
}

void CPU::write(uint16_t addr, uint8_t data)
{
	bus->write(addr, data);
}