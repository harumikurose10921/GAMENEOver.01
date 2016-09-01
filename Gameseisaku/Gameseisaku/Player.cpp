#include "stdafx.h"
#include "Player.h"
#include "game.h"

Player::Player()
{
		

}

Player::~Player()
{

}

void Player::Init()
{

	//ライト初期化
	light.SetdiffuseLightDirection(0, D3DXVECTOR4(0.707f, 0.0f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(1, D3DXVECTOR4(-0.707f, 0.0f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(2, D3DXVECTOR4(0.0f, 0.707f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(3, D3DXVECTOR4(0.0f, -0.707f, -0.707f, 1.0f));

	light.SetdiffuseLightColor(0, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetdiffuseLightColor(1, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetdiffuseLightColor(2, D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));
	light.SetdiffuseLightColor(3, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetambientLight(D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));

	modeldata.LoadModelData("Assets/model/Unity.x");
	model.Init(&modeldata);
	model.SetLight(&light);
}

void Player::Update()
{
	
	if (GetAsyncKeyState('W')&0x8000){
		position.z += 1.5f;
	}
	else if (GetAsyncKeyState('S') & 0x8000){
		position.z -= 1.5f;
	}

	/*else if (GetAsyncKeyState('A') & 0x800){
		position.x -= 0.5f;
	}
	else if (GetAsyncKeyState('D') & 0x800){
		position.x += 0.5f;
	}*/

	model.UpdateWorldMatrix(position, D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
}

void Player::Render()
{
	//モデル描画
	model.Draw(&game->GetCamera().GetviewMatrix(),&game->GetCamera().GetprojectionMatrix());
}

void Player::SetPosition(D3DXVECTOR3 pos)
{
	position = pos;
}

