#pragma once
#include "Regist.h"
#include<string>
class InstructionCount :
	public Regist
{
public:
	InstructionCount();
	InstructionCount(std::string);
	~InstructionCount();


	void increment();
};

