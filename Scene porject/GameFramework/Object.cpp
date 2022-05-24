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

OBJ_LAYER CObject::GetObjectLayer()
{
	return ObjLayer;
}
void CObject::SetObjectLayer(OBJ_LAYER InOBJ_Laye)
{
	ObjLayer = InOBJ_Laye;
}

void CObject::Update(float InDeltaTime)
{

}

 void CObject::Render(HDC InHdc)
{
	 if (Texture)
	 {
		 if (ObjType == EOBJ_TYPE::Player)
		 {
			 BitBlt(InHdc,
				 Position.x - (Scale.x * 0.5f),
				 Position.y - (Scale.y * 0.5f),
				 //Scale.x,
				 //Scale.y,
				 Texture->GetWidth(),
				 Texture->GetHeight(),
				 Texture->GetHdc(),
				 0,
				 0,
				 SRCCOPY);
		 }
		 else if (ObjType == EOBJ_TYPE::ELLIPSE)
		 {
			 BitBlt(InHdc,
				 Position.x - (Scale.x * 0.5f),
				 Position.y - (Scale.y * 0.5f),
				 //Scale.x,
				 //Scale.y,
				 Texture->GetWidth(),
				 Texture->GetHeight(),
				 Texture->GetHdc(),
				 0,
				 0,
				 SRCCOPY);
		 }
		 else if ( ObjType == EOBJ_TYPE::Bullet)
		 {
			 BitBlt(InHdc,
				 Position.x - (Scale.x * 0.5f),
				 Position.y - (Scale.y * 0.5f),
				 //Scale.x,
				 //Scale.y,
				 Texture->GetWidth(),
				 Texture->GetHeight(),
				 Texture->GetHdc(),
				 0,
				 0,
				 SRCCOPY);
		 }
		 else if (ObjType == EOBJ_TYPE::RECTANGLE)
		 {
			 BitBlt(InHdc,
				 Position.x - (Scale.x * 0.5f),
				 Position.y - (Scale.y * 0.5f),
				 //Scale.x,
				 //Scale.y,
				 Texture->GetWidth(),
				 Texture->GetHeight(),
				 Texture->GetHdc(),
				 0,
				 0,
				 SRCCOPY);
		 }
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
		 if (ObjType == EOBJ_TYPE::BackGrund)
		 {
			 Rectangle(InHdc,
				 Position.x,
				 Position.y ,
				 Scale.x,
				 Scale.y);
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