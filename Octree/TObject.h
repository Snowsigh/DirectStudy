#pragma once
#include "Tvector.h"

// Collision Info
struct TBox
{
	TVector vMin; 
	TVector vMax; 
	TVector vPivot;
	TVector vCenter;
	TVector vSize;

	TBox()
	{
		vMin = { 0,0,0 };
		vMax = { 0,0,0 };
		vPivot = { 0,0,0 };
		vCenter = { 0,0,0 };
		vSize = { 0,0,0, };
	}
	TBox(TVector _Min, TVector _Max)
	{
		vCenter = (_Min + _Max) / 2.0f;
		vSize = _Max - vCenter;
		TVector vHalf = vSize / 2.0f;
		vPivot = { vCenter.x - vHalf.x, vCenter.y - vHalf.y, vCenter.z + vHalf.z };
		vMin = _Min;
		vMax = _Max;
	}
};


// Dynamic object Info
class TObject
{
public:
	int m_iNodeIndex;

	TVector m_vVelocity; // 속도
	TVector m_vAcceleration; // 가속도
	TVector m_vForces; // 힘의 합산
	TBox m_tBox;
	TVector m_vPos;


public:
	TObject();
	TObject(TVector _Pos, TVector _vSize);
	
};
