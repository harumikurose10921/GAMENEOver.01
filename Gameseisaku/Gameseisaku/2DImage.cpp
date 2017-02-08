//�e�N�X�`���̓ǂݍ��݁E�摜�\��

#include "stdafx.h"
#include "2DImage.h"


C2DImage::C2DImage()
{
}


C2DImage::~C2DImage()
{
}

void C2DImage::Init()
{
	D3DXIMAGE_INFO imgInfo;										//�摜���i�[�p�\����
	D3DXCreateTextureFromFileEx(g_pd3dDevice, this->texFileName, 0, 0, 0, 0, D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_DEFAULT, 0, &imgInfo, NULL, &this->pTexture);	//�e�N�X�`���Ǎ�
	this->texCenter = D3DXVECTOR2((float)imgInfo.Width / 2, (float)imgInfo.Height / 2);	//�e�N�X�`���̒��_�Z�b�g
	RECT rec = { 0, 0, imgInfo.Width, imgInfo.Height };			//�`��̈�
	memcpy(&this->rect, &rec, sizeof(RECT));					//�`��̈�Z�b�g
}

void C2DImage::Render(LPD3DXSPRITE pSprite)
{
	pSprite->Begin(D3DXSPRITE_ALPHABLEND);		//�X�v���C�g�`��J�n
	pSprite->SetTransform(&this->transformMatrix);	//�ϊ��s��Z�b�g
	pSprite->Draw(this->pTexture, &this->rect, &D3DXVECTOR3(this->texCenter.x, this->texCenter.y, 0.0f), NULL, this->backColor);	//�X�v���C�g�Ƀe�N�X�`���\�t��
	pSprite->End();	//�X�v���C�g�`��I��
}

void C2DImage::SetupMatrices()
{
	D3DXMatrixIdentity(&this->transformMatrix);	//���[���h�s�񏉊���
	D3DXMatrixTransformation2D(&this->transformMatrix, NULL, 0.0f, &this->scale, NULL, D3DXToRadian(this->angle), &this->position);	//�ϊ��s��쐬
}