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

	ram = Ram("Ram");

	registerB = Regist(true, true, true, true, "B-Register");
	registerA = StatusRegister("A-Register");
}


ProcessorEmulator::~ProcessorEmulator()
{
}

int main() {

	//debug.info(emulator.addressBus.getName());
	//debug.info(emulator.dataBus.getName());
	emulator.ram.setRamAt(50, 3);
	emulator.ram.setRamAt(51, 4);
	emulator.ram.setRamAt(52, 5);
	emulator.ram.setRamAt(53, 6);
	emulator.ram.setRamAt(54, 7);


	emulator.dataBus.setValue(50);
	emulator.registerB.readData();

	emulator.registerB.writeAddr();

	emulator.ram.writeData();

	emulator.registerA.readData();

	debug.info(emulator.registerA.dump());

	emulator.dataBus.setValue(100);
	emulator.ram.readData();

	debug.info(emulator.ram.dump());
	debug.info(emulator.ram.dump(20));
	debug.info(emulator.ram.dump(53));

	system("pause");
	return 0;
}

