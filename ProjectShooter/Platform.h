#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "Key.h"

class Platform
{
private:
	int width, height;
	void readInputs(std::ifstream & file);
	
protected:
	int windowGet;
	std::map<std::string, Key> keyMap;
	std::string name, InitMap;

public:
	Key *getKeyToRead(std::string key);
	int getWidth();
	void setWidth(int w);
	int getHeight();
	void setHeight(int h);
	std::string getName();
	void setName(std::string n);
	virtual void init();
	virtual void draw()=0;
	void readConfig();
	virtual int inputOne() = 0; //= 0; //Abstracta pura.
	
	Platform();
	~Platform();
};