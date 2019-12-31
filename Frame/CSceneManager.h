#pragma once
#include "CScene.h"
#include <map>
#include <string>
class CSceneManager
{
	std::map<std::string, CScene*> m_mapAllScene;
	CScene* m_pCurrentScene;
	CSceneManager();
	CSceneManager(const CSceneManager& that);
public:
	static CSceneManager* GetInstance();

	int AddNewScene(std::string strSceneName, CScene* pCScene);
	int ChangeScene(std::string strSceneName);
	void Start();
};

