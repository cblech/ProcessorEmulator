#pragma once
#include "Regist.h"
#include <string>

class Rechenwerk :
	public Regist
{
public:
	Rechenwerk();
	Rechenwerk(std::string);
	~Rechenwerk();

	void addData();
	void subData();
	void mulData();
	void divData();

	void increment();
	void decrement();

	void invert();
};

