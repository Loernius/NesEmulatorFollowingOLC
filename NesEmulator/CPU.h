#pragma once
#include<cstdint>
#include "Bus.h"

class CPU
{
public:
	// constructor and destructor
	CPU();
	~CPU();
	// variables
	struct REGISTERS {
		uint8_t acc = 0x00; // accumulator
		uint8_t x = 0x00; // x register
		uint8_t y = 0x00; // y register
		uint8_t status = 0x00; // status register
		uint16_t pc = 0x00; // program counter
		uint8_t stack = 0x00; // stack pointer
	};

	enum FLAGS {
		C = (1 << 0), // Carry Bit
		Z = (1 << 1), // Zero
		I = (1 << 2), // Disable Interrupts
		D = (1 << 3), // Decimal Mode (unused)
		B = (1 << 4), // Break
		U = (1 << 5), // Unused
		V = (1 << 6), // Overflow
		N = (1 << 7) // Negative
	};

	void clock();
	void reset();
	void irq();
	void mmi();

	uint8_t fetch();
	uint8_t fetched = 0x00;

	void ConnectBus(Bus* n) { bus = n; };

private:
	Bus* bus = nullptr;

	uint8_t read(uint16_t addr);
	
	void write(uint16_t addr, uint8_t data);

	void SetFlag(FLAGS flag, bool v);
	uint8_t GetFlag(FLAGS flag);

	uint8_t filterInstruction(int8_t instruction);
};

