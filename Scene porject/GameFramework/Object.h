#pragma once
#include "framework.h"

class CTexture;

enum class EOBJ_TYPE {
	BackGrund,
	MonsterSkill,
	Monster,
	Bullet,
	Player,
	UI,
	Max,
};

enum class OBJ_LAYER : char { // LAYER : char 모르겠음
	BACKGROUND		= 0,
	MONSTERSKILL	= 6,
	MONSTER			= 12,
	BULLET			= 18,
	PLAYER			= 24,
	UI				= 30,
	MAX,
};

class CObject
{
protected:
	Vector2D		Position;
	Vector2D		Scale;
	EOBJ_TYPE		ObjType;
	OBJ_LAYER		ObjLayer;

	CTexture*		Texture;
	
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

	void SetObjectType(EOBJ_TYPE objType);
	EOBJ_TYPE GetObjectType();

	void SetDeltaTime(float InDeltaTime);
	float GetDeltaTime();	

	void SetTexture(CTexture* InTexture);

	OBJ_LAYER GetObjectLayer();
	void SetObjectLayer(OBJ_LAYER InOBJ_Layer);
};

