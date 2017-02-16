#pragma once
//�p�[�e�B�N���̔����@�B
#ifndef  _PARTICLEEMITTER_H_
#define	 _PARICLEEMITTER_H_


class Particle;
//�p�[�e�B�N�������p�����[�^�[
struct SParicleEmitParameter {
	//������
	void Init()
	{
		memset(this, 0, sizeof(SParicleEmitParameter));
	}
	const char* texturePath; //�e�N�X�`���̃t�@�C���p�X�B
	float w;//�p�[�e�B�N���̕��B
	float h;//�p�[�e�B�N���̍����B
	float intervalTime;//�p�[�e�B�N���̔����Ԋu�B
	D3DXVECTOR3 initSpeed;//�����x
};

class ParticleEmiter 
{
public:
//�R���X�g���N�^
	ParticleEmiter();
	//�f�X�g���N�^
	~ParticleEmiter();
	//������
	//param[in]	camera	�p�[�e�B�N���̕`��Ŏg�p���邩�߂�
	//param[in]	param
	void Init(const SParicleEmitParameter&param);//�p�����[�^�B
	void Updeate();
	void Render(const D3DXMATRIX&viewMaatrix, const D3DXMATRIX&projMatrix);
private:
	SParicleEmitParameter param;          //�p�����[�^�B
	std::list<Particle*> particleList;
	float timer;                          //�^�C�}�[
};
#endif // ! _PARTICLEEMITTER_H_
