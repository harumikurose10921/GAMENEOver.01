#include "stdafx.h"
#include "Camera.h"
#include"Player.h"

//�R���X�g���N�^
Camera::Camera()
{
	Near = 0.1f;
	Far = 100.0f;
	aspect = 1.0f;
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;
	
	
}
//�f�X�g���N�^
Camera::~Camera()
{
}
//�A�X�y�N�g��̃Z�b�^�[
void Camera::SetAspect(float _aspect)
{
	aspect = _aspect;
}
//�A�X�y�N�g��̃Q�b�^�[
float Camera::GetAspect()
{
	return aspect;
}
//�t�@�[�̃Z�b�^�[
void Camera::SetFar(float _far)
{
	Far = _far;
}
//�t�@�[�̃Q�b�^�[
float Camera::GetFar()
{
	return Far;
}
//���_�̂��Z�b�^�[
void Camera::SetEyept(D3DXVECTOR3 pt)
{
	vEyePt = pt;
}
//���_�̃Q�b�^�[
D3DXVECTOR3 Camera::GetEyept()
{
	return vEyePt;
}
//�ɂ��[�̃Z�b�^�[
void Camera::SetNear(float _near)
{
	Near = _near;
}
//�ɂ��[�̃Q�b�^�[
float Camera::GetNear()
{
	return Near;
}
//������̃Z�b�^�[
void Camera::SetUpvec(D3DXVECTOR3 up)
{
	vUpVec = up;
}
//������̃Q�b�^�[
D3DXVECTOR3 Camera::GetUpVec()
{
	return vUpVec;
}
//�����_�̃Z�b�^�[
void Camera:: SetLookatPt(D3DXVECTOR3 pt)
{
	vLookatPt = pt;
}
//�����X�̃Q�b�^�[
D3DXVECTOR3 Camera::GetLookatPt()
{
	return vLookatPt;
}

void Camera::SetviewMatrix(D3DXMATRIX mview)
{
	viewMatrix = mview;
}
D3DXMATRIX Camera::GetviewMatrix()
{
	return viewMatrix;
}

void Camera::SetprojectionMatrix(D3DXMATRIX proj)
{
	projectionMatrix = proj;
}
D3DXMATRIX Camera::GetprojectionMatrix()
{
	return projectionMatrix;
}

void Camera::Init(Player* player)
{
	SetPosition(D3DXVECTOR3(0.0f, 0.8, 3.0));
	vEyePt = D3DXVECTOR3(0.0f, 10.0f, -5.0f);
	vLookatPt = D3DXVECTOR3(0.0f, 7.0f,0.0f);
	vUpVec = D3DXVECTOR3(0.0f, 15.0f, 0.0f);
	toPos = GetEyept() - GetLookatPt();
	this->player = player;
	Update();
}

void Camera::Update()
{
	
	
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		CameraRo(0.05f);
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		CameraRo(-0.05f);
	}

	D3DXMatrixLookAtLH(&viewMatrix, &vEyePt, &vLookatPt, &vUpVec);
	D3DXMatrixPerspectiveFovLH(&projectionMatrix, D3DX_PI / 4, aspect, Near, Far);
	SetLookatPt(player->GetPosition());
	//SetEyept(player->GetPosition() + toPos);
	SetPosition(vEyePt);\
}

void Camera::CameraRo(float vF)
{
	toPos = GetEyept() - GetLookatPt();
	D3DXMatrixRotationY(&Rot, vF);
	D3DXVec3Transform(&OutPos, &toPos, &Rot);
	cameraPos.x = GetLookatPt().x + OutPos.x;
	cameraPos.y = GetLookatPt().y + OutPos.y;
	cameraPos.z = GetLookatPt().z + OutPos.z;
	SetEyept(cameraPos);
}