#include "StatusRegister.h"



StatusRegister::StatusRegister(std::string name)
{
	this->name = name;
	isCapableOf = IsCapableOf{ true,true,true,true };
}


StatusRegister::~StatusRegister()
{
}

bool StatusRegister::isZero()
{
	return this->value==0;
}

bool StatusRegister::isNegativ()
{
	return (Regist::value|0x7fff)==0xffff;
}

bool StatusRegister::isPositiv()
{
	return !isNegativ();
}
