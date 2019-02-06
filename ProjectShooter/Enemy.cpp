#include "Enemy.h"




Enemy::Enemy()
{
	path = new LinkedList<Transform>();
	monkey = new Mesh("./Resources/Models/MagmaElemental.obj");
	shader = new Shader("./Resources/Shaders/basicShader");
	texture = new Texture("./Resources/Sprites/bricks.jpg");
}

void Enemy::SetPosition(float x, float y, float z)
{
	transform.GetPos()->x = x;
	transform.GetPos()->y = y;
	transform.GetPos()->z = z;
}

float Enemy::GetXPosition()
{
	return transform.GetPos()->x;
}

float Enemy::GetYPosition()
{
	return transform.GetPos()->y;
}

float Enemy::GetZPosition()
{
	return transform.GetPos()->z;
}

void Enemy::Draw(const Camera &camera)
{


	transform.GetRot()->y =  100;

	shader->Bind();
	texture->Bind();

	shader->Update(transform, camera);
	monkey->Draw();

//	counter -= 0.00001f;




}

Enemy::~Enemy()
{
}
