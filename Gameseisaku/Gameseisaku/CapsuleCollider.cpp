/*!
* @brief	�J�v�Z���R���C�_�[�B
*/
#include "stdafx.h"
#include "CapsuleCollider.h"

/*!
* @brief	�R���X�g���N�^�B
*/
CCapsuleCollider::CCapsuleCollider() :
		shape(nullptr)
{

}
/*!
* @brief	�f�X�g���N�^�B
*/
CCapsuleCollider::~CCapsuleCollider()
{
	delete shape;
}
