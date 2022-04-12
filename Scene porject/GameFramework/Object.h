#pragma once
#include "framework.h"

enum class EOBJ_TYPE {
	RECTANGLE,
	ELLIPSE,
	Player,
	Bullet,
	Max,
};

class CObject
{
protected:
	Vector2D		Position;
	Vector2D		Scale;
	EOBJ_TYPE		ObjType;
	
	float			ObjDeletaTime = 0.f;
public:
	CObject();
	CObject(Vector2D InPosition, Vector2D InScale);
	virtual ~CObject();

	void SetPosition(Vector2D InPosition) { Position = InPosition; }
	Vector2D GetPosition() { return Position; }

	void SetScale(Vector2D InScale) { Scale = InScale; }
	Vector2D GetScale() { return Scale; }

	void SetType(EOBJ_TYPE InType) { ObjType = InType; }

	virtual void Update(float InDeltaTime);
	virtual void Render(HDC InHdc);
	//bool InTerSect(const CObject* InPosition);

	void SetObjectType(EOBJ_TYPE objType);
	EOBJ_TYPE GetObjectType();

	void SetDeltaTime(float InDeltaTime);
	float GetDeltaTime();	
};

