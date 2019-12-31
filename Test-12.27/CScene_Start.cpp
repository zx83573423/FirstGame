#include "CScene_Start.h"
#include "../Frame/CSceneManager.h"
#include <iostream>
#include <Windows.h>
using namespace std;
void CScene_Start::Init()
{
	cout << "开始场景:初始化" << endl;
}

void CScene_Start::Start()
{
	cout << "开始场景:开始" << endl;
}

void CScene_Start::Update()
{
	cout << "开始场景:更新" << endl;
	if (GetAsyncKeyState('J') & 1)
	{
		cout << "按下J键" << endl;
		int nResult = CSceneManager::GetInstance()->ChangeScene("游戏场景");
		if (1 == nResult)
		{
			cout << "切换成功" << endl;
		}
		else
		{
			cout << "切换失败" << endl;
		}
		
	}
	Sleep(1000);
}

void CScene_Start::End()
{
	cout << "开始场景:结束" << endl;
}

void CScene_Start::Quit()
{
	cout << "开始场景:退出" << endl;
}
