#pragma once
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "Utilities\LinkedList.h"


class Enemy
{
private:
	Mesh * monkey;
	Shader *shader;
	Texture *texture;
	Transform transform;
	LinkedList<Transform> *path;
public:
	void Draw(const Camera &camera);
	void SetPosition(float x, float y, float z);
	float GetXPosition();
	float GetYPosition();
	float GetZPosition();
	Enemy();
	~Enemy();
};