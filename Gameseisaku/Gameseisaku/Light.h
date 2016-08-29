#pragma once

class Light
{
public:
	static const int LIGHT_NUM = 4;
	Light(){
		memset(this, 0, sizeof(Light));
	}
	~Light(){
	
	}
	const D3DXVECTOR4* GetdiffuseLightDirection() const
	{
		return diffuseLightDirection;
	}

	const D3DXVECTOR4* GetdiffuseLightColor() const
	{
		return diffuseLightColor;
	}

	void SetdiffuseLightDirection(int lightNo,const D3DXVECTOR4& dir)
	{
		diffuseLightDirection[lightNo] = dir;
	}
	void SetdiffuseLightColor(int lightNo, const D3DXVECTOR4& color)
	{
		diffuseLightColor[lightNo] = color;
	}
	void SetambientLight(const D3DXVECTOR4& ambient)
	{
		ambientLight = ambient;
	}
	void UpLight();
private:
	D3DXVECTOR4 			diffuseLightDirection[LIGHT_NUM];	//ライトの方向。
	D3DXVECTOR4				diffuseLightColor[LIGHT_NUM];		//ライトの色。
	D3DXVECTOR4				ambientLight;	//環境光

};