
#include <iostream>
#include <Windows.h>
#include "CScene_Game.h"
#include "CGame_Test.h"
using namespace std;
void CScene_Game::Init()
{
	cout << "游戏场景:初始化" << endl;
	
}

void CScene_Game::Start()
{
	cout << "游戏场景:开始" << endl;

	m_pGame = new CGame_Test;
	m_pGame->Init(10,10);
}

void CScene_Game::Update()
{
	cout << "游戏场景:更新" << endl;
	system("cls");
	m_pGame->Run();
	Sleep(100);
}

void CScene_Game::End()
{
	cout << "游戏场景:结束" << endl;

	m_pGame->Quit();
	delete m_pGame;
	m_pGame = nullptr;
}

void CScene_Game::Quit()
{
	cout << "游戏场景:退出" << endl;
}
