#pragma once
#include "State.h"
#include "Log.h"
#include "Map.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"
#include "Platform.h"
#include "ImageScreen.h"
#include "Enemy.h"
#include "Utilities\LinkedList.h"
#include "Utilities\LinkedList.cpp"
#include "Weapons.h"

class GamePlayState : public State
{
private:
	Map map;
	Platform *platform;
	Transform transform;
    Shader *shader;
	Camera camera;
	Enemy *enemy1;
	Enemy *enemy2;
	LinkedList<Weapon> weapons;
	int currentGun{ 0 };
	float rotateY{ 0 };
public:
	void Init(Platform *plat) override;
	void Update() override;
	void Draw() override;
	void Input() override;
	GamePlayState();
	~GamePlayState();
};