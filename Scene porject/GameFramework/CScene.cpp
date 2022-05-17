#include "CScene.h"
#include <vector>
#include "Object.h"
#include "Func.h"
#include "ObjectManager.h"
#include "BoxObject.h"
#include <random>
#include <iostream>
#include "Box2.h"
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
	
}

void CScene::Clear()
{
	ClearObject();
}
void CScene::Update(float InDeltaTime)
{
	
}


void CScene::AddObject(CObject* InObject)
{
	OBJvector.push_back(InObject);
}

void CScene::AddBox(float InDeltaTime)
{
	if (ObjectManager::GetInstance()->GetPlayer() == nullptr)
		return;

	float rand = (float)Dis(gen);

	if (ObjectManager::GetInstance()->GetPlayer()->GetStageCode() == 1)
	{
		Box = new BoxObject(Vector2D{ (float)980 ,(float)dis(gen) }, Vector2D{ rand ,rand }, 600);
		Box->SetObjectType(EOBJ_TYPE::RECTANGLE);
		Box->SetDeltaTime(InDeltaTime);
		AddObject(Box);
	}

	if (ObjectManager::GetInstance()->GetPlayer()->GetStageCode() == 2)
	{
		Box = new Box2(Vector2D{ (float)dis(gen) ,(float)0 }, Vector2D{ rand ,rand }, 600);
		Box->SetObjectType(EOBJ_TYPE::RECTANGLE);
		Box->SetDeltaTime(InDeltaTime);
		AddObject(Box);
	}
}

std::vector<CObject*>& CScene::Get_Object()
{
	return OBJvector;
}

void CScene::SetVectorSize(std::vector<CObject*>& InVC)
{
	OBJvector.swap(InVC);
}

void CScene::Render(HDC InHdc)
{
	for (int i = 0; i < OBJvector.size(); ++i)
	{
		if (OBJvector[i]->GetObjectType() == EOBJ_TYPE::RECTANGLE)
		{
			SelectObject(InHdc, BLACK);
		}
		else if (OBJvector[i]->GetObjectType() == EOBJ_TYPE::ELLIPSE)
		{
			SelectObject(InHdc, RED);
		}
		else if (OBJvector[i]->GetObjectType() == EOBJ_TYPE::Bullet)
		{
			SelectObject(InHdc, BLACK);
		}
		OBJvector[i]->Render(InHdc);
	}
	SelectObject(InHdc, BACKGROUND);
 }

bool CScene::Player_Hit()
{
	CObject* Player = ObjectManager::GetInstance()->GetPlayer();

	for (int i = 0;i < OBJvector.size(); ++i)
	{
		if (OBJvector[i]->GetObjectType() == EOBJ_TYPE::RECTANGLE || OBJvector[i]->GetObjectType() == EOBJ_TYPE::Bullet)
		{
			if (!CheckCollision(Player->GetPosition(), Player->GetScale(), OBJvector[i]->GetPosition(), OBJvector[i]->GetScale()))
				continue;

			delete* (OBJvector.begin() + i);
			OBJvector.erase(OBJvector.begin() + i);
			return true;
		}
	}
	return false;
}

void CScene::ClearObject()
{
	vector<CObject*>::iterator iter;
	for (iter = OBJvector.begin();iter != OBJvector.end();iter++)
	{
		delete* iter;
	}
}