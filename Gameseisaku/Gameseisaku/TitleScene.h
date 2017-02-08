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
	HRESULT CreateSprite();	//�X�v���C�g�����֐�

private:
	LPD3DXSPRITE m_pSprite;			//�X�v���C�g
	CTitle title;					//�^�C�g��
	Camera camera;
	Light light;
};

extern CTitleScene g_titlescene;