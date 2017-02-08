/*!
* @brief	カプセルコライダー。
*/
#include "stdafx.h"
#include "CapsuleCollider.h"

/*!
* @brief	コンストラクタ。
*/
CCapsuleCollider::CCapsuleCollider() :
		shape(nullptr)
{

}
/*!
* @brief	デストラクタ。
*/
CCapsuleCollider::~CCapsuleCollider()
{
	delete shape;
}
