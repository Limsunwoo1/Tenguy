#pragma once
#include "Object.h"
#include "ObjectManager.h"
class BulletObject :public CObject
{
	
public:

	BulletObject();
	BulletObject(Vector2D InPosition, Vector2D InScale);
	virtual ~BulletObject();

	virtual void Update(float InDeltaTime) override;
	/*virtual void Render(HDC InHdc) override;*/

	void BulletRemove();
	//void BulletInterSet();

};



