#include "CScene_Start.h"
#include "../Frame/CSceneManager.h"
#include <iostream>
#include <Windows.h>
using namespace std;
void CScene_Start::Init()
{
	cout << "��ʼ����:��ʼ��" << endl;
}

void CScene_Start::Start()
{
	cout << "��ʼ����:��ʼ" << endl;
}

void CScene_Start::Update()
{
	cout << "��ʼ����:����" << endl;
	if (GetAsyncKeyState('J') & 1)
	{
		cout << "����J��" << endl;
		int nResult = CSceneManager::GetInstance()->ChangeScene("��Ϸ����");
		if (1 == nResult)
		{
			cout << "�л��ɹ�" << endl;
		}
		else
		{
			cout << "�л�ʧ��" << endl;
		}
		
	}
	Sleep(1000);
}

void CScene_Start::End()
{
	cout << "��ʼ����:����" << endl;
}

void CScene_Start::Quit()
{
	cout << "��ʼ����:�˳�" << endl;
}
