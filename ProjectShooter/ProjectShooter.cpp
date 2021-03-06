// ProjectShooter.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include "State.h"
#include "GamePlayState.h"
#include "GameStateManager.h"
#include <iostream>
#include <Windows.h> //Standard windows headers

#ifdef SDL2
#pragma comment(lib,"SDL2.lib")
#pragma comment(lib,"SDL2main.lib")

int main(int argc, char *argv[]) {
#else
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
#endif
	State * gamePlay = new GamePlayState();

	GameStateManager * stateManager = new GameStateManager();
	stateManager->PushState(gamePlay);
	//stateManager = nullptr;
	stateManager->GameLoop(); //Dentro el init.

	system("pause");
	return 0;
}
