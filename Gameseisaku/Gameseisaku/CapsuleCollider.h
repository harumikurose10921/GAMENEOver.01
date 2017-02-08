/*!
* @brief	カプセルコライダー。
*/

#pragma once
#include "ICollider.h"

	class CCapsuleCollider : public ICollider
	{
	public:
		/*!
		* @brief	コンストラクタ。
		*/
		CCapsuleCollider();
		/*!
		* @brief	デストラクタ。
		*/
		~CCapsuleCollider();
		/*!
		* @brief	作成。
		*/
		void Create(float radius, float height)
		{
			shape = new btCapsuleShape(radius, height);
		}
		btCollisionShape* GetBody() override
		{
			return shape;
		}
	private:
		btCapsuleShape*		shape;
	};
