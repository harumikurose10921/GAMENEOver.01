#pragma once
class Matrix{
public:
	union {
		struct {
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float m[4][4];
	};
	static const Matrix Identity;	//!<単位行列。
public:
	//ベクトルと行列の乗算
	//[in,out] v 乗算されるベクトル。
	void Mul(D3DXVECTOR3& vOut)const
	{
		D3DXVECTOR3 vTmp = vOut;
		vOut.x = vTmp.x * m[0][0] + vTmp.y * m[1][0] + vTmp.z * m[2][0] + m[3][0];
		vOut.y = vTmp.x * m[0][1] + vTmp.y * m[1][1] + vTmp.z * m[2][1] + m[3][1];
		vOut.z = vTmp.x * m[0][2] + vTmp.y * m[1][2] + vTmp.z * m[2][2] + m[3][2];
	}

};
