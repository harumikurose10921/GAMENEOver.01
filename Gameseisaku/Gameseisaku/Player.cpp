#include "stdafx.h"
#include "Player.h"
#include "game.h"
#include "Animation.h"

Player::Player()
{

	direction.z = 1.0f;

}

Player::~Player()
{

}

void Player::Init()
{
	tRodi = 0.0f;
	moveDir = D3DXVECTOR3(0.0f, 15.0f, 0.0f);

	//���C�g������
	light.SetdiffuseLightDirection(0, D3DXVECTOR4(0.707f, 0.0f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(1, D3DXVECTOR4(-0.707f, 0.0f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(2, D3DXVECTOR4(0.0f, 0.707f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(3, D3DXVECTOR4(0.0f, -0.707f, -0.707f, 1.0f));

	light.SetdiffuseLightColor(0, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetdiffuseLightColor(1, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetdiffuseLightColor(2, D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));
	light.SetdiffuseLightColor(3, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetambientLight(D3DXVECTOR4(0.3f,0.3f, 0.3f, 1.0f));

	modeldata.LoadModelData("Assets/model/Querytyan.X",&animation);
	model.Init(&modeldata);
	model.SetLight(&light);

	//�L�����N�^�R���g���[�����������B
	characterController.Init(0.3f, 1.0f, pos);
	characterController.SetGravity(-10.0f);	//�d�͋��߁B

}

void Player::Update()
{
	
	float fMoveSpeed = 8.0f;
	moveSpeed = 0.0f;

	D3DXVECTOR3 toPos;
	toPos = game->GetCamera().GetLookatPt() - game->GetCamera().GetEyept();
	toPos.y = 0.0f;
	D3DXVec3Normalize(&toPos, &toPos);

	D3DXVECTOR3 toSide;   //������
	D3DXVec3Cross(&toSide, &toPos, &D3DXVECTOR3(0.0f, 1.0f,0.0f));
	D3DXVec3Normalize(&toSide, &toSide);

	/*animation.PlayAnimation(0);
	animation.Update(0.0166);*/
	//�O�ړ�
	if (GetAsyncKeyState('W')&0x8000){
		moveDir += toPos;
		moveSpeed = fMoveSpeed;
	}
	//��ړ�
	else if (GetAsyncKeyState('S') & 0x8000){
		moveDir -= toPos;
		moveSpeed = fMoveSpeed;
	}
	//���ړ�
	if (GetAsyncKeyState('A') & 0x8000){
		moveDir += toSide;
		moveSpeed = fMoveSpeed;
	}
	//�E�ړ�
	else if (GetAsyncKeyState('D') & 0x8000){
		moveDir -= toSide;
		moveSpeed = fMoveSpeed;
	}
	//����
	if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
		moveSpeed = fMoveSpeed * 2;
	}

	D3DXVec3Normalize(&moveDir, &moveDir);
	//�v���C���[���J�����̕����Ɍ������Đi�܂���
	c_movespeed = moveDir * moveSpeed;
	c_movespeed.y = characterController.GetMoveSpeed().y;

	//�n�ʂɂ���Ƃ��ɃW�����v
	if (characterController.IsOnGround()==true) 
	{
		if (GetAsyncKeyState(VK_SPACE) != 0) 
		{
			c_movespeed.y = 5.0f;
			characterController.Jump();
	   }
	}
	
	//�L�����N�^���������x��ݒ�B
	characterController.SetMoveSpeed(c_movespeed);
	//�L�����N�^�R���g���[���[�����s�B
	characterController.Execute();
	position = characterController.GetPosition();
	//���S
	if (position.y < -1.0f)
	{
		//�m�F�p
		MessageBox(NULL, "��������", "MesegeBox", NULL);
	}

	D3DXQUATERNION qRot;
	D3DXVECTOR3 vY(0.0f, 0.1f, 0.0f);
	D3DXQuaternionRotationAxis(&qRot, &vY, atan2f(moveDir.x,moveDir.z));

	model.UpdateWorldMatrix(position, qRot, D3DXVECTOR3(1.0f, 1.0f, 1.0f));
}

void Player::Render()
{
	//���f���`��
	model.Draw(&game->GetCamera().GetviewMatrix(),&game->GetCamera().GetprojectionMatrix());
}
