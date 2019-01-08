#include "Debug.h"
#include<iostream>


Debug::Debug()
{
}


Debug::~Debug()
{
}

const void Debug::info(std::string msg)
{
	textout("info", msg);
}

const void Debug::warning(std::string msg)
{
	textout("warning", msg);
}

const void Debug::error(std::string msg)
{
	textout("error", msg);
}

inline void Debug::textout(std::string pre, std::string text)
{
	std::cout << "Debug " << pre << ": " << text << std::endl;
}
