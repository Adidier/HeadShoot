#pragma once
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "Utilities/LinkedList.h"

class EnemyListMovement
{
private:
	Mesh * monkey;
	Shader *shader;
	Texture *texture;
	Transform transform;
	float Positions[2];
	//LinkedList<float&> nodelist;
public:
	void Draw(const Camera &camera);
	void SetPosition(float x, float y, float z);
	float GetXPosition();
	float GetYPosition();
	float GetZPosition();
	EnemyListMovement();
	~EnemyListMovement();
};

