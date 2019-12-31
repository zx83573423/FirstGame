#pragma once
#include "../Frame/CGame.h"
#include "../Frame/CObject.h"
#include <map>
class CGame_Test :
	public CGame
{
	std::map<int, CObject*> m_mapMap;
protected:
	void Draw();
	void Logic();
public:
	//³õÊ¼»¯
	void Init(uint32_t dwWidth, uint32_t dwHight);
	//ÍË³ö
	void Quit();
};

