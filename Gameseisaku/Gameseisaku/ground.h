#pragma once

class ground
{
public:
	ground();
	~ground(); 
	void Init();
	void Updeate();
	void Render();
	void Setposition(D3DXVECTOR3 pos){
		position = pos;
	}
private:
	D3DXVECTOR3 position;
	D3DXMATRIX  mWorld;
	D3DXMATRIX  mRotation;
	SkinModel model;
	SkinModelData modeldata;
	Light light;
};