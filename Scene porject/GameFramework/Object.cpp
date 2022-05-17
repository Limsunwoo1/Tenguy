#include "Object.h"
#include "CTexture.h"
CObject::CObject()
	: Position()
	, Scale()
	, ObjType(EOBJ_TYPE::RECTANGLE)
{

}
CObject::CObject(Vector2D InPosition, Vector2D InScale)
	: Position(InPosition)
	, Scale(InScale)
	, ObjType(EOBJ_TYPE::RECTANGLE)
{
	
}
CObject::~CObject()
{

}

void CObject::SetTexture(CTexture* InTexture)
{
	Texture = InTexture;
}

void CObject::Update(float InDeltaTime)
{

}

 void CObject::Render(HDC InHdc)
{
	 if (Texture)
	 {

	 }
	 else
	 {
		 if (ObjType == EOBJ_TYPE::RECTANGLE || ObjType == EOBJ_TYPE::Player)
		 {
			 Rectangle(InHdc,
				 Position.x - (Scale.x * 0.5f),
				 Position.y - (Scale.y * 0.5f),
				 Position.x + (Scale.x * 0.5f),
				 Position.y + (Scale.y * 0.5f));
		 }
		 if (ObjType == EOBJ_TYPE::ELLIPSE || ObjType == EOBJ_TYPE::Bullet)
		 {
			 Ellipse(InHdc,
				 Position.x - (Scale.x * 0.5f),
				 Position.y - (Scale.y * 0.5f),
				 Position.x + (Scale.x * 0.5f),
				 Position.y + (Scale.y * 0.5f));
		 }
	 }
}

 void CObject::SetObjectType(EOBJ_TYPE objType)
 {
	 ObjType = objType;
 }

 EOBJ_TYPE CObject::GetObjectType()
 {
	 return ObjType;
 }

 void CObject::SetDeltaTime(float InDeltaTime)
 {
	 ObjDeletaTime = InDeltaTime;
 }
 float CObject::GetDeltaTime()
 {
	 return ObjDeletaTime;
 }