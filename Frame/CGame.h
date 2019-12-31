#pragma once
#include <iostream>
class CGame
{
protected:
	uint32_t m_dwWidth;
	uint32_t m_dwHight;
protected:
    virtual void Draw() = 0;
	virtual void Logic() = 0;
public:
	//��ʼ��
	virtual void Init(uint32_t dwWidth, uint32_t dwHight) = 0;
	//����
	virtual void Run();
	//�˳�
	virtual void Quit() = 0;
};

