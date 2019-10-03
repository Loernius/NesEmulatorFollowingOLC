#pragma once
#include<cstdint>
#include "CPU.h"
#include<array>

class Bus
{
public:
	// initializers
	Bus();
	~Bus();
	// write and read functions
	void write(uint16_t addr, uint8_t data);
	uint8_t read(uint16_t addr, bool bReadOnly = false);
	// connected devices
	CPU	cpu;

	std::array<uint8_t, 64 * 1024> ram;


};

