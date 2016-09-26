#include "stdafx.h"
#include "Player.h"
#include "game.h"

Player::Player()
{

	direction.z = 1.0f;

}

Player::~Player()
{

}

void Player::Init()
{
	tRodi = 0.0f;
	position.x = 0.0f;
	position.y = 10.0f;
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

	modeldata.LoadModelData("Assets/model/Querytyan.X");
	model.Init(&modeldata);
	model.SetLight(&light);
}

void Player::Update()
{
	bool isTrun = false;
	if (GetAsyncKeyState('W')&0x8000){
		position.z += 0.05f;
		tRodi = D3DXToRadian(360);
		isTrun = true;
	}
	else if (GetAsyncKeyState('S') & 0x8000){
		position.z -= 0.05f;
		tRodi = D3DXToRadian(180);
		isTrun = true;
	}
	
	if (GetAsyncKeyState('A') & 0x8000){
		position.x -=  0.05;
		tRodi = D3DXToRadian(-90.0f);
	}
	else if (GetAsyncKeyState('D') & 0x8000){
		position.x += 0.05f;
		tRodi = D3DXToRadian(90.0f);
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000){
		position.y += 0.05f;
	}
	else if (GetAsyncKeyState('M')&0x8000){
		position.y -= 0.05f;
	}
	D3DXQUATERNION qRot;
	D3DXVECTOR3 vY(0.0f, 0.1f, 0.0f);
	D3DXQuaternionRotationAxis(&qRot, &vY, tRodi);

	model.UpdateWorldMatrix(position, qRot, D3DXVECTOR3(1.0f, 1.0f, 1.0f));
}

void Player::Render()
{
	//ƒ‚ƒfƒ‹•`‰æ
	model.Draw(&game->GetCamera().GetviewMatrix(),&game->GetCamera().GetprojectionMatrix());
}

