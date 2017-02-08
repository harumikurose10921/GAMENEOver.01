#pragma once
#define vecZero D3DXVECTOR3(0.0f,0.0f,0.0f)
#define QuatanionIndentity D3DXQUATERNION(0.0f,0.0f,0.0f,1.0f)

class ICollider;

//���̏��B
struct RigidBodyInfo {
	RigidBodyInfo() :
	collider(NULL),
	mass(0.0f)
	{
		pos = vecZero;
		rot = QuatanionIndentity;
	}
	D3DXVECTOR3 pos;				//���W�B
	D3DXQUATERNION rot;			//��]�B
	ICollider* collider;		//�R���C�_�[�B
	float mass;					//���ʁB

};
//���̃N���X�B
class RigidBody
{
	btRigidBody*			rigidBody;		//���́B
	btDefaultMotionState*	myMotionState;	//���[�V�����X�e�[�g�B
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
