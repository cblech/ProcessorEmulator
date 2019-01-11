#pragma once
#include "Regist.h"
class InstructionCount :
	public Regist
{
public:
	InstructionCount();
	~InstructionCount();

	void increment();
};

