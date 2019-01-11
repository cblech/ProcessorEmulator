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

	registerB = Regist("B-Register");
	registerA = StatusRegister("A-Register");

	instuctionRegister = InstuctionRegister("Instuction-Register");
}


ProcessorEmulator::~ProcessorEmulator()
{
}

int main() {

	//debug.info(emulator.addressBus.getName());
	//debug.info(emulator.dataBus.getName());
	emulator.ram.loadFromFile("ram.txt");


	debug.info(emulator.ram.dump());
	debug.info(emulator.ram.dump(1));
	debug.info(emulator.ram.dump(2));
	debug.info(emulator.ram.dump(3));
	debug.info(emulator.ram.dump(9));
	debug.info(emulator.ram.dump(100));

	system("pause");
	return 0;
}

