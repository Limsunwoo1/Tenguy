#pragma once
#include "Object.h"
class BoxObject : public CObject
{
protected:
	int speed;
public:
	BoxObject();
	BoxObject(Vector2D InPoint, Vector2D InScale, int Speed);
	virtual ~BoxObject();

	virtual void Update(float InDeltaTime) override;
	void BoxRemove();
	void Hit();

};

