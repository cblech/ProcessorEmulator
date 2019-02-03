#include "ProcessorEmulator.h"
#include <iostream>
#include "Debug.h"
#include <string>
#include "Bus.h"
#include "Regist.h"
#include "InstructionCount.h"
#include "EmuWindow.h"
#include <thread>
#include <chrono>


namespace g {
	Debug debug;
	ProcessorEmulator emulator;
	WindowData wd = { 0 };
}

#define debug g::debug
#define emulator g::emulator
#define wd g::wd

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


	EmuWindow ew(&wd);
	std::thread tr(&EmuWindow::run,&ew);

	debug.info("thread running...");

	for (int i = 0; i < 0xffff;i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		wd.rechenwerk = i;
		wd.dataBus = 5+i*3;
		wd.addressBus = 20+((i*5)-12);
		wd.ram = -i;
	}


	tr.join();

	//system("pause");
	return 0;
}

