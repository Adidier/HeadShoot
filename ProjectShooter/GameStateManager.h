#pragma once
#include <vector>
#include "State.h"
#include "Log.h"
#include "Platform.h"
#include "PlatformSDL.h"
#include "PlatformWIN32.h"
class GameStateManager
{
private:
	std::vector<State *> States;
	int index = 0;
#ifdef SDL2
	PlatformSDL * platform;
#else
	PlatformWIN32 * platform;
#endif
public:
	void GameLoop();
	void PushState(State * st);
	GameStateManager();
	~GameStateManager();
};

