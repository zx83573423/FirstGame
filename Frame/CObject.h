#pragma once
#include <string>
#include "CObjectDefine.h"
class CObject
{
protected:
	int32_t m_iPosX;
	int32_t m_iPosY;
	uint32_t m_dwType;
	uint32_t m_dwDetailType;
public:
	CObject();
	virtual std::string Print() = 0;
	void SetPosX(int32_t iPosX);
	void SetPosY(int32_t iPosY);
	int32_t GetPosX();
	int32_t GetPosY();
	uint32_t GetObjectType();
	uint32_t GetObjectDetailType();
};

