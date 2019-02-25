#include "pch.h"
#include "GamePlayState.h"
#include "Stack.h"
// Siempre debe de estar en debug y x64 para compilar
#include "Utilities\HashTable.h"
#include "BinaryTree.h"
#include <iostream>


void GamePlayState::Init(Platform *plat)
{
	BinaryTree<int>* raiz1;
	BinaryTree<int>* raiz = new BinaryTree<int>;
	raiz->data = 28;
	raiz->leftChild = new BinaryTree<int>;
	raiz->leftChild->data = 37;
	raiz->leftChild->parent = raiz;

	raiz->rightChild = new BinaryTree<int>;
	raiz->rightChild->data = 6;
	raiz->rightChild->parent = raiz;

	raiz->leftChild->leftChild = new BinaryTree<int>;
	raiz->leftChild->leftChild->data = 79;
	raiz->leftChild->leftChild->parent = raiz->leftChild;

	raiz->leftChild->rightChild = new BinaryTree<int>;
	raiz->leftChild->rightChild->data = 42;
	raiz->leftChild->rightChild->parent = raiz->leftChild;

	BinaryTree<int>::Destroy(raiz);

	if (raiz->leftChild)
	{
		int count = raiz->Count();
	}
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

	Stack <int> pila;
	pila.push(1);
	pila.push(2);
	pila.push(3);
	pila.pop();

	int r = pila.top();
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