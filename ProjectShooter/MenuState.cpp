#include "pch.h"
#include "MenuState.h"

void MenuState::Init(Platform *plat)
{
	Log::Write("Current state: Init.");
}

void MenuState::Update()
{
	Log::Write("Current state: Update.");
}

void MenuState::Draw()
{
	Log::Write("Current state: Draw.");
}

void MenuState::Input()
{
	Log::Write("Current state: Input.");
}

MenuState::MenuState()
{
}

MenuState::~MenuState()
{
}
