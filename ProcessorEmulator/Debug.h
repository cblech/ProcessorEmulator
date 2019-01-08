#pragma once
#include <string>

class Debug
{
public:
	Debug();
	~Debug();

	const void info(std::string msg);
	const void warning(std::string msg);
	const void error(std::string msg);

private:
	void inline textout(std::string pre,std::string text);
};

