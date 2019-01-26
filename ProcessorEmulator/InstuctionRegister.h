#pragma once
#include "Regist.h"
#include <string>

class InstuctionRegister :
	public Regist
{
public:
	InstuctionRegister();
	InstuctionRegister(std::string name);
	~InstuctionRegister();

	void readAddr() = delete;
	void writeAddr() = delete;
	//void readData();
	void writeData() = delete;

	unsigned short getValue();
};

