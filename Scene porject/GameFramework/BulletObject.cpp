#include "BulletObject.h"
#include <iostream>
#include "CSceneManager.h"
BulletObject::BulletObject()
	:CObject()
{

}
BulletObject::BulletObject(Vector2D InPosition, Vector2D InScale)
	: CObject(InPosition, InScale) 
{
	
}

BulletObject::~BulletObject()
{
	
}

void BulletObject::Update(float InDeltaTime)
{
	Position.x += 2100 * InDeltaTime;
	//BulletInterSet();
	BulletRemove();
 }

void BulletObject::BulletRemove()
{
	for (int i = 0; i < CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::MONSTER).size(); ++i)
	{
		std::vector<CObject*> InVecotr = CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::MONSTER);

		if (InVecotr[i]->GetObjectType() == EOBJ_TYPE::ELLIPSE)
		{
			if (InVecotr[i]->GetPosition().x >= 980)
			{
				CSceneManager::GetInstance()->SetVectorSize(OBJ_LAYER::MONSTER, i);
				break;
			}
		}
		else
		{

		}
		
	}
}