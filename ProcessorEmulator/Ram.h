#pragma once
#include "Regist.h"
#include <string>

class Ram :
	public Regist
{
public:
	Ram();
	Ram(std::string name);
	~Ram();

	short getRam();
	void setRam(short);

	short getRamAt(short);
	void setRamAt(short,short);

	void writeData();
	void readData();

	void readAddr() = delete;
	void writeAddr() = delete;

	std::string dump();

	std::string dump(short pos);

private:
	short value[0xffff] = { 0 };
};

