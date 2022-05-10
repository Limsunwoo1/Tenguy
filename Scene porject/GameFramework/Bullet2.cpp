#include "Bullet2.h"
#include "CSceneManager.h"

Bullet2::Bullet2()
	:CObject()
{

}
Bullet2::Bullet2(Vector2D InPosition, Vector2D InScale)
	: CObject(InPosition, InScale)
{

}

Bullet2::~Bullet2()
{

}

void Bullet2::Update(float InDeltaTime)
{
	Position.y -= 2100 * InDeltaTime;
	Bullet2Remove();
}

void Bullet2::Bullet2Remove()
{
	for (int i = 0; i < CSceneManager::GetInstance()->Get_Object().size(); ++i)
	{
		std::vector<CObject*> InVecotr = CSceneManager::GetInstance()->Get_Object();

		if (InVecotr[i]->GetObjectType() == EOBJ_TYPE::ELLIPSE)
		{
			if (InVecotr[i]->GetPosition().x >= 980)
			{
				InVecotr.erase(InVecotr.begin() + i);
				CSceneManager::GetInstance()->SetVectorSize(InVecotr);
				InVecotr.clear();
				break;
			}
		}
		else
		{

		}
	}
}