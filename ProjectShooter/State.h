#pragma once
#include "Platform.h"

class State
{
public:
	virtual void Init(Platform *plat) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Input() = 0;

};

