
#include <iostream>
#include <Windows.h>
#include "CScene_Game.h"
#include "CGame_Test.h"
using namespace std;
void CScene_Game::Init()
{
	cout << "��Ϸ����:��ʼ��" << endl;
	
}

void CScene_Game::Start()
{
	cout << "��Ϸ����:��ʼ" << endl;

	m_pGame = new CGame_Test;
	m_pGame->Init(10,10);
}

void CScene_Game::Update()
{
	cout << "��Ϸ����:����" << endl;
	system("cls");
	m_pGame->Run();
	Sleep(100);
}

void CScene_Game::End()
{
	cout << "��Ϸ����:����" << endl;

	m_pGame->Quit();
	delete m_pGame;
	m_pGame = nullptr;
}

void CScene_Game::Quit()
{
	cout << "��Ϸ����:�˳�" << endl;
}
