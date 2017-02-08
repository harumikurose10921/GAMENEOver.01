#pragma once

class C2DImage
{
public:
	C2DImage();
	~C2DImage();
	virtual void Init();
	virtual void Update() = 0;
	void Render(LPD3DXSPRITE);
	void SetupMatrices();
protected:
	D3DXVECTOR2 position;			//�ʒu���
	float angle;					//��]���
	D3DXVECTOR2 scale;			//�X�P�[�����
	LPDIRECT3DTEXTURE9 pTexture;	//�e�N�X�`��
	D3DCOLOR backColor;			//�w�i�J���[
	LPCTSTR texFileName;			//�e�N�X�`���t�@�C����
	D3DXVECTOR2 texCenter;		//�e�N�X�`���̒��_
	RECT rect;					//�`���`
	D3DXMATRIX transformMatrix;	//�ϊ��s��
};

