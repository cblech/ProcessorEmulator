#pragma once
#include "Debug.h"
#include "Regist.h"
#include "Bus.h"
#include "StatusRegister.h"
#include "Ram.h"
#include "InstuctionRegister.h"
#include "Rechenwerk.h"
#include "InstructionCount.h"
#include "EmuWindow.h"

class ProcessorEmulator
{

public:
	ProcessorEmulator();
	~ProcessorEmulator();

	Bus dataBus;
	Bus addressBus;
	Bus instructionBus;

	Ram ram;

	Regist registerB;
	StatusRegister registerA;
	InstructionCount instructionCounter;

	InstuctionRegister instuctionRegister;

	Rechenwerk rechenwerk;
};

namespace g {
	extern Debug debug;
	extern ProcessorEmulator emulator;
	extern WindowData wd;
}