#include "StatusRegister.h"



StatusRegister::StatusRegister(std::string name)
{
	Regist(true,true,true,true,name);
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
	return Regist::value|0x7fff==0xffff;
}
