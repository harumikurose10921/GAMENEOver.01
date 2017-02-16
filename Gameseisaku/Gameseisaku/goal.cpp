#include "stdafx.h"
#include "goal.h"
#include "Player.h"

Goal::Goal()
{

}
Goal::~Goal()
{

}
void Goal::Init()
{
	position.x = 98.0f;
	position.y = 3.5f;
	position.z = 5.0f;
	//ライト初期化
	light.SetdiffuseLightDirection(0, D3DXVECTOR4(0.707f, 0.0f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(1, D3DXVECTOR4(-0.707f, 0.0f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(2, D3DXVECTOR4(0.0f, 0.707f, -0.707f, 1.0f));
	light.SetdiffuseLightDirection(3, D3DXVECTOR4(0.0f, -0.707f, -0.707f, 1.0f));

	light.SetdiffuseLightColor(0, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetdiffuseLightColor(1, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetdiffuseLightColor(2, D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));
	light.SetdiffuseLightColor(3, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetambientLight(D3DXVECTOR4(10.3f, 0.3f, 0.3f, 1.0f));

	modeldata.LoadModelData("Assets/model/Querytyan.X",NULL);
	model.Init(&modeldata);
	model.SetLight(&light);
	
}

void Goal::Updeate()
{
	D3DXVECTOR3 v1;
	v1 = player->GetPosition() - position;
	float len = D3DXVec3Length(&v1);
	if (len < 1.0f)
	{
		MessageBox(NULL, "goal", "メッセージボックス", NULL);
	}

	model.UpdateWorldMatrix(position, D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
}

void Goal::Render()
{
	//モデル描画
	model.Draw(&game->GetCamera().GetviewMatrix(), &game->GetCamera().GetprojectionMatrix());
}
