#pragma once

#include "RenderTarget.h"

class Bloom {
public:
	/*!
	* @brief	�R���X�g���N�^�B
	*/
	Bloom();
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	~Bloom();
	void Render();
	//�d�݂̍X�V�B
	void UpdateWeight(float dispersion);
private:
	LPD3DXEFFECT effect;						//�V�F�[�_�[�G�t�F�N�g
	RenderTarget luminanceRenderTarget;			//�P�x�𒊏o���邽�߂̃����_�����O�^�[�Q�b�g�B
	RenderTarget downSamplingRenderTarget[2];	//�u���[�������邽�߂̃_�E���T���v�����O�p�̃����_�����O�^�[�Q�b�g�B
	static const int NUM_WEIGHTS = 8;			//�K�E�X�u���[�̏d�݁B
	float weights[NUM_WEIGHTS];					//�K�E�X�u���[�Ŏg���d�݃e�[�u���B
};