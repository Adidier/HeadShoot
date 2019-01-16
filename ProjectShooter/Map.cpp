#include "pch.h"
#include "Map.h"
#include <sstream>
#include <iostream>

bool Map::loadMap(std::string levelName)
{
	std::string currLine;
	std::ifstream myfile("Map1.txt");
	if (myfile.is_open()) {

		while (!myfile.eof())
		{
			getline(myfile, currLine); //line 1
			//for (int c = 0; c < currLine.length(); ++c) {
			Enemy enemy;
			std::vector<std::string> vect;
			std::stringstream ss(currLine);
			while (ss.good())
			{
				std::string substr;
				getline(ss, substr, ',');
				vect.push_back(substr);
			}
			enemy.SetPosition(stoi(vect[2]), stoi(vect[3]), stoi(vect[4]));
			vectorenemies.push_back(enemy);
		}
	}
	return false;
}

Map::Map()
{
}

void Map::drawEnemies(Camera camera)
{
	for (Enemy e : vectorenemies)
		e.Draw(camera);
}

void Map::updateEnemies(glm::vec3 & p1pos)
{
	std::vector<Enemy> tempvector;
	for (Enemy e : vectorenemies)
	{
		float x = e.GetXPosition();
		float y = e.GetYPosition();
		float z = e.GetZPosition();
		float squared;
		squared = sqrt(((x-p1pos.x) *(x - p1pos.x)) + ((y- p1pos.y) *(y - p1pos.y)) + ((z-p1pos.z)*(z - p1pos.z)));
		e.SetPosition(x - .01f *((x - p1pos.x) / squared), y - .01f *((y - p1pos.y) / squared), z - .01f *((z - p1pos.z) / squared));
		tempvector.push_back(e);
	}
	vectorenemies.clear();
	for (Enemy e : tempvector)
		vectorenemies.push_back(e);
}

Map::~Map()
{
}
