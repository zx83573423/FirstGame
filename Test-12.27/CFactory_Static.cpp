#include "CFactory_Static.h"
#include "CStaticObject_Grass.h"

CFactory_Static::CFactory_Static()
{
}

CFactory_Static::CFactory_Static(const CFactory_Static& that)
{
}

CFactory_Static* CFactory_Static::GetInstace()
{
	static CFactory_Static* pOne = nullptr;
	if (nullptr == pOne)
	{
		pOne = new CFactory_Static;
	}
	return pOne;
}

CObject* CFactory_Static::CreatObject(int nType)
{
	CObject* pCurrentObj = nullptr;
	//�ȴ�map��
	std::map<int, CObject*>::iterator it = m_mapAllObject.find(nType);
	if (m_mapAllObject.end() != it)
	{
		//�ҵ���
		pCurrentObj = it->second;
		//���ô�����1
		m_mapAllCObjectQuote[pCurrentObj] = m_mapAllCObjectQuote[pCurrentObj] + 1;
	}
	else
	{
		//û���ҵ�
		switch (nType)
		{
		case OBJECT_DETAIL_TYPE_GRASS:pCurrentObj = new CStaticObject_Grass; break;
		}
		//��ӽ���
		m_mapAllObject[nType] = pCurrentObj;
		//���ô���Ϊ1
		m_mapAllCObjectQuote[pCurrentObj] = 1;
	}

	return pCurrentObj;
}

int CFactory_Static::DeleteObject(CObject* pObject)
{
	if (nullptr == pObject)
		return -1;
	std::map<CObject*, uint32_t>::iterator it = m_mapAllCObjectQuote.find(pObject);
	if (m_mapAllCObjectQuote.end() != it)
	{
		m_mapAllCObjectQuote[pObject] = m_mapAllCObjectQuote[pObject] - 1;
		//������ô���Ϊ0
		if (0 == m_mapAllCObjectQuote[pObject])
		{
			uint32_t dwDetailType = pObject->GetObjectDetailType();
			//�ӱ���ɾ��
			m_mapAllObject.erase(dwDetailType);
			m_mapAllCObjectQuote.erase(pObject);
			delete pObject;
			return 1;
		}
	}
	return -1;
}
