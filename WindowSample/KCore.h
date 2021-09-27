#pragma once
#include "KDevice.h"
#include "KWindow.h"

class KCore : public KWindow
{

private:
	bool	GameInit()	override;
	bool	GameRun()	override;
	bool	GameFrame();
	bool	GameRender();
	bool	GameRelease()override;
public:
	virtual bool	Init();
	virtual bool	Frame();
	virtual bool	PreRender();
	virtual bool	Render();
	virtual bool	PostRender();
	virtual bool	Release();
public:
}; 
