#pragma once
//#include "turn.h"
#include "CharacterController.h"


class Game;
class Animation;
class Player
{
public:
	void SetPosition(D3DXVECTOR3 pos)
	{
	   position = pos;
	}
	
	D3DXVECTOR3 GetPosition()
	{
		return characterController.GetPosition();
	}
	//向きの取得
	D3DXVECTOR3& GetDirection(){
		return direction;
	}

	Player();
	~Player();
	void Init();
	void Update();
	void Render();
	void Rerase();
	void Rot();
	
private:

	D3DXVECTOR3 position;
	D3DXMATRIX  mWorld;
	D3DXMATRIX  mRotation;
	SkinModel model;
	SkinModelData modeldata;
	Light light;
	//Trun trun;
	D3DXVECTOR3 direction;//向き
	Animation animation;
	float tRodi;
	D3DXVECTOR3 moveDir;//動く方向
	D3DXVECTOR3 c_movespeed;
    float       moveSpeed;
	D3DXVECTOR3 pos = D3DXVECTOR3(3.0f, 38.0f, 0.0f);
	CharacterController characterController;//キャラクターコントローラー
	//bool des;
	
};