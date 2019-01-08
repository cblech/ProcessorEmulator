#pragma once
#include "Debug.h"
#include "Bus.h"
#include "Register.h"


class ProcessorEmulator
{
public:
	ProcessorEmulator();
	~ProcessorEmulator();

	Bus dataBus;
	Bus addressBus;
	Bus instructionBus;

	Register registerB;


};

namespace g {
	extern Debug debug;
	extern ProcessorEmulator emulator;
}