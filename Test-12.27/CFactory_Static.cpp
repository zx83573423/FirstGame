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
	//先从map查
	std::map<int, CObject*>::iterator it = m_mapAllObject.find(nType);
	if (m_mapAllObject.end() != it)
	{
		//找到了
		pCurrentObj = it->second;
		//引用次数加1
		m_mapAllCObjectQuote[pCurrentObj] = m_mapAllCObjectQuote[pCurrentObj] + 1;
	}
	else
	{
		//没有找到
		switch (nType)
		{
		case OBJECT_DETAIL_TYPE_GRASS:pCurrentObj = new CStaticObject_Grass; break;
		}
		//添加进表
		m_mapAllObject[nType] = pCurrentObj;
		//引用次数为1
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
		//如果引用次数为0
		if (0 == m_mapAllCObjectQuote[pObject])
		{
			uint32_t dwDetailType = pObject->GetObjectDetailType();
			//从表中删除
			m_mapAllObject.erase(dwDetailType);
			m_mapAllCObjectQuote.erase(pObject);
			delete pObject;
			return 1;
		}
	}
	return -1;
}
