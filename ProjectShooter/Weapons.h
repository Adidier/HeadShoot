#pragma once
#include "ImageScreen.h"
#include <string>
class Weapon
{
public:
	Weapon(std::string imageName);
	~Weapon();

private:
	ImageScreen *image;
};

