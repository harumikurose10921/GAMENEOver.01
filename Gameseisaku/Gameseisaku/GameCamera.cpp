#include"stdafx.h"
#include"GameCamera.h"
#include"Player.h"

GameCamera  *gamecamera;

void GameCamera::SetLookatPt(D3DXVECTOR3 pt)
{
	vLookatPt = pt;
}
//’Ž‹“X‚ÌƒQƒbƒ^[
D3DXVECTOR3 GameCamera::GetLookatPt()
{
	return vLookatPt;
}

GameCamera::GameCamera() :
player(nullptr)
{

}

GameCamera::~GameCamera()
{

}

void GameCamera::Init(Player* player)
{

	camera.SetPosition(D3DXVECTOR3(0.0f, 0.8, 3.0));
	camera.SetEyept(D3DXVECTOR3(0.0f, 10.0f, -8.0f));
	camera.SetLookatPt(D3DXVECTOR3(0.0f, 10.0f, -8.0f));
	camera.SetUpvec(D3DXVECTOR3(0.0f, 15.0f, 0.0f));
	toPos = camera.GetEyept() - camera.GetLookatPt();
	this->player = player;
	Update();
}

void GameCamera::Update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		camera.CameraRo(-0.05f);
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		camera.CameraRo(0.05f);
	}
}