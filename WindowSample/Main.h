#pragma once
#include "KCore.h"

class Sample : public KCore
{
public:
	Sample();
	~Sample();
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
private:
	
};

Sample::Sample()
{
}

Sample::~Sample()
{
}