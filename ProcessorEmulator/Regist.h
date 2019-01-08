#pragma once
#include <string>
//#include "ProcessorEmulator.h"


class Regist
{
public:
	struct IsCapableOf;

	Regist(std::string name = "");
	Regist(bool wd,bool rd,bool wa, bool ra, std::string name = "");
	Regist(IsCapableOf isCapableOf,std::string name = "");

	~Regist();

	void readData();
	void writeData();
	void readAddr();
	void writeAddr();

	struct IsCapableOf
	{
		bool WriteData = false;
		bool ReadData = false;
		bool WriteAddr = false;
		bool ReadAddr = false;
	};

protected:
	std::string name;

	IsCapableOf isCapableOf;
	unsigned short value = 0;
};

