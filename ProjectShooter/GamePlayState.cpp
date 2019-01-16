#include "pch.h"
#include "GamePlayState.h"

void GamePlayState::Init(Platform *plat)
{
	platform = plat;
	Log::Write("Current state: Init.");
	map.loadMap("Map1.txt");

	shader = new Shader("./Resources/Shaders/basicShader");
	gun = new ImageScreen("./Resources/Sprites/gun.png");
    //enemy1 = new Enemy();
	
}
void GamePlayState::Update()
{
	//Log::Write("Current state: Update.");
	glm::vec3& camPos = camera.GetPos();
	map.updateEnemies(camPos);
}

void GamePlayState::Draw()
{
	gun->Draw();
	//enemy1->Draw(camera);
	map.drawEnemies(camera);
}

void GamePlayState::Input()
{
	//Log::Write("Current state: Input.");
	if (platform->getKeyToRead("P1UP")->state)
	{
		camera.MoveForward(0.1);
	}
	else if (platform->getKeyToRead("P1DOWN")->state)
	{
		camera.MoveForward(-0.1);
	}
	else if (platform->getKeyToRead("P1LEFT")->state)
	{
		camera.MoveRight(0.1);
	}
	else if (platform->getKeyToRead("P1RIGHT")->state)
	{
		camera.MoveRight(-0.1);
	}


	if (platform->getKeyToRead("P2RIGHT")->state)
	{
		camera.RotateY(-0.01);
	}
	else if (platform->getKeyToRead("P2LEFT")->state)
	{
		camera.RotateY(0.01);
	}
}

GamePlayState::GamePlayState():
camera(glm::vec3(0.0f, 0.0f, -5.0f), 140.0f,(float)600 / (float)400, 0.1f, 100.0f)
{
}

GamePlayState::~GamePlayState()
{
	delete enemy1;
}