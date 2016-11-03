#include "stdafx.h"
#include "ground.h"
#include "game.h"

ground::ground()
{

}

ground::~ground(){

}

void ground::Init()
{
	position.x = 0.0f;
	position.y = 5.0f;
	position.z = 0.0f;

	//ライト初期化
	light.SetdiffuseLightDirection(0, D3DXVECTOR4(0.707f, 0.0f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(1, D3DXVECTOR4(-0.707f, 0.0f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(2, D3DXVECTOR4(0.0f, 0.707f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(3, D3DXVECTOR4(0.0f, -0.707f, -0.707f, 1.0f));

	light.SetdiffuseLightColor(0, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetdiffuseLightColor(1, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetdiffuseLightColor(2, D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));
	light.SetdiffuseLightColor(3, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetambientLight(D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));

	modeldata.LoadModelData("Assets/model/court.x",NULL);
	model.Init(&modeldata);
	model.SetLight(&light);
	model.GetOrgMeshFirst();
	mWorld = model.FindBoneWorldMatrix("court.x");
	//メッシュコライダーを作成。
	//meshcollider.CreateFromSkinModel(&model, mWorld);

}
void ground::Updeate()
{
	model.UpdateWorldMatrix(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR3(1.0f, -2.0f, 1.0f));
}

void ground::Render()
{
	model.Draw(&game->GetCamera().GetviewMatrix(), &game->GetCamera().GetprojectionMatrix());
}

void ground::IsIntersect(const D3DXVECTOR3& pos,const D3DXVECTOR3& ray,int& bHit,float& len )
{
	D3DXMATRIX mWorldInv;
	D3DXMatrixMultiply(&mWorldInv, &mWorldInv, mWorld);
	D3DXVECTOR3 posInGround = pos;
	D3DXVec3TransformCoord(&posInGround, &posInGround, &mWorldInv);
	D3DXVECTOR3 rayInGround = ray;
	D3DXVec3TransformCoord(&rayInGround, &rayInGround, &mWorldInv);
	HRESULT hr = D3DXIntersect(
		model.GetOrgMeshFirst(),
		(const D3DXVECTOR3*)&posInGround,
		(const D3DXVECTOR3*)&rayInGround,
		&bHit,
		NULL,
		NULL,
		NULL,
		&len,
		NULL,
		NULL
		);
	
}