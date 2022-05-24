#include "BoxObject.h"
#include "ObjectManager.h" 
#include <iostream>
#include <vector>
#include "Func.h"
#include "CSceneManager.h"

BoxObject::BoxObject()
{

}

BoxObject::BoxObject(Vector2D InPoint, Vector2D InScale,int Speed) :
	CObject(InPoint, InScale)
{
	this->speed = Speed;
}

BoxObject::~BoxObject()
{

}

void BoxObject::Update(float InDeltaTime)
{
	Position.x -= speed * InDeltaTime;
	BoxRemove();
	Hit();
}

void BoxObject::BoxRemove()
{
	std::vector<CObject*> InVecotr = CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::MONSTER);

	for (int i = 0; i < InVecotr.size(); ++i)
	{
		if (InVecotr[i]->GetObjectType() == EOBJ_TYPE::ELLIPSE)
			continue;

		if (InVecotr[i]->GetPosition().x <= 0)
		{
			CSceneManager::GetInstance()->SetVectorSize(OBJ_LAYER::MONSTER, i);
		}
	}
}

void BoxObject::Hit()
{
	std::vector<CObject*> InVecotr = CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::MONSTER);

	for (int i = 0; i < InVecotr.size(); ++i)
	{

		if (InVecotr[i]->GetObjectType() != EOBJ_TYPE::ELLIPSE)
			continue;
			
		if (!CheckCollision(Position, Scale, InVecotr[i]->GetPosition(), InVecotr[i]->GetScale()))
				continue;

		CSceneManager::GetInstance()->SetVectorSize(OBJ_LAYER::MONSTER, i);

 		int cnt = 0;
		std::vector<CObject*> InVecotr2 = CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::MONSTER);

		for (int i = 0; i < InVecotr2.size(); ++i)
		{
			if (Position.x == InVecotr2[i]->GetPosition().x && Position.y == InVecotr2[i]->GetPosition().y && InVecotr2[i]->GetObjectType() == EOBJ_TYPE::ELLIPSE)
			{
				cnt = i;
				break;
			}
		}
		//std::cout << "Ãæµ¹" << std::endl;
		InVecotr2.erase(InVecotr2.begin() + cnt);
		CSceneManager::GetInstance()->SetVectorSize(OBJ_LAYER::MONSTER, i);
		InVecotr2.clear();
	}
}