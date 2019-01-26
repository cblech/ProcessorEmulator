#pragma once
#include <string>
class Bus
{
private:
	unsigned short value;
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

