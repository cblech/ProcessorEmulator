#pragma once
#include <string>
class Bus
{
private:
	unsigned int value;
	bool defined;
	std::string name;
public:
	Bus(std::string name="");
	~Bus();

	int getValue();
	void setValue(int value);
	void unSet();

	std::string getName();
};

