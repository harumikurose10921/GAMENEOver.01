#pragma once
#include"MeshCollider.h"

class ground
{
public:
	ground();
	~ground(); 
	void Init();
	void Updeate();
	void Render();
	//�n�ʂƂ̂����蔻��B
	//pos  ���C�̎n�_�B
	//ray	���C�����B
	//bHit	���C�ƒn�ʂ��Փ˂�����1���ݒ肳���B
	//len	���C�̎n�_�����_�܂ł̋����B
	void IsIntersect(const D3DXVECTOR3& pos, const D3DXVECTOR3& ray, int& bHit, float& len);
	void Setposition(D3DXVECTOR3 pos){
		position = pos;
	}
private:
	D3DXVECTOR3 position;
	D3DXMATRIX*  mWorld;//���[���h�s��
	D3DXMATRIX  mRotation;
	SkinModel model;		//�X�L�����f��
	SkinModelData modeldata;
	Light light;
	MeshCollider meshcollider;//���b�V���R���C�_�[
	

};