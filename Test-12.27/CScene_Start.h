#pragma once
#include "../Frame/CScene.h"
class CScene_Start :
	public CScene
{
public:
	void Init() ;
	void Start();
	void Update();
	void End();
	void Quit();
};

