#include "pch.h"
#include "GamePlayState.h"
// Siempre debe de estar en debug y x64 para compilar
#include "Utilities\HashTable.h"
#include "BinaryTree.h"
#include <iostream>

int CompareInts(int left, int right)
{
	return left - right;
}

void GamePlayState::Init(Platform *plat)
{
	BinarySearchTree<int> tree(CompareInts);
	BinaryTree<int>* node;
	// insert data
	tree.Insert(8);
	tree.Insert(4);
	tree.Insert(12);
	tree.Insert(2);
	tree.Insert(6);
	tree.Insert(10);
	tree.Insert(14);
	tree.Insert(14);
	platform = plat;
	Log::Write("Current state: Init.");
	map.loadMap("Map1.txt");

	shader = new Shader("./Resources/Shaders/basicShader");
	gun1 = new ImageScreen("./Resources/Sprites/gun1.png");
	gun2 = new ImageScreen("./Resources/Sprites/gun2.png");

	guns.Append(1);
	guns.Append(2);

	guns.Append(3);

	guns.Append(4);
	guns.RemoveTail();
    enemy1 = new Enemy();
}
void GamePlayState::Update()
{
	//Log::Write("Current state: Update.");
	glm::vec3& camPos = camera.GetPos();
	map.updateEnemies(camPos);
}

void GamePlayState::Draw()
{
	if(currentGun==0)
		gun1->Draw();
	else if (currentGun == 1)
		gun2->Draw();
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

	if (platform->getKeyToRead("P1SELECT")->state)
	{
		currentGun++;
		platform->getKeyToRead("P1SELECT")->state = 0;
		if (currentGun > 1)
			currentGun = 0;
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