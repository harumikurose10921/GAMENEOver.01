#pragma once

class Sky
{
public:
	Sky();

	~Sky()
	{

	}
	void Start()
	{

	}
	void Update();

	void Render();
private:
	D3DXVECTOR3 position;
	D3DXMATRIX  mWorld;
	D3DXMATRIX  mRotation;
	SkinModel model;
	SkinModelData modeldata;
	Light light;
};