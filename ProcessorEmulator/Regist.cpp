#include "Regist.h"
#include <string>
#include "ProcessorEmulator.h"
#include "Util.h"

//#define outAllWrites


Regist::Regist(std::string name)
{

	this->name = name;
}



Regist::~Regist()
{
}

void Regist::readData()
{

		value = g::emulator.dataBus.getValue();
#ifdef outAllWrites
		g::debug.info(std::string("reading ") + std::to_string(value) + " from databus.");
#endif

}
void Regist::writeData()
{
		g::emulator.dataBus.setValue(value);
#ifdef outAllWrites
		g::debug.info(std::string("writing ") + std::to_string(value) + " to databus.");
#endif
}
void Regist::readAddr()
{
		value = g::emulator.addressBus.getValue();
#ifdef outAllWrites
		g::debug.info(std::string("reading ") + std::to_string(value) + " from addressbus.");
#endif

}
void Regist::writeAddr()
{

		g::emulator.addressBus.setValue(value);
#ifdef outAllWrites
		g::debug.info(std::string("writing ") + std::to_string(value) + " to databus.");
#endif

}

std::string Regist::dump()
{
	return "Register '" + name + "' has Value: " + std::to_string(value)+" ("+util::to_hex(value)+")";
}
