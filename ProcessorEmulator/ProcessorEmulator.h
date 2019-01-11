#pragma once
#include "Debug.h"
#include "Regist.h"
#include "Bus.h"
#include "StatusRegister.h"
#include "Ram.h"
#include "InstuctionRegister.h"

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

	InstuctionRegister instuctionRegister;
};

namespace g {
	extern Debug debug;
	extern ProcessorEmulator emulator;
}