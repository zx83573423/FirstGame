#pragma once
#include "CObject.h"
class CFactory
{
public:
	//��������
	virtual CObject* CreatObject(int nType) = 0;
	//ɾ������
	virtual int DeleteObject(CObject* pObject) = 0;
};

