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
	//��ʼ��
	void Init(uint32_t dwWidth, uint32_t dwHight);
	//�˳�
	void Quit();
};

