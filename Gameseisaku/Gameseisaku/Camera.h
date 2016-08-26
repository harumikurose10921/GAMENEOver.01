#pragma once

class Camera
{
public:
	Camera();
	~Camera();
	//������̐ݒ�
	void SetUpvec(D3DXVECTOR3 up);
	//������̎擾
	D3DXVECTOR3 GetUpVec();
	//�r���[�s��
	void SetviewMatrix(D3DXMATRIX mview);
	//�r���[�s��̎擾
	D3DXMATRIX GetviewMatrix();
	//�v���W�F�N�V�����s��̐ݒ�
	void SetprojectionMatrix(D3DXMATRIX proj);
	//�v���W�F�N�V�����s��̎擾
	D3DXMATRIX GetprojectionMatrix();
	//�A�X�y�N�g���ݒ�
	void SetAspect(float _aspect);
	//�A�X�y�N�g����擾
	float GetAspect();
	//�t�@�[�����ݒ�
	void SetFar(float _far);
	//�t�@�[���擾
	float GetFar();
	//�j�A��ݒ�
	void SetNear(float _Near);
	//�j�A���擾
	float GetNear();
	//���_��ݒ�
	void SetEyept(D3DXVECTOR3 pt);
	//���_���擾
	D3DXVECTOR3 GetEyept();
	//�����_��ݒ�
	void SetLookatPt(D3DXVECTOR3 pt);
	//�����_�����擾
	D3DXVECTOR3 GetLookatPt();

	void Init();
	void Update();
private:
	D3DXMATRIX				viewMatrix;			//!<�r���[�s��B
	D3DXMATRIX				projectionMatrix;	//!<�v���W�F�N�V�����s��B
	D3DXVECTOR3				vEyePt;				//!�J�����̎��_�B
	D3DXVECTOR3				vLookatPt;			//!�J�����̒����_�B�ǂ������Ă��邩�Ƃ������B
	D3DXVECTOR3				vUpVec;				//!�J�����̏�����B
	float					Far;				//!<�����ʁB
	float					Near;				//!<�ߕ��ʁB
	float					aspect;				//!<�A�X�y�N�g��
};