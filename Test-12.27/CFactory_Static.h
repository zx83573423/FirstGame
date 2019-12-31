#pragma once
#include "../Frame/CFactory.h"
#include <map>
/*
	静态工厂:因为不涉及到位置改变，只需要引用同一个对象即可
*/
class CFactory_Static :
	public CFactory
{
	std::map<int, CObject*> m_mapAllObject;		//类型，对象
	std::map<CObject*, uint32_t> m_mapAllCObjectQuote;//对象  引用次数

	//暂时写成单利
	CFactory_Static();
	CFactory_Static(const CFactory_Static& that);
public:
	static CFactory_Static* GetInstace();
	//创建对象
	CObject* CreatObject(int nType);
	//删除对象
	int DeleteObject(CObject* pObject);
};

