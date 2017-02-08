#pragma once 
#include "Title.h"
#include "Camera.h"
#include "Light.h"

class CTitleScene
{
public:
	CTitleScene(){}
	~CTitleScene(){}
	void Init();
	void Update();
	void Render();
	HRESULT CreateSprite();	//スプライト生成関数

private:
	LPD3DXSPRITE m_pSprite;			//スプライト
	CTitle title;					//タイトル
	Camera camera;
	Light light;
};

extern CTitleScene g_titlescene;