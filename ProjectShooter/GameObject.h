#pragma once
#include <string>
class GameObject
{
protected:
	int type{ 0 }, x{ 0 }, y{ 0 }, z{ 0 };
	std::string name;
public:
	void setType(int _t);
	int getType();
	void setName(std::string _n);
	std::string getName();
	void setX(int _x);
	int getX();
	void setY(int _y);
	int getY();
	void setZ(int _z);
	int getZ();
	GameObject();
	~GameObject();
};

