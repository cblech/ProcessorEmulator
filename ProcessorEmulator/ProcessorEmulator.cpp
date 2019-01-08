#include "ProcessorEmulator.h"
#include <iostream>
#include "Debug.h"
#include <string>
#include "Bus.h"
#include "Regist.h"


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

	registerB = Regist(true, true, true, true, "B-Register");
	registerA = StatusRegister("A-Register");
}


ProcessorEmulator::~ProcessorEmulator()
{
}

int main() {

	//debug.info(emulator.addressBus.getName());
	//debug.info(emulator.dataBus.getName());

	emulator.addressBus.setValue(5);
	emulator.addressBus.unSet();
	emulator.addressBus.setValue(7);
	emulator.dataBus.setValue(2);
	emulator.dataBus.setValue(3);

	emulator.registerB.readAddr();
	emulator.registerB.writeData();

	emulator.registerA.readData();
	emulator.registerA.isNegativ();

	system("pause");
	return 0;
}

