#include "pch.h"
#include "Weapons.h"


Weapon::Weapon(std::string imageName)
{
	image = new ImageScreen(imageName);
}


Weapon::~Weapon()
{
}
