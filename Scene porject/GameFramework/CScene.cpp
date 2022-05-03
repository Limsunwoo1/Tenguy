#include "CScene.h"
#include <vector>
#include "Object.h"
#include "Func.h"
#include "ObjectManager.h"

HBRUSH BLACK = CreateSolidBrush(RGB(0, 0, 0));
HBRUSH RED = CreateSolidBrush(RGB(255, 0, 0));
HBRUSH GREEN = CreateSolidBrush(RGB(0, 128, 0));
HBRUSH BACKGROUND = CreateSolidBrush(RGB(255, 255, 255));

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

}
void CScene::Update(float InDeltaTime)
{
	for (int i = 0; i < OBJvector.size(); ++i)
	{
		OBJvector[i]->Update(InDeltaTime);
	}
}


void CScene::AddObject(CObject* InObject)
{
	OBJvector.push_back(InObject);
}

std::vector<CObject*> CScene::Get_Object()
{
	return OBJvector;
}

void CScene::SetVectorSize(std::vector<CObject*> InVC)
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
