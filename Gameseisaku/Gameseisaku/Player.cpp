#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRotation);
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;

}

Player::~Player()
{

}

void Player::Init(LPDIRECT3DDEVICE9 pd3dDevice)
{
	model.Init(pd3dDevice, "Unity.x");
}

void Player::Update()
{
	D3DXMatrixTranslation(&mWorld, position.x, position.y, position.z);
}

void Player::Render(LPDIRECT3DDEVICE9 pd3dDevice,
	D3DXMATRIX viewMatrix,
	D3DXMATRIX projMatrix,
	D3DXVECTOR4* diffuseLightDirection,
	D3DXVECTOR4* diffuseLightColor,
	D3DXVECTOR4	 ambientLight,
	int numDiffuseLight)
{
	model.Render(
		pd3dDevice,
		mWorld,
		mRotation,
		viewMatrix,
		projMatrix,
		diffuseLightDirection,
		diffuseLightColor,
		ambientLight,
		numDiffuseLight);
}

void Player::SetPosition(D3DXVECTOR3 pos)
{
	position = pos;
}

void Player::Rerase()
{
	model.Release();
}