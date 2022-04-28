#include "CStage1.h"
#include "Object.h"
#include "BoxObject.h"
#include "ObjectManager.h"
#include <vector>
#include <random>
#include "CSceneManager.h"
#include "CTitleScene.h"


using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(0, 980);
uniform_int_distribution<int> Dis(50, 150);

CStage1::CStage1()
{
	Player = new CPlayer();
	Player->SetObjectType(EOBJ_TYPE::Player);
	ObjectManager::GetInstance()->SetPlayer(Player);
}

CStage1::~CStage1()
{

}

void CStage1::Init()
{
	if (Player != nullptr)
		return;

	Player = new CPlayer();
	Player->SetObjectType(EOBJ_TYPE::Player);
	ObjectManager::GetInstance()->SetPlayer(Player);
}

void CStage1::Clear()
{
	delete Player;
	Player = nullptr;
	std::vector<CObject*> COB;
	ObjectManager::GetInstance()->SetPlayer(Player);
	ObjectManager::GetInstance()->SetVectorSize(COB);
}

void CStage1::Update(float InDeltaTime)
{
	CObject* test_Obj = ObjectManager::GetInstance()->GetPlayer();        //형 변환
	CPlayer* testPobj = static_cast<CPlayer*>(test_Obj);

	static float currdelta;

	if (testPobj->GetPlayerLIfe() == 0)
	{
		CTitleScene* Tiltele = new CTitleScene();
		CSceneManager::GetInstance()->SetCurScene(Tiltele);
			
		return;
	}
	currdelta += InDeltaTime;

	if (ObjectManager::GetInstance()->Player_Hit() == true)
	{
		if (currdelta > 1.0f)
		{
			testPobj->SetPlayerLIfe(testPobj->GetPlayerLIfe() - 1);
			currdelta = 0.f;
		}
	}


	BoxSpawnCoolTimeCurrent += InDeltaTime;

	if (BoxSpawnCoolTimeCurrent > BoxSpawnCoolTimeMax)
	{
		BoxSpawnCoolTimeCurrent = 0.f;
		AddBox(InDeltaTime);
	}

	BoxAttackObject(InDeltaTime);           //루프를 돌면서 좌표값 체크	 및 이전에 생성된 박스오브젝트가 지속적인 공격을 할수 있게해야함

}

void CStage1::AddBox(float InDeltaTime)
{
	float rand = (float)Dis(gen);
	Box = new BoxObject(Vector2D{ (float)980 ,(float)dis(gen) }, Vector2D{ rand ,rand }, 600);
	Box->SetObjectType(EOBJ_TYPE::RECTANGLE);
	Box->SetDeltaTime(InDeltaTime);
	ObjectManager::GetInstance()->AddObject(Box);
}

void CStage1::BoxAttackObject(float InDeltaTime)
{
	vector<CObject*> InVect = ObjectManager::GetInstance()->Get_Object();
	for (int i = 0; i < InVect.size(); ++i)
	{
		if (InVect[i]->GetObjectType() != EOBJ_TYPE::RECTANGLE)
			continue;

		BoxAttackObjectSpawnCoolTimeCurrent = InVect[i]->GetDeltaTime();
		BoxAttackObjectSpawnCoolTimeCurrent += InDeltaTime;

		if (BoxAttackObjectSpawnCoolTimeCurrent < BoxAttackObjectSpawnCoolTimeMax)
		{
			InVect[i]->SetDeltaTime(BoxAttackObjectSpawnCoolTimeCurrent);
			continue;
		}

		if (BoxAttackObjectSpawnCoolTimeCurrent > BoxAttackObjectSpawnCoolTimeMax)
		{
			BoxAttack = new BoxObject(Vector2D{ InVect[i]->GetPosition().x, InVect[i]->GetPosition().y }, Vector2D{ 20,20 }, 1200);
			BoxAttack->SetObjectType(EOBJ_TYPE::Bullet);
			InVect[i]->SetDeltaTime(0.f);

			ObjectManager::GetInstance()->AddObject(BoxAttack);
		}
	}
}
