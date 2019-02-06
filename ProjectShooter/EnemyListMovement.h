#pragma once
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "./Utilities/LinkedList.h"
#include "Utilities/LinkedList.h"

class EnemyListMovement
{
private:
	Mesh * monkey;
	Shader *shader;
	Texture *texture;
	Transform transform;
	LinkedList<Transform> nodelist;
	
public:
	void Draw(const Camera &camera);
	void SetPosition(float x, float y, float z);
	void AddEnemyNode(float x, float y, float z);

	float GetNodeXPosition();
	float GetNodeYPosition();
	float GetNodeZPosition();
	float GetXPosition();
	float GetYPosition();
	float GetZPosition();
	EnemyListMovement();
	~EnemyListMovement();
};