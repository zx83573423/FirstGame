#pragma once
#include "../Frame/CFactory.h"
#include <map>
/*
	��̬����:��Ϊ���漰��λ�øı䣬ֻ��Ҫ����ͬһ�����󼴿�
*/
class CFactory_Static :
	public CFactory
{
	std::map<int, CObject*> m_mapAllObject;		//���ͣ�����
	std::map<CObject*, uint32_t> m_mapAllCObjectQuote;//����  ���ô���

	//��ʱд�ɵ���
	CFactory_Static();
	CFactory_Static(const CFactory_Static& that);
public:
	static CFactory_Static* GetInstace();
	//��������
	CObject* CreatObject(int nType);
	//ɾ������
	int DeleteObject(CObject* pObject);
};

