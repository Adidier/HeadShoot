#pragma once
#include <string>
class Log
{
public:
	static void Write(std::string msg);
	Log();
	~Log();
};

