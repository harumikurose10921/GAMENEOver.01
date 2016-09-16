#include"stdafx.h"
#include"GameCamera.h"
#include"Player.h"

GameCamera  *gamecamera;

GameCamera::GameCamera() :
player(nullptr)
{

}

GameCamera::~GameCamera()
{

}

void GameCamera::Init()
{
	camera.SetPosition(D3DXVECTOR3(0.0f, 0.8f, 3.0f));
	
}