#include "CStage1.h"
#include "Object.h"
#include "BoxObject.h"
#include "ObjectManager.h"
#include <vector>
#include <random>
#include "CSceneManager.h"
#include "CTitleScene.h"
#include <iostream>
#include "Box2.h"
#include "Struct.h"
#include "ResourceManager.h"

using namespace std;


CStage1::CStage1()
{
	
}

CStage1::~CStage1()
{

}

void CStage1::Init()
{
	Player = new CPlayer(/*Vector2D(500,600), Vector2D(50, 50)*/);
	Player->SetObjectType(EOBJ_TYPE::Player);
	Player->SetObjectLayer(OBJ_LAYER::PLAYER);
	Player->SetTexture(CResourceManager::GetInstance()->FindTexture("Player"));
	Player->SetStageCode(1);
	ObjectManager::GetInstance()->SetPlayer(Player);
	AddObject(Player);
	
	CObject* Backgruond = new CObject(Vector2D((float)0, (float)0), Vector2D((float)980, (float)680));
	Backgruond->SetObjectType(EOBJ_TYPE::BackGrund);
	Backgruond->SetObjectLayer(OBJ_LAYER::BACKGROUND);
	Backgruond->SetTexture(CResourceManager::GetInstance()->FindTexture("BACKGRUOND"));
	AddObject(Backgruond);

	BoxSpawnCoolTimeMax = 0.3f;
	BoxSpawnCoolTimeCurrent = 0.f;

	BoxAttackObjectSpawnCoolTimeMax = 0.1f;
	BoxAttackObjectSpawnCoolTimeCurrent = 0.f;
}

void CStage1::Clear()
{
	delete Player;
	Player = nullptr;
	ObjectManager::GetInstance()->SetPlayer(Player);
	CScene::ClearObject();
}

void CStage1::Update(float InDeltaTime)
{
	CScene::Update(InDeltaTime);
	
	static CPlayer* InPlayer;
	static float currdelta;
	static float test;
	test += InDeltaTime;
	currdelta += InDeltaTime;
	static int tes = 0;
	if (test > 1)
	{
		cout << "---------" << endl;
		cout << "°¹¼ö" << Get_Object(OBJ_LAYER::MONSTER).size() << endl;
		cout << "---------" << endl;
		cout << "ÇÁ·¹ÀÓ " << tes << endl;
		cout << "---------" << endl;
		test = 0.f;
		tes = 0;
		//CScene::Update(InDeltaTime);
	}
	++tes;
	CObject* Player = ObjectManager::GetInstance()->GetPlayer();
	InPlayer = ObjectManager::GetInstance()->Dynamic_Cast(Player);

	if (Player_Hit() == true)
	{
		/*if (currdelta > 1.0f)
		{
			InPlayer->SetPlayerLIfe(InPlayer ->GetPlayerLIfe()-1);
			currdelta = 0.f;
		}*/
	}

	if (InPlayer->GetPlayerLIfe() == 0)
	{
		CTitleScene* Title = new CTitleScene();
		CSceneManager::GetInstance()->SetCurScene(Title);
		return;
	}

	ObjectManager::GetInstance()->SetPlayer(InPlayer);
	BoxSpawnCoolTimeCurrent += InDeltaTime;

	if (BoxSpawnCoolTimeCurrent > BoxSpawnCoolTimeMax)
	{
		BoxSpawnCoolTimeCurrent = 0.f;
		AddBox(InDeltaTime);
	}
	BoxAttackObject(InDeltaTime);
}

void CStage1::BoxAttackObject(float InDeltaTime)
{
	std::vector<CObject*> OBJvector = Get_Object(OBJ_LAYER::MONSTER);

	for (int i = 0; i < OBJvector.size(); ++i)
	{
		BoxAttackObjectSpawnCoolTimeCurrent = OBJvector[i]->GetDeltaTime();
		BoxAttackObjectSpawnCoolTimeCurrent += InDeltaTime;

		if (BoxAttackObjectSpawnCoolTimeCurrent < BoxAttackObjectSpawnCoolTimeMax)
		{
			OBJvector[i]->SetDeltaTime(BoxAttackObjectSpawnCoolTimeCurrent);
			continue;
		}

		if (BoxAttackObjectSpawnCoolTimeCurrent > BoxAttackObjectSpawnCoolTimeMax)
		{
			CObject* BoxAttack = new BoxObject(Vector2D{ OBJvector[i]->GetPosition().x, OBJvector[i]->GetPosition().y }, Vector2D{ 20,20 }, 1200);
			BoxAttack->SetObjectType(EOBJ_TYPE::MonsterSkill);
			BoxAttack->SetObjectLayer(OBJ_LAYER::MONSTERSKILL);
			BoxAttack->SetTexture(CResourceManager::GetInstance()->FindTexture("Bullet"));
			OBJvector[i]->SetDeltaTime(0.f);

			AddObject(BoxAttack);
		}
	}
}
