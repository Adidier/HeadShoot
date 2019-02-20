#include "EnemyListMovement.h"

EnemyListMovement::EnemyListMovement(){
	monkey = new Mesh("./Resources/Models/testBoxNoUV.obj");
	shader = new Shader("./Resources/Shaders/basicShader");
	texture = new Texture("./Resources/Sprites/bricks.jpg");
}

void EnemyListMovement::SetPosition(float x, float y, float z){
	transform.GetPos()->x = x;
	transform.GetPos()->y = y;
	transform.GetPos()->z = z;
}

void EnemyListMovement::AddEnemyNode(float x, float y, float z) {
	Transform EnemyNode;
	EnemyNode.GetPos()->x = x;
	EnemyNode.GetPos()->y = y;
	EnemyNode.GetPos()->z = z;
	nodelist.Append(EnemyNode);
}

float EnemyListMovement::GetXPosition(){
	return transform.GetPos()->x;
}

float EnemyListMovement::GetYPosition(){
	return transform.GetPos()->y;
}

float EnemyListMovement::GetZPosition(){
	return transform.GetPos()->z;
}

float EnemyListMovement::GetNodeXPosition() {
	return 1.0f;
}

float EnemyListMovement::GetNodeYPosition() {
	return 1.0f;
}

float EnemyListMovement::GetNodeZPosition() {
	return 1.0f;
}

void EnemyListMovement::Draw(const Camera &camera){
	transform.GetRot()->y = 100;
	shader->Bind();
	texture->Bind();
	shader->Update(transform, camera);
	monkey->Draw();
}

EnemyListMovement::~EnemyListMovement(){
}