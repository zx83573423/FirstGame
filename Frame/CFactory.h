#pragma once
#include "CObject.h"
class CFactory
{
public:
	//创建对象
	virtual CObject* CreatObject(int nType) = 0;
	//删除对象
	virtual int DeleteObject(CObject* pObject) = 0;
};

