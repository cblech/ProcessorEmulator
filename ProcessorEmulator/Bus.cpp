#include "Bus.h"
#include "ProcessorEmulator.h"
#include <string>

Bus::Bus(std::string name)
{
	//g::debug.info(name);
	this->name = name;
	value = 0;
	defined = false;
}


Bus::~Bus()
{
}

int Bus::getValue()
{
	return value;
}

void Bus::setValue(int value)
{
	if (defined)
	{
		g::debug.warning(std::string("Multiple writes on Bus")+((name=="")?".":" "+name+".")+" Now using Value: "+std::to_string(value));
	}
	this->value = value;
	this->defined = true;
}

void Bus::unSet()
{
	value = 0;
	this->defined = false;
}

std::string Bus::getName()
{
	return name;
}
