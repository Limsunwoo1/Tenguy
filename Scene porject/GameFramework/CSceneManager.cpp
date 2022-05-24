#include "CSceneManager.h"
#include "CScene.h"
#include "CTitleScene.h"
#include "BoxObject.h"
#include "ObjectManager.h"
#include "Func.h"
#include <random>

//random_device rd;
//mt19937 gen(rd());
//uniform_int_distribution<int> dis(0, 980);
//uniform_int_distribution<int> Dis(50, 150);


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

void CSceneManager::Render(HDC InHdc)
{
	CurScene->Render(InHdc);
}

void CSceneManager::SetCurScene(CScene* InNewScene)
{
	CurScene->Clear();
	CurScene = InNewScene;
	CurScene->Init();
}

void CSceneManager::AddObject(CObject* InObject)
{
	CurScene->AddObject(InObject);
}

const std::vector<CObject*>& CSceneManager::Get_Object(OBJ_LAYER InLayer)
{
	return CurScene->Get_Object(InLayer);
}

void CSceneManager::SetVectorSize(OBJ_LAYER InLayer, int count)
{
	CurScene->SetVectorSize(InLayer, count);
}
