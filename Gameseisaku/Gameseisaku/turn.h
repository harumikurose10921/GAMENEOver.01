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
	float	currentAngleY;	//現在の方向
	float	targetAngleY;		//向きたい方向
	float	turnSpeed;		//回転速度
	float   TurnSpeed;
	bool	isTurn;				//回転フラグ

};