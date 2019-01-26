#pragma once
#include <string>
//#include "ProcessorEmulator.h"


class Register
{
public:
	struct IsCapableOf
	{
		bool WriteData = false;
		bool ReadData = false;
		bool WriteAddr = false;
		bool ReadAddr = false;
	};

	Register(std::string name = "");
	Register(bool wd,bool rd,bool wa, bool ra, std::string name = "");
	Register(IsCapableOf isCapableOf,std::string name = "");

	~Register();

	void readData();
	void writeData();
	void readAddr();
	void writeAddr();
	
private:
	std::string name;

	IsCapableOf isCapableOf;
	int value = 0;
};

