#include "pch.h"
#include "Log.h"
#include <iostream>
#include <fstream>
#include <string>

void Log::Write(std::string msg)
{
	msg += "\r \n";
	std::ofstream myfile("log.log", std::ios::ate);
	if (myfile.is_open()) //ofstream	ios::out
	{
		myfile << msg ;
		myfile.close();
	}
	else std::cout << "Unable to open file" << std::endl;
}

Log::Log()
{
}


Log::~Log()
{
}
