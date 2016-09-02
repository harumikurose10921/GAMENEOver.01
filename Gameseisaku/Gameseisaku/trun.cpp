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
		float angleDiff = targetAngleY - currentAngleY;	//�ړI�p�x�܂łǂꂾ���񂹂������̂����v�Z����B
		float angleDiffAbs = fabsf(angleDiff);				//�񂷊p�x�̐�Βl���v�Z�B
		if (angleDiffAbs > 0.0001f) {						//�񂷊p�x�̑傫�������ɏ������ꍇ�͉񂳂Ȃ��B
			float turnDir = angleDiff / angleDiffAbs;		//��]������������v�Z����B
			if (angleDiffAbs > fPI) {						//��]������p�x��180�x���z���Ă��邩�𔻒肷��B
				//180�x���z�����]�̂��߉����B
				currentAngleY += 2.0f * fPI *  turnDir;	//���݂̊p�x��-90�x�Ȃ�270�x�A180�x�Ȃ�-180�x�ɂ���B
				turnDir *= -1.0f;							//�񂷕����𔽓]�B
			}
			turnSpeed = TurnSpeed * turnDir;
		}
	}
	currentAngleY += turnSpeed;
	if (fabsf(targetAngleY - currentAngleY) < fabsf(turnSpeed) + 0.01f) {
		//�^�[���I���B
		turnSpeed = 0.0f;
		currentAngleY = targetAngleY;
	}
	return currentAngleY;
}