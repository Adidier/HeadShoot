#include "pch.h"
#include "PlatformSDL.h"
#include "SDL.h"
#include <iostream>
#include <string>
#include "GL/glew.h"

void PlatformSDL::draw()
{
	SDL_GL_SwapWindow(window);
}

void PlatformSDL::init()
{
	Platform::init();

	setWidth(getWidth());
	setHeight(getHeight());

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init";
		return;
	}

	//Get window mode.
	switch (windowGet){
		case 1:
			windowMode = SDL_WINDOW_FULLSCREEN;
			break;
		case 0:
		default:
			windowMode = SDL_WINDOW_SHOWN;
			break;
	}


	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	window = SDL_CreateWindow(getName().c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, getWidth(), getHeight(), windowMode| SDL_WINDOW_OPENGL);


	if (window == nullptr) {
		Log::Write("CreateWindow");
		throw std::runtime_error("error");
		return;
	}

	renderer = SDL_GL_CreateContext(window);

	if (renderer == nullptr) {
		Log::Write("CreateRenderer");
		throw std::runtime_error("error");
		return;
	}

	GLenum status = glewInit();
	if (status != GLEW_OK)
	{
		std::cout << "error init opengl";
	}
	

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}

int PlatformSDL::inputOne()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	const char* currentKeyStates = (char*)SDL_GetKeyboardState(NULL);
	Key *key = getKeyToRead("P1UP");
	if (key&&currentKeyStates[key->asciiValue - 93])
		key->state = 1;
	else
		key->state = 0;

	key = getKeyToRead("P1DOWN");
	if (key&&currentKeyStates[key->asciiValue - 93])
		key->state = 1;
	else
		key->state = 0;

	key = getKeyToRead("P1LEFT");
	if (key&&currentKeyStates[key->asciiValue - 93])
		key->state = 1;
	else
		key->state = 0;

	key = getKeyToRead("P1RIGHT");
	if (key&&currentKeyStates[key->asciiValue - 93])
		key->state = 1;
	else
		key->state = 0;

	key = getKeyToRead("P2UP");
	if (key&&currentKeyStates[key->asciiValue - 93])
		key->state = 1;
	else
		key->state = 0;

	key = getKeyToRead("P2DOWN");
	if (key&&currentKeyStates[key->asciiValue - 93])
		key->state = 1;
	else
		key->state = 0;

	key = getKeyToRead("P2LEFT");
	if (key&&currentKeyStates[key->asciiValue - 93])
		key->state = 1;
	else
		key->state = 0;

	key = getKeyToRead("P2RIGHT");
	if (key&&currentKeyStates[key->asciiValue - 93])
		key->state = 1;
	else
		key->state = 0;


	glClearColor(1,0,0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	return 0;
}

PlatformSDL::PlatformSDL()
{
}

PlatformSDL::~PlatformSDL()
{
}
