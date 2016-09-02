#pragma once
#include "turn.h"
class Game;
class Player
{
public:
	Player();
	~Player();
	void Init();
	void Update();
	void Render();
	void Rerase();
	void SetPosition(D3DXVECTOR3 pos);
	
private:
	D3DXVECTOR3 position;
	D3DXMATRIX  mWorld;
	D3DXMATRIX  mRotation;
	//Camera camera;
	SkinModel model;
	SkinModelData modeldata;
	Light light;
	Trun trun;
	
	float tRodi;
};
