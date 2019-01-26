#include "Util.h"
#include <string>
#include <sstream>
#include <iomanip>

namespace util {

	std::string to_hex(short i)
	{
		std::stringstream stream;
		stream << "0x"
			<< std::setfill('0') << std::setw(sizeof(short) * 2)
			<< std::hex << i;
		return stream.str();
	}

	

}