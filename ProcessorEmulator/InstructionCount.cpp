#include "InstructionCount.h"



InstructionCount::InstructionCount()
{
}

InstructionCount::InstructionCount(std::string name)
{
	this->name = name;
}


InstructionCount::~InstructionCount()
{
}

void InstructionCount::increment()
{
	value++;
}
