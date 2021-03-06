#pragma once
#include <iostream>
#include <cmath>



class TVector
{
public:
	float x;
	float y;
	float z;
	TVector();
	~TVector();

private:
};
TVector::TVector() : x(0), y(0), z(0) {}
TVector::~TVector() {}


class TLogic : public TVector
{
public:

	TVector SetVector(float x = 0, float y = 0);
	float DotPruduct(TVector p1, TVector p2);
	float Projection(TVector p1, TVector p2, TVector p3);
	float AngleBetween(TVector p1, TVector p2);
private:

};

float TLogic::AngleBetween(TVector p1, TVector p2)
{
	return DotPruduct(p1, p2) / sqrt(((p1.x * p1.x) + (p1.y * p1.y)) * (p2.x * p2.x + p2.y * p2.y));
}
TVector TLogic::SetVector(float _x, float _y)
{
	TVector Rat;
	Rat.x = _x;
	Rat.y = _y;
	return Rat;
}
float TLogic::DotPruduct(TVector p1, TVector p2)
{
	return (p1.x * p2.x) + (p1.y * p2.y);
}
float TLogic::Projection(TVector p1, TVector p2, TVector p3) // 여기부터는 벡터끼리의 계산이라 변환
{
	TVector a = SetVector(p1.x - p2.x, p1.y - p2.y);
	TVector b = SetVector(p1.x - p3.x, p1.y - p3.y);
	TVector ret = SetVector((a.x * DotPruduct(a, b) / DotPruduct(a, a)), (a.y * DotPruduct(a, b) / DotPruduct(a, a)));
	
	TVector Get = SetVector(b.x - ret.x, b.y - ret.y);
	float vec = sqrt((Get.x * Get.x) + (Get.y * Get.y));

	return vec; 
}



