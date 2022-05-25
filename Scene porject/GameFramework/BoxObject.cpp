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
	MonsterSkill_Hit();
	MonsterHit();
}

void BoxObject::BoxRemove()
{
	std::vector<CObject*> Monster = CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::MONSTER);

	for (int i = 0; i < Monster.size(); ++i)
	{
		if (Monster[i]->GetPosition().x <= 0)
		{
			//std::cout << "박스 삭제" << std::endl;
			CSceneManager::GetInstance()->SetVectorSize(OBJ_LAYER::MONSTER, i);
		}
	}

	std::vector<CObject*> MonsterSkill = CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::MONSTERSKILL);
	for (int i = 0; i < MonsterSkill.size(); ++i)
	{
		if (MonsterSkill[i]->GetPosition().x <= 0)
		{
			//std::cout << "박스 삭제" << std::endl;
			CSceneManager::GetInstance()->SetVectorSize(OBJ_LAYER::MONSTERSKILL, i);
		}
	}
}

void BoxObject::MonsterHit()
{
	std::vector<CObject*> InVecotr = CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::MONSTER);
	std::vector<CObject*> Player = CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::PLAYER);
	for (int i = 0; i < InVecotr.size(); ++i)
	{
		for (int j = 0; i < Player.size(); ++i)
		{
			if (!CheckCollision(InVecotr[i]->GetPosition(), InVecotr[i]->GetScale(), Player[j]->GetPosition(), Player[j]->GetScale()))
				continue;
			std::cout << Player.size() << std::endl;
			CSceneManager::GetInstance()->SetVectorSize(OBJ_LAYER::MONSTER, i);
			break;
			//std::cout << "충돌" << std::endl;
		}
	}

	InVecotr = CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::MONSTER);
	std::vector<CObject*> Bullet = CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::BULLET);
	for (int i = 0; i < InVecotr.size(); ++i)
	{
		for (int j = 0; i < Bullet.size(); ++i)
		{
			if (!CheckCollision(InVecotr[i]->GetPosition(), InVecotr[i]->GetScale(), Bullet[j]->GetPosition(), Bullet[j]->GetScale()))
				continue;

			CSceneManager::GetInstance()->SetVectorSize(OBJ_LAYER::MONSTER, i);
			CSceneManager::GetInstance()->SetVectorSize(OBJ_LAYER::BULLET, j);
			break;
			//std::cout << "충돌" << std::endl;
		}
	}
}

void BoxObject::MonsterSkill_Hit()
{
	std::vector<CObject*> InVecotr = CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::MONSTERSKILL);
	std::vector<CObject*> Bullet = CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::BULLET);
	for (int i = 0; i < InVecotr.size(); ++i)
	{
		for (int j = 0; i < Bullet.size(); ++i)
		{
			if (!CheckCollision(InVecotr[j]->GetPosition(), InVecotr[j]->GetScale(), Bullet[j]->GetPosition(), Bullet[j]->GetScale()))
				continue;

			CSceneManager::GetInstance()->SetVectorSize(OBJ_LAYER::MONSTERSKILL, i);
			//std::cout << "충돌" << std::endl;
		}
	}

	InVecotr = CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::MONSTERSKILL);
	for (int i = 0; i < InVecotr.size(); ++i)
	{
		for (int j = 0; i < Bullet.size(); ++i)
		{
			if (!CheckCollision(Position, Scale, Bullet[j]->GetPosition(), Bullet[j]->GetScale()))
				continue;

			CSceneManager::GetInstance()->SetVectorSize(OBJ_LAYER::MONSTERSKILL, i);
			CSceneManager::GetInstance()->SetVectorSize(OBJ_LAYER::BULLET, j);
			//std::cout << "충돌" << std::endl;
		}
	}
}