#pragma once
#include <iostream>
#include <vector>
#include <map>

class TVector
{
public:
	float x;
	float y;
	float z;
	TVector(): x(0),y(0),z(0) {}
	TVector(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
	TVector operator +=(TVector p)
	{
		x += p.x;
		y += p.y;
		z += p.z;
		return *this;
	}
	TVector operator *(float p)
	{
		TVector ret;
		ret.x = x * p;
		ret.y = y * p;
		ret.z = z * p;
		return ret;
	}
	TVector operator +(TVector p)
	{
		TVector ret;
		ret.x = x + p.x;
		ret.y = y + p.y;
		ret.z = z + p.z;
		return ret;
	}
	TVector operator -(TVector p)
	{
		TVector ret;
		ret.x = x - p.x;
		ret.y = y - p.y;
		ret.z = z - p.z;
		return ret;
	}
	TVector operator /(float p)
	{
		TVector ret;
		ret.x = x / p;
		ret.y = y / p;
		ret.z = z / p;
		return ret;
	}
	bool operator ==(TVector p)
	{
		if (x == p.x && y == p.y && z == p.z) return true;
		else return false;
	}
private:

};
