#include "pch.h"
#include "GameObject.h"


void GameObject::setType(int _t)
{
	type = _t;
}

int GameObject::getType()
{
	return type;
}

void GameObject::setName(std::string _n)
{
	name = _n;
}

std::string GameObject::getName()
{
	return name;
}

void GameObject::setX(int _x)
{
	x = _x;
}

int GameObject::getX()
{
	return x;
}

void GameObject::setY(int _y)
{
	y = _y;
}

int GameObject::getY()
{
	return y;
}

void GameObject::setZ(int _z)
{
	z = _z;
}

int GameObject::getZ()
{
	return z;
}

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}
