#include "ProcessorEmulator.h"
#include <iostream>
#include "Debug.h"
#include <string>
#include "Bus.h"
#include "Register.h"


namespace g {
	Debug debug;
	ProcessorEmulator emulator;
}

#define debug g::debug
#define emulator g::emulator

ProcessorEmulator::ProcessorEmulator()
{
	dataBus = Bus("data");
	addressBus = Bus("address");
	instructionBus = Bus("instruction");

	registerB = Register(true, true, true, true, "B-Register");
}


ProcessorEmulator::~ProcessorEmulator()
{
}

int main() {

	//debug.info(emulator.addressBus.getName());
	//debug.info(emulator.dataBus.getName());

	emulator.addressBus.setValue(2);
	emulator.addressBus.unSet();
	emulator.addressBus.setValue(2);
	emulator.dataBus.setValue(2);
	emulator.dataBus.setValue(2);

	system("pause");
	return 0;
}

