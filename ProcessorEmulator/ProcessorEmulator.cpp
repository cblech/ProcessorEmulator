#include "ProcessorEmulator.h"
#include <iostream>
#include "Debug.h"
#include <string>
#include "Bus.h"
#include "Regist.h"
#include "InstructionCount.h"


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

	registerB = Regist("B-Register");
	registerA = StatusRegister("A-Register");

	instuctionRegister = InstuctionRegister("Instuction-Register");
	instructionCounter = InstructionCount("Instruction Counter");

	rechenwerk = Rechenwerk("Rechenwerk");
}


ProcessorEmulator::~ProcessorEmulator()
{
}

int main() {

	//debug.info(emulator.addressBus.getName());
	//debug.info(emulator.dataBus.getName());
	emulator.ram.loadFromFile("ram.txt");


	emulator.addressBus.setValue(0);
	emulator.ram.writeData();
	emulator.rechenwerk.readData();

	emulator.addressBus.setValue(4);
	emulator.ram.writeData();
	emulator.rechenwerk.subData();
	debug.info(emulator.rechenwerk.dump());

	emulator.rechenwerk.invert();
	emulator.rechenwerk.increment();
	debug.info(emulator.rechenwerk.dump());



	system("pause");
	return 0;
}

