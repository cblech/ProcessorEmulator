#include "Rechenwerk.h"
#include "ProcessorEmulator.h"


Rechenwerk::Rechenwerk()
{
}

Rechenwerk::Rechenwerk(std::string name)
{
	this->name = name;
}


Rechenwerk::~Rechenwerk()
{
}

void Rechenwerk::addData()
{
	value += g::emulator.dataBus.getValue();
}

void Rechenwerk::subData()
{
	value -= g::emulator.dataBus.getValue();
}

void Rechenwerk::mulData()
{
	value *= g::emulator.dataBus.getValue();
}

void Rechenwerk::divData()
{
	value /= g::emulator.dataBus.getValue();
}

void Rechenwerk::increment()
{
	value++;
}

void Rechenwerk::decrement()
{
	value--;
}

void Rechenwerk::invert()
{
	value = ~value;
}
