#pragma once

static const float fPI = 3.14159265358979323846f;
const float	TurnSpeed = D3DXToRadian(10.0f);

class Trun
{
public:
	Trun();
	~Trun();
	void Init();
	float Updeate(bool isTurn, float currentAngleY);
private:
	float	currentAngleY;	//���݂̕���
	float	targetAngleY;		//������������
	float	turnSpeed;		//��]���x
	float   TurnSpeed;
	bool	isTurn;				//��]�t���O

};