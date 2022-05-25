#include "CScene.h"
#include <vector>
#include "Object.h"
#include "Func.h"
#include "ObjectManager.h"
#include "BoxObject.h"
#include <random>
#include <iostream>
#include "Box2.h"
#include "ResourceManager.h"
using namespace std;

HBRUSH BLACK = CreateSolidBrush(RGB(0, 0, 0));
HBRUSH RED = CreateSolidBrush(RGB(255, 0, 0));
HBRUSH GREEN = CreateSolidBrush(RGB(0, 128, 0));
HBRUSH BACKGROUND = CreateSolidBrush(RGB(255, 255, 255));

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(0, 980);
uniform_int_distribution<int> Dis(50, 150);

CScene::CScene()
{

}

CScene::~CScene()
{

}

void CScene::Init()
{
	CObject* Backgruond = new CObject(Vector2D((float)0, (float)0), Vector2D((float)980, (float)680));
	Backgruond->SetObjectType(EOBJ_TYPE::BackGrund);
	Backgruond->SetObjectLayer(OBJ_LAYER::BACKGROUND);
	Backgruond->SetTexture(CResourceManager::GetInstance()->FindTexture("BACKGRUOND"));

	AddObject(Backgruond);
}

void CScene::Clear()
{
	ClearObject();
}

void CScene::Update(float InDeltaTime)
{
	for (int layer = (int)OBJ_LAYER::BACKGROUND; layer < (int)OBJ_LAYER::MAX; ++layer)
	{
		for (int i = 0; i < OBJvector[layer].size(); ++i)
		{
			OBJvector[layer][i]->Update(InDeltaTime);
		}
	}
}

void CScene::AddObject(CObject* InObject)
{
	if (InObject->GetObjectType() == EOBJ_TYPE::Player)
		OBJvector[(int)OBJ_LAYER::PLAYER].push_back(InObject);
	else if (InObject->GetObjectType() == EOBJ_TYPE::BackGrund)
		OBJvector[(int)OBJ_LAYER::BACKGROUND].push_back(InObject);
	else if (InObject->GetObjectType() == EOBJ_TYPE::Monster)
		OBJvector[(int)OBJ_LAYER::MONSTER].push_back(InObject);
	else if (InObject->GetObjectType() == EOBJ_TYPE::MonsterSkill)
		OBJvector[(int)OBJ_LAYER::MONSTERSKILL].push_back(InObject);
	else if (InObject->GetObjectType() == EOBJ_TYPE::Bullet)
		OBJvector[(int)OBJ_LAYER::BULLET].push_back(InObject);
	else if (InObject->GetObjectType() == EOBJ_TYPE::UI)
		OBJvector[(int)OBJ_LAYER::UI].push_back(InObject);
}

void CScene::AddBox(float InDeltaTime)
{
	if (ObjectManager::GetInstance()->GetPlayer() == nullptr)
		return;

	float rand = (float)Dis(gen);

	if (ObjectManager::GetInstance()->GetPlayer()->GetStageCode() == 1)
	{
		CObject* Box = new BoxObject(Vector2D{ (float)980 ,(float)dis(gen) }, Vector2D{ rand ,rand }, 600);
		Box->SetObjectType(EOBJ_TYPE::Monster);
		Box->SetObjectLayer(OBJ_LAYER::MONSTER);
		Box->SetDeltaTime(0);
		Box->SetTexture(CResourceManager::GetInstance()->FindTexture("MONSTER"));
		AddObject(Box);
	}

	if (ObjectManager::GetInstance()->GetPlayer()->GetStageCode() == 2)
	{
		CObject* Box = new Box2(Vector2D{ (float)dis(gen) ,(float)0 }, Vector2D{ rand ,rand }, 600);
		Box->SetObjectType(EOBJ_TYPE::Monster);
		Box->SetObjectLayer(OBJ_LAYER::MONSTER);
		Box->SetDeltaTime(0);
		Box->SetTexture(CResourceManager::GetInstance()->FindTexture("MONSTER"));
		AddObject(Box);
	}
}

const std::vector<CObject*>& CScene::Get_Object(OBJ_LAYER InLayer)
{
	return OBJvector[(int)InLayer];
}

void CScene::SetVectorSize(OBJ_LAYER InLayer, int count)
{
	delete OBJvector[(int)InLayer][count];
	OBJvector[(int)InLayer].erase((OBJvector[(int)InLayer].begin() + count));
}

void CScene::Render(HDC InHdc)
{
	for (int layer = (int)OBJ_LAYER::BACKGROUND; layer < (int)OBJ_LAYER::MAX; ++layer)
	{
		for (int i = 0; i < OBJvector[layer].size(); ++i)
		{
			OBJvector[layer][i]->Render(InHdc);
		}
	}
 }

bool CScene::Player_Hit()
{
	CObject* Player = ObjectManager::GetInstance()->GetPlayer();

	for (int i = 0;i < OBJvector[(int)OBJ_LAYER::MONSTER].size(); ++i)
	{
		if (!CheckCollision(Player->GetPosition(), Player->GetScale(), OBJvector[(int)OBJ_LAYER::MONSTER][i]->GetPosition(),
			OBJvector[(int)OBJ_LAYER::MONSTER][i]->GetScale()))
			continue;

		delete* (OBJvector[(int)OBJ_LAYER::MONSTER].begin() + i);
		OBJvector[(int)OBJ_LAYER::MONSTER].erase(OBJvector[(int)OBJ_LAYER::MONSTER].begin() + i);
		return true;
	}
	return false;
}

void CScene::ClearObject()
{
	vector<CObject*>::iterator iter;
	for (int layer = 0; layer < (int)OBJ_LAYER::MAX; ++layer)
	{
		if (layer == (int)OBJ_LAYER::PLAYER)
			continue;

		for (iter = OBJvector[layer].begin();iter != OBJvector[layer].end();iter++)
		{
			delete *iter;
		}
	}
}