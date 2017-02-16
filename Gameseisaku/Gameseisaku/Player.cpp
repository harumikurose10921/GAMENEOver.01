#include "stdafx.h"
#include "Player.h"
#include "game.h"
#include "Animation.h"

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
	moveDir = D3DXVECTOR3(0.0f, 15.0f, 0.0f);

	//ライト初期化
	light.SetdiffuseLightDirection(0, D3DXVECTOR4(0.707f, 0.0f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(1, D3DXVECTOR4(-0.707f, 0.0f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(2, D3DXVECTOR4(0.0f, 0.707f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(3, D3DXVECTOR4(0.0f, -0.707f, -0.707f, 1.0f));

	light.SetdiffuseLightColor(0, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetdiffuseLightColor(1, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetdiffuseLightColor(2, D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));
	light.SetdiffuseLightColor(3, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetambientLight(D3DXVECTOR4(0.3f,0.3f, 0.3f, 1.0f));

	modeldata.LoadModelData("Assets/model/Querytyan.X",&animation);
	model.Init(&modeldata);
	model.SetLight(&light);

	//キャラクタコントローラを初期化。
	characterController.Init(0.3f, 1.0f, pos);
	characterController.SetGravity(-10.0f);	//重力強め。

}

void Player::Update()
{
	
	float fMoveSpeed = 8.0f;
	moveSpeed = 0.0f;

	D3DXVECTOR3 toPos;
	toPos = game->GetCamera().GetLookatPt() - game->GetCamera().GetEyept();
	toPos.y = 0.0f;
	D3DXVec3Normalize(&toPos, &toPos);

	D3DXVECTOR3 toSide;   //横方向
	D3DXVec3Cross(&toSide, &toPos, &D3DXVECTOR3(0.0f, 1.0f,0.0f));
	D3DXVec3Normalize(&toSide, &toSide);

	/*animation.PlayAnimation(0);
	animation.Update(0.0166);*/
	//前移動
	if (GetAsyncKeyState('W')&0x8000){
		moveDir += toPos;
		moveSpeed = fMoveSpeed;
	}
	//後移動
	else if (GetAsyncKeyState('S') & 0x8000){
		moveDir -= toPos;
		moveSpeed = fMoveSpeed;
	}
	//左移動
	if (GetAsyncKeyState('A') & 0x8000){
		moveDir += toSide;
		moveSpeed = fMoveSpeed;
	}
	//右移動
	else if (GetAsyncKeyState('D') & 0x8000){
		moveDir -= toSide;
		moveSpeed = fMoveSpeed;
	}
	//加速
	if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
		moveSpeed = fMoveSpeed * 2;
	}

	D3DXVec3Normalize(&moveDir, &moveDir);
	//プレイヤーをカメラの方向に向かって進ませる
	c_movespeed = moveDir * moveSpeed;
	c_movespeed.y = characterController.GetMoveSpeed().y;

	//地面にいるときにジャンプ
	if (characterController.IsOnGround()==true) 
	{
		if (GetAsyncKeyState(VK_SPACE) != 0) 
		{
			c_movespeed.y = 5.0f;
			characterController.Jump();
	   }
	}
	
	//キャラクタが動く速度を設定。
	characterController.SetMoveSpeed(c_movespeed);
	//キャラクタコントローラーを実行。
	characterController.Execute();
	position = characterController.GetPosition();
	//死亡
	if (position.y < -1.0f)
	{
		//確認用
		MessageBox(NULL, "落ちたよ", "MesegeBox", NULL);
	}

	D3DXQUATERNION qRot;
	D3DXVECTOR3 vY(0.0f, 0.1f, 0.0f);
	D3DXQuaternionRotationAxis(&qRot, &vY, atan2f(moveDir.x,moveDir.z));

	model.UpdateWorldMatrix(position, qRot, D3DXVECTOR3(1.0f, 1.0f, 1.0f));
}

void Player::Render()
{
	//モデル描画
	model.Draw(&game->GetCamera().GetviewMatrix(),&game->GetCamera().GetprojectionMatrix());
}
