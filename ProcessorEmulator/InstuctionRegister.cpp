#include "InstuctionRegister.h"



InstuctionRegister::InstuctionRegister()
{
	
}

InstuctionRegister::InstuctionRegister(std::string name)
{
	this->name = name;
}


InstuctionRegister::~InstuctionRegister()
{
}

unsigned short InstuctionRegister::getValue()
{
	return value;
}
