#pragma once
#include "Debug.h"
#include "Regist.h"
#include "Bus.h"
#include "StatusRegister.h"


class ProcessorEmulator
{

public:
	ProcessorEmulator();
	~ProcessorEmulator();

	Bus dataBus;
	Bus addressBus;
	Bus instructionBus;

	
	Regist registerB;
	StatusRegister registerA;

};

namespace g {
	extern Debug debug;
	extern ProcessorEmulator emulator;
}