#pragma once
#include <string>
#include <fstream>
#include <string>
#include "GameObject.h"
#include <vector>
#include "Enemy.h"
#include "camera.h"

class Map
{
private:
	std::vector<std::string> vectorstring;
	std::vector<Enemy> vectorenemies;
public:
	bool loadMap(std::string levelName);
	void drawEnemies(Camera camera);
	void updateEnemies(glm::vec3& p1pos);
	Map();
	~Map();
};

