#pragma once
//�p�[�e�B�N��
#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "Primitive.h"
struct SParticleEmitParameter;

//�p�[�e�B�N���B
class Particle {
public:

private:
	Primitive primitive;//�v���~�e�B�u�B
	LPDIRECT3DTEXTURE9 texture;//�e�N�X�`���B
	ID3DXEffect* shaderEffect;//�V�F�[�_�[�G�t�F�N�g�B
	D3DXVECTOR3 moveSpeed;//���x�B
	D3DXVECTOR3 position;//���W�B
public:
	Particle();
	~Particle();
	void Init(const SParicleEmitParameter& param);
	void Updeate();
	void Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix);
};
#endif //_PARTICLE_H_
