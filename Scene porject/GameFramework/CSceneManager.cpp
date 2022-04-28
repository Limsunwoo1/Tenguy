#include "CSceneManager.h"
#include "CScene.h"
#include "CTitleScene.h"

CSceneManager::CSceneManager()
: CurScene(nullptr)
{

}

CSceneManager::~CSceneManager()
{
	CurScene->Clear();
}


void CSceneManager::Init()
{
	CurScene = new CTitleScene();
	CurScene->Init();
}

void CSceneManager::Update(float InDeltaTime)
{
	CurScene->Update(InDeltaTime);
}

void CSceneManager::SetCurScene(CScene* InNewScene)
{
	CurScene->Clear();
	CurScene = InNewScene;
	CurScene->Init();
}

