#include "Regist.h"
#include <string>
#include "ProcessorEmulator.h"


Regist::Regist(std::string name)
{
	IsCapableOf c = { false,false,false,false };

	this->isCapableOf = c;
	this->name = name;
}

Regist::Regist(bool wd, bool rd, bool wa, bool ra, std::string name)
{
	IsCapableOf c = { wd,rd,wa,ra };
	
	this->isCapableOf = c;
	this->name = name;
}

Regist::Regist(IsCapableOf isCapableOf,std::string name)
{
	this->isCapableOf = isCapableOf;
	this->name = name;
}


Regist::~Regist()
{
}

void Regist::readData()
{
	if (this->isCapableOf.ReadData)
	{
		value = g::emulator.dataBus.getValue();
		g::debug.info(std::string("reading ") +std::to_string(value) + " from databus.");
	}
	else
	{
		g::debug.error(name + " is not alowed to read from data bus.");
	}
}
void Regist::writeData()
{
	if (this->isCapableOf.WriteData)
	{
		g::emulator.dataBus.setValue(value);
		g::debug.info(std::string("writing ") + std::to_string(value) + " to databus.");
	}
	else
	{
		g::debug.error(name + " is not alowed to write to data bus.");
	}
}
void Regist::readAddr()
{
	if (this->isCapableOf.ReadAddr)
	{
		value = g::emulator.addressBus.getValue();
		g::debug.info(std::string("reading ") + std::to_string(value) + " from addressbus.");
	}
	else
	{
		g::debug.error(name + " is not alowed to read from address bus.");
	}
}
void Regist::writeAddr()
{
	if (this->isCapableOf.WriteAddr)
	{
		g::emulator.addressBus.setValue(value);
		g::debug.info(std::string("writing ") + std::to_string(value) + " to databus.");
	}
	else
	{
		g::debug.error(name + " is not alowed to to write to address bus.");
	}
}
