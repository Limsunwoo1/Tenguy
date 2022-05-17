#include "CTexture.h"
CTexture::CTexture()
{

}
CTexture::~CTexture()
{
	SelectObject(Hdc, OldTextureHandle);

	DeleteObject(TextureHandle);

	DeleteDC(Hdc);
}


bool CTexture::LoadTexture(const string& InName, HINSTANCE InHInst, HDC InHdc, const wstring& InFilePath)
{
	Name = InName;
	FilePath = InFilePath;

	TextureHandle = (HBITMAP)LoadImageW(InHInst, InFilePath.c_str(),    //Load �Լ� �𸣰���
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);     // �Ʒ� ������ �𸣰���

	Hdc = CreateCompatibleDC(InHdc);
	
	OldTextureHandle = (HBITMAP)SelectObject(Hdc, TextureHandle);

	GetObject(TextureHandle, sizeof(TextureInfo), &TextureInfo);

	return true;
}
