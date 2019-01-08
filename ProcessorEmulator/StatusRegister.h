#pragma once
#include "Regist.h"
class StatusRegister :
	public Regist
{
public:
	StatusRegister(std::string name = "");
	~StatusRegister();

	bool isZero();
	bool isNegativ();
	bool isPositiv();
};

