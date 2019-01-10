#include "Ram.h"
#include "ProcessorEmulator.h"
#include "Util.h"

Ram::Ram()
{	
}

Ram::Ram(std::string name)
{
	this->name = name;
}

Ram::~Ram()
{
}

short Ram::getRam()
{
	return value[g::emulator.addressBus.getValue()];
}

void Ram::setRam(short newVal)
{
	value[g::emulator.addressBus.getValue()]=newVal;
}

short Ram::getRamAt(short pos)
{
	return value[pos];
}

void Ram::setRamAt(short pos, short newVal)
{
	value[pos]=newVal;
}

void Ram::writeData()
{
	g::emulator.dataBus.setValue(getRam());
}

void Ram::readData()
{
	setRam(g::emulator.dataBus.getValue());
}

std::string Ram::dump()
{
	return "Register '" + name
		+ "' has Value " + std::to_string(value[g::emulator.addressBus.getValue()])
		+ " (" + util::to_hex(value[g::emulator.addressBus.getValue()])
		+ ") at Address " + std::to_string(g::emulator.addressBus.getValue()) + ".";
}

std::string Ram::dump(short pos)
{
	return "Register '" + name
		+ "' has Value " + std::to_string(value[pos])
		+ " (" + util::to_hex(value[pos])
		+ ") at Address " + std::to_string(pos) + ".";
}

