#include "stdafx.h"
#include "ground.h"
#include "game.h"

ground::ground()
{

}

ground::~ground(){

}

void ground::Init()
{
	position.x = 0.0f;
	position.y = 5.0f;
	position.z = 0.0f;

	//ƒ‰ƒCƒg‰Šú‰»
	light.SetdiffuseLightDirection(0, D3DXVECTOR4(0.707f, 0.0f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(1, D3DXVECTOR4(-0.707f, 0.0f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(2, D3DXVECTOR4(0.0f, 0.707f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(3, D3DXVECTOR4(0.0f, -0.707f, -0.707f, 1.0f));

	light.SetdiffuseLightColor(0, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetdiffuseLightColor(1, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetdiffuseLightColor(2, D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));
	light.SetdiffuseLightColor(3, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetambientLight(D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));

	modeldata.LoadModelData("Assets/model/court.x");
	model.Init(&modeldata);
	model.SetLight(&light);
}
void ground::Updeate()
{
	model.UpdateWorldMatrix(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR3(1.0f, -2.0f, 1.0f));
}

void ground::Render()
{
	model.Draw(&game->GetCamera().GetviewMatrix(), &game->GetCamera().GetprojectionMatrix());
}