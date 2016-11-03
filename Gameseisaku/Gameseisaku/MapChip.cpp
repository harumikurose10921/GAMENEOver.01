#include"stdafx.h"
#include"MapChip.h"
#include "game.h"


MapChip::MapChip(){

}
MapChip::~MapChip(){

	game->GetPhysicsWorld()->RemoveRigidBody(&rigidBody);
}

void MapChip::Init(const char*name)
{

	//�܂��̓X�L�����f�������[�h�B
	char modelPath[256];
	sprintf(modelPath, "Assets/model/%s.X",name);
	skinmodelData.LoadModelData(modelPath,NULL);
		D3DXMATRIX mTrans;
		SetPos(position);
		position = position*0.38f;
		D3DXMatrixTranslation(&mTrans, position.x,position.y,position.z);
		D3DXMATRIX mRot;
		D3DXQUATERNION rotation;
		D3DXMatrixRotationQuaternion(&mRot, &rotation);
	skinModel.Init(&skinmodelData);
	skinModel.SetLight(&light);
	skinModel.UpdateWorldMatrix(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR3(1.0f, -2.0f, 1.0f));
	//�X�L�����f�����烁�b�V���R���C�_�[���쐬����B
	D3DXMATRIX* rootBoneMatrix = skinmodelData.GetRootBoneMatrix();
	meshCollider.CreateFromSkinModel(&skinModel, rootBoneMatrix);
	//���̂��쐬���邽�߂̏���ݒ�B
	RigidBodyInfo rbInfo;
	rbInfo.collider = &meshCollider;
	rbInfo.mass = 0.0f;					//���ʂ�0�ɂ���Ɠ����Ȃ����̂ɂȂ�B
	rbInfo.pos = position;
	rbInfo.rot = rotation;
	//���̂��쐬�B
	rigidBody.Create(rbInfo);
	game->GetPhysicsWorld()->AddRigidBody(&rigidBody);
	//meshCollider.CreateFromSkinModel(&skinModel, skinmodelData.GetRootBoneMatrix());

	light.SetdiffuseLightDirection(0, D3DXVECTOR4(0.707f, 0.0f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(1, D3DXVECTOR4(-0.707f, 0.0f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(2, D3DXVECTOR4(0.0f, 0.707f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(3, D3DXVECTOR4(0.0f, -0.707f, -0.707f, 1.0f));

	light.SetdiffuseLightColor(0, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetdiffuseLightColor(1, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetdiffuseLightColor(2, D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));
	light.SetdiffuseLightColor(3, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetambientLight(D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));
	
}

void MapChip::Start()
{

}

void MapChip::Update()
{
	skinModel.UpdateWorldMatrix(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR3(1.0f, -2.0f, 1.0f));
}

void MapChip::Render()
{
	skinModel.Draw(&game->GetCamera().GetviewMatrix(), &game->GetCamera().GetprojectionMatrix());
}

void MapChip::SetPos(D3DXVECTOR3 pos)
{
	position = pos;
}