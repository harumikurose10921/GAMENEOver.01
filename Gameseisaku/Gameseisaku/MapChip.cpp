#include"stdafx.h"
#include"MapChip.h"
#include "game.h"


MapChip::MapChip(){

}
MapChip::~MapChip(){

	game->GetPhysicsWorld()->RemoveRigidBody(&rigidBody);
}

void MapChip::Init(const char*name,D3DXVECTOR3 pos,D3DXQUATERNION rot,D3DXVECTOR3 sc)
{
	sc.x *= -1;
	//まずはスキンモデルをロード。
	char modelPath[256];
	sprintf(modelPath, "Assets/model/%s.X",name);
	skinmodelData.LoadModelData(modelPath,NULL);
	
	skinModel.Init(&skinmodelData);
	skinModel.SetLight(&light);
	skinModel.UpdateWorldMatrix(pos, rot, sc/*D3DXVECTOR3(1.0f, 1.0f, 1.0f)*/);
	//スキンモデルからメッシュコライダーを作成する。
	D3DXMATRIX* rootBoneMatrix = skinmodelData.GetRootBoneMatrix();
	meshCollider.CreateFromSkinModel(&skinModel, rootBoneMatrix);
	position = pos;
	rotation = rot;
	scale = sc;
	//剛体を作成するための情報を設定。
	RigidBodyInfo rbInfo;
	rbInfo.collider = &meshCollider;
	rbInfo.mass = 0.0f;					//質量を0にすると動かない剛体になる。
	rbInfo.pos = position;
	rbInfo.rot = rotation;
	//剛体を作成。
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
	//skinModel.UpdateWorldMatrix(position, D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
}

void MapChip::Render()
{
	skinModel.Draw(&game->GetCamera().GetviewMatrix(), &game->GetCamera().GetprojectionMatrix());
}

void MapChip::SetPos(D3DXVECTOR3 pos)
{
	position = pos;
}