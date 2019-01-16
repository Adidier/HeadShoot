#include "pch.h"
#include "GameStateManager.h"

void GameStateManager::GameLoop()
{
	try {
		States[index]->Init(platform);
		while (true) {
			#ifndef SDL2
			platform->winMessage();
			#endif
			platform->inputOne();
			States[index]->Input();
			States[index]->Update();
			States[index]->Draw();
			platform->draw();
		}
	}
	catch(...){
		Log::Write("[ERROR] In function (GameLoop): No state");
	}
}

void GameStateManager::PushState(State * st)
{
	if (st != nullptr)
		States.push_back(st);
}

GameStateManager::GameStateManager()
{
#ifdef SDL2
	platform = new PlatformSDL();
#else
	platform = new PlatformWIN32();
#endif
	platform->readConfig();
	platform->init();
}

GameStateManager::~GameStateManager()
{
}
