#pragma once
#include "turn.h"
class Game;
class Player
{
public:
	void SetPosition(D3DXVECTOR3 pos)
	{
		position = pos;
	}
	D3DXVECTOR3 GetPosition()
	{
		return position;
	}
	//Œü‚«‚ÌŽæ“¾
	D3DXVECTOR3& GetDirection(){
		return direction;
	}

	Player();
	~Player();
	void Init();
	void Update();
	void Render();
	void Rerase();
	
	
private:
	D3DXVECTOR3 position;
	D3DXMATRIX  mWorld;
	D3DXMATRIX  mRotation;
	SkinModel model;
	SkinModelData modeldata;
	Light light;
	Trun trun;
	D3DXVECTOR3 direction;//Œü‚«
	float tRodi;
};