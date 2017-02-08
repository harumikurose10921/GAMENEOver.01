#pragma once
#define vecZero D3DXVECTOR3(0.0f,0.0f,0.0f)
#define QuatanionIndentity D3DXQUATERNION(0.0f,0.0f,0.0f,1.0f)

class ICollider;

//剛体情報。
struct RigidBodyInfo {
	RigidBodyInfo() :
	collider(NULL),
	mass(0.0f)
	{
		pos = vecZero;
		rot = QuatanionIndentity;
	}
	D3DXVECTOR3 pos;				//座標。
	D3DXQUATERNION rot;			//回転。
	ICollider* collider;		//コライダー。
	float mass;					//質量。

};
//剛体クラス。
class RigidBody
{
	btRigidBody*			rigidBody;		//剛体。
	btDefaultMotionState*	myMotionState;	//モーションステート。
public:
	RigidBody();
	~RigidBody();
	void Release();
	void Create(RigidBodyInfo& rbInfo);
	btRigidBody* GetBody()
	{
		return rigidBody;
	}
};
