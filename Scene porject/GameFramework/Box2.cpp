#include "Box2.h"
#include "CSceneManager.h"
#include <vector>
#include "Func.h"

Box2::Box2()
{

}

Box2::Box2(Vector2D InPoint, Vector2D InScale, int Speed) :
	BoxObject(InPoint, InScale, Speed)
{
	this->speed = Speed;
}

Box2::~Box2()
{

}

void Box2::Update(float InDeltaTime)
{
	Position.y += speed * InDeltaTime;
	BoxRemove();
	Hit();
}

void Box2::BoxRemove()
{
	std::vector<CObject*> InVecotr = CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::MONSTER);

	for (int i = 0; i < InVecotr.size(); ++i)
	{
		if (InVecotr[i]->GetObjectType() == EOBJ_TYPE::ELLIPSE)
			continue;

		if (InVecotr[i]->GetPosition().y >= 980)
		{
			CSceneManager::GetInstance()->SetVectorSize(OBJ_LAYER::MONSTER, i);
		}
	}
}
