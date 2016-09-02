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
	float	currentAngleY;	//Œ»İ‚Ì•ûŒü
	float	targetAngleY;		//Œü‚«‚½‚¢•ûŒü
	float	turnSpeed;		//‰ñ“]‘¬“x
	float   TurnSpeed;
	bool	isTurn;				//‰ñ“]ƒtƒ‰ƒO

};