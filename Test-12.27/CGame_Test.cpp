#include "CGame_Test.h"
#include "CFactory_Static.h"
#include <iostream>
using namespace std;
void CGame_Test::Draw()
{
	for (size_t i = 0; i < m_dwWidth * m_dwHight; i++)
	{
		if (nullptr != m_mapMap[i])
		{
			cout << m_mapMap[i]->Print();
		}
		else
		{
			cout << "¡õ";
		}
		

		if (m_dwWidth - 1 == i % m_dwWidth)
		{
			cout << endl;
		}

	}
}
void CGame_Test::Logic()
{
}
void CGame_Test::Init(uint32_t dwWidth, uint32_t dwHight)
{
	m_dwWidth = dwWidth;
	m_dwHight = dwHight;
	for (size_t i = 0; i < m_dwWidth * m_dwHight; i++)
	{
		m_mapMap[i] = nullptr;
	}

	//Ìí¼ÓÔªËØ
	CObject* pObj = CFactory_Static::GetInstace()->CreatObject(OBJECT_DETAIL_TYPE_GRASS);
	m_mapMap[0 + 0 * m_dwWidth] = pObj;
}

void CGame_Test::Quit()
{
	for (size_t i = 0; i < m_dwWidth * m_dwHight; i++)
	{
		CFactory_Static::GetInstace()->DeleteObject(m_mapMap[i]);
	}
	m_mapMap.clear();
}
