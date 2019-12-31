#include "CSceneManager.h"
CSceneManager::CSceneManager()
{
}

CSceneManager::CSceneManager(const CSceneManager& that)
{
}

CSceneManager* CSceneManager::GetInstance()
{
	static CSceneManager* pOne = nullptr;
	if (nullptr == pOne)
	{
		pOne = new CSceneManager;
	}
	return pOne;
}

int CSceneManager::AddNewScene(std::string strSceneName, CScene* pCScene)
{
	std::map<std::string, CScene*>::iterator it = m_mapAllScene.find(strSceneName);
	if (m_mapAllScene.end() != it)
	{
		return -1;
	}
	m_mapAllScene[strSceneName] = pCScene;
	pCScene->Init();
	return 1;
}

int CSceneManager::ChangeScene(std::string strSceneName)
{
	std::map<std::string, CScene*>::iterator it = m_mapAllScene.find(strSceneName);
	if (m_mapAllScene.end() != it)
	{
		if (nullptr != m_pCurrentScene)
		{
			m_pCurrentScene->End();
		}
		m_pCurrentScene = it->second;
		m_pCurrentScene->Start();
		return 1;
	}
	return -1;
}

void CSceneManager::Start()
{
	while (true)
	{
		if (nullptr != m_pCurrentScene)
			m_pCurrentScene->Update();
	}
}
