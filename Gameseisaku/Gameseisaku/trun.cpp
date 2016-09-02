#include"stdafx.h"
#include"turn.h"

Trun::Trun()
{
	
}

Trun::~Trun()
{

}

void Trun::Init()
{
	currentAngleY = 0.0f;
	targetAngleY = 0.0f;
	turnSpeed = 0.0f;
	TurnSpeed = 0.1f;
}

float Trun::Updeate(bool isTurn, float currentAngleY)
{
	if (isTurn) {
		float angleDiff = targetAngleY - currentAngleY;	//目的角度までどれだけ回せがいいのかを計算する。
		float angleDiffAbs = fabsf(angleDiff);				//回す角度の絶対値を計算。
		if (angleDiffAbs > 0.0001f) {						//回す角度の大きさが非常に小さい場合は回さない。
			float turnDir = angleDiff / angleDiffAbs;		//回転させる方向を計算する。
			if (angleDiffAbs > fPI) {						//回転させる角度が180度を越えているかを判定する。
				//180度を越える回転のため遠回り。
				currentAngleY += 2.0f * fPI *  turnDir;	//現在の角度を-90度なら270度、180度なら-180度にする。
				turnDir *= -1.0f;							//回す方向を反転。
			}
			turnSpeed = TurnSpeed * turnDir;
		}
	}
	currentAngleY += turnSpeed;
	if (fabsf(targetAngleY - currentAngleY) < fabsf(turnSpeed) + 0.01f) {
		//ターン終わり。
		turnSpeed = 0.0f;
		currentAngleY = targetAngleY;
	}
	return currentAngleY;
}