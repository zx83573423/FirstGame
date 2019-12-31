#include "CObject.h"


CObject::CObject()
{
	m_iPosX = 0;
	m_iPosY = 0;
	m_dwType = OBJECT_TYPE_NONE;
	m_dwDetailType = OBJECT_DETAIL_TYPE_NONE;
}

void CObject::SetPosX(int32_t iPosX)
{
	m_iPosX = iPosX;
}

void CObject::SetPosY(int32_t iPosY)
{
	m_iPosY = iPosY;
}

int32_t CObject::GetPosX()
{
	return m_iPosX;
}

int32_t CObject::GetPosY()
{
	return m_iPosY;
}

uint32_t CObject::GetObjectType()
{
	return m_dwType;
}

uint32_t CObject::GetObjectDetailType()
{
	return m_dwDetailType;
}
