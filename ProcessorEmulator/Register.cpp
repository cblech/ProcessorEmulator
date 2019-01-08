#include "Register.h"
#include <string>


Register::Register(std::string name)
{
	Register(true, true, true, true, name);
}

Register::Register(bool wd, bool rd, bool wa, bool ra, std::string name)
{
	IsCapableOf c = { wd,rd,wa,ra };
	Register(c, name);
}

Register::Register(IsCapableOf isCapableOf,std::string name)
{
	this->isCapableOf = isCapableOf;
	this->name = name;
}


Register::~Register()
{
}

void Register::readData()
{
	if (this->isCapableOf.ReadData)
	{
		value = g::emulator.dataBus.getValue();
	}
	else
	{
		g::debug.error(name + " is not alowed to read from data bus.");
	}
}
void Register::writeData()
{
	if (this->isCapableOf.WriteData)
	{
		g::emulator.dataBus.setValue(value);
	}
	else
	{
		g::debug.error(name + " is not alowed to write to data bus.");
	}
}
void Register::readAddr()
{
	if (this->isCapableOf.ReadAddr)
	{
		value = g::emulator.addressBus.getValue();
	}
	else
	{
		g::debug.error(name + " is not alowed to read from address bus.");
	}
}
void Register::writeAddr()
{
	if (this->isCapableOf.WriteAddr)
	{
		g::emulator.addressBus.setValue(value);
	}
	else
	{
		g::debug.error(name + " is not alowed to to write to address bus.");
	}
}
