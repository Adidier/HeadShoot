#include "pch.h"
#include "GamePlayState.h"
#include "Stack.h"
// Siempre debe de estar en debug y x64 para compilar
#include "Utilities\HashTable.h"
#include "Utilities\Tree.h"
#include <iostream>

template <class DataType>
void print(Tree<DataType>* node)
{
	std::cout << node->m_data<<std::endl;
}
void GamePlayState::Init(Platform *plat)
{
	Tree<int>* node = new Tree<int>;
	TreeIterator<int> itr(node);
	itr = node;

	node->m_data = 5;

	Tree<int>* nodeHijoDerecho = new Tree<int>;
	node->m_children.Append(nodeHijoDerecho);
	nodeHijoDerecho->m_data = 10;


	Tree<int>* nodeHijoIzquierdo = new Tree<int>;
	node->m_children.Append(nodeHijoIzquierdo);
	nodeHijoIzquierdo->m_data = 20;

	Tree<int>* nodeHijoDer2 = new Tree<int>;
	nodeHijoDer2->m_data = 3;
	nodeHijoDerecho->m_children.Append(nodeHijoDer2);
	int count = node->Count();

	node->Preorder(node, print);
	node->Postorder(node, print);

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