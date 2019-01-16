#pragma once
#include <vector>
#include "GameObject.h"
#include <filesystem>
#include <string>
class ResourceManager
{
private:
	ResourceManager();
	~ResourceManager();
	std::vector <GameObject *> assets;
	static ResourceManager * ptr;
	void folderReader(std::string _path);
	void assetPusher(std::string _path, std::string _ext, int _type);
	
public:
	static ResourceManager*getPtr();
	void readContent(std::string _path);
	void createGameObject(std::string _name, int _type);
	void push(GameObject * _obj);
};

const std::string ResourceDir = "Resources";
const std::string SpritesDir = "Resources/Sprites";
const std::string SoundsDir = "Resources/Sounds";
const std::string ModelsDir = "Resources/Models";