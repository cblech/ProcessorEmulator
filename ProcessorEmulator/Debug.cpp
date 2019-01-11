#include "Debug.h"
#include<iostream>

//#define ignoreInfo
//#define ignoreWarning
//#define ignoreError


Debug::Debug()
{
}


Debug::~Debug()
{
}

const void Debug::info(std::string msg)
{
#ifdef ignoreInfo
	return;
#endif
	textout("info", msg);
}

const void Debug::warning(std::string msg)
{
#ifdef ignoreWarning
	return;
#endif
	textout("warning", msg);
}

const void Debug::error(std::string msg)
{
#ifdef ignoreError
	return;
#endif
	textout("error", msg);
}

inline void Debug::textout(std::string pre, std::string text)
{
	std::cout << "Debug " << pre << ": " << text << std::endl;
}
