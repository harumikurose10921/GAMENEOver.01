#pragma once
#include "Model.h"
class Player
{
public:
	Player();
	~Player();
	void Init(LPDIRECT3DDEVICE9 pd3dDevice);
	void Update();
	void Render(LPDIRECT3DDEVICE9 pd3dDevice,
		D3DXMATRIX viewMatrix,
		D3DXMATRIX projMatrix,
		D3DXVECTOR4* diffuseLightDirection,
		D3DXVECTOR4* diffuseLightColor,
		D3DXVECTOR4	 ambientLight,
		int numDiffuseLight);
	void Rerase();
	void SetPosition(D3DXVECTOR3 pos);
private:
	D3DXVECTOR3 position;
	D3DXMATRIX  mWorld;
	D3DXMATRIX  mRotation;
	Model       model;
};