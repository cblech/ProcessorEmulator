#pragma once
#include <string>
//#include "ProcessorEmulator.h"


class Regist
{
public:

	Regist(std::string name = "");

	~Regist();

	void readData();
	void writeData();
	void readAddr();
	void writeAddr();

	std::string dump();


protected:
	std::string name;

	unsigned short value = 0;
};

