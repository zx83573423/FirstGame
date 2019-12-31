#pragma once
#include "../Frame/CScene.h"

class CGame;
class CScene_Game :
	public CScene
{
	CGame* m_pGame;
public:
	void Init();
	void Start();
	void Update();
	void End();
	void Quit();
};

