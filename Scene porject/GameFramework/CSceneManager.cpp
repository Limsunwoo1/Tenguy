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

//void CSceneManager::AddBox(float InDeltaTime)
//{
//	float rand = (float)Dis(gen);
//	Box = new BoxObject(Vector2D{ (float)980 ,(float)dis(gen) }, Vector2D{ rand ,rand }, 600);
//	Box->SetObjectType(EOBJ_TYPE::RECTANGLE);
//	Box->SetDeltaTime(InDeltaTime);
//	CurScene->AddObject(Box);
//	
//	/*delete Box;
//	Box = nullptr;*/
//}
void CSceneManager::AddObject(CObject* InObject)
{
	CurScene->AddObject(InObject);
}

std::vector<CObject*> CSceneManager::Get_Object()
{
	return CurScene->Get_Object();
}

void CSceneManager::SetVectorSize(std::vector<CObject*> InVC)
{
	CurScene->SetVectorSize(InVC);
}


bool CSceneManager::Player_Hit()
{
	CObject* Player = ObjectManager::GetInstance()->GetPlayer();

	for (int i = 0;i < CurScene->Get_Object().size(); ++i)
	{
		if (CurScene->Get_Object()[i]->GetObjectType() == EOBJ_TYPE::RECTANGLE || CurScene->Get_Object()[i]->GetObjectType() == EOBJ_TYPE::Bullet)
		{
			if (!CheckCollision(Player->GetPosition(), Player->GetScale(), CurScene->Get_Object()[i]->GetPosition(), CurScene->Get_Object()[i]->GetScale()))
				continue;

			CurScene->Get_Object().erase(CurScene->Get_Object().begin() + i);
			delete* (CurScene->Get_Object().begin() + i);
			return true;
		}

	}
	return false;
}


void CSceneManager::BoxAttackObject(float InDeltaTime)
{
	for (int i = 0; i < CurScene->Get_Object().size(); ++i)
	{
		if (CurScene->Get_Object()[i]->GetObjectType() != EOBJ_TYPE::RECTANGLE)
			continue;

		BoxAttackObjectSpawnCoolTimeCurrent = CurScene->Get_Object()[i]->GetDeltaTime();
		BoxAttackObjectSpawnCoolTimeCurrent += InDeltaTime;

		if (BoxAttackObjectSpawnCoolTimeCurrent < BoxAttackObjectSpawnCoolTimeMax)
		{
			CurScene->Get_Object()[i]->SetDeltaTime(BoxAttackObjectSpawnCoolTimeCurrent);
			continue;
		}

		if (BoxAttackObjectSpawnCoolTimeCurrent > BoxAttackObjectSpawnCoolTimeMax)
		{
			CObject* BoxAttack = new BoxObject(Vector2D{ CurScene->Get_Object()[i]->GetPosition().x, CurScene->Get_Object()[i]->GetPosition().y }, Vector2D{ 20,20 }, 1200);
			BoxAttack->SetObjectType(EOBJ_TYPE::Bullet);
			CurScene->Get_Object()[i]->SetDeltaTime(0.f);

			AddObject(BoxAttack);
		}
	}
}