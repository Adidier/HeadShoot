#pragma once
#include "State.h"
#include "Log.h"
class MenuState : public State
{
public:
	void Init(Platform *plat) override;
	void Update() override;
	void Draw() override;
	void Input() override;
	MenuState();
	~MenuState();
};

