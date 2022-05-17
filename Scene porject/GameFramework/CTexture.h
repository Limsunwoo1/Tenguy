#pragma once
#include <windows.h>
#include <string>
using namespace std;

class CTexture
{
private:
	wstring FilePath;
	string Name;

	HDC			Hdc;
	HBITMAP		TextureHandle;
	HBITMAP		OldTextureHandle;
	BITMAP		TextureInfo;
public:
	CTexture();
	~CTexture();

	HDC GetHdc() { return Hdc; }

	unsigned int GetWidth() { return TextureInfo.bmWidth; }
	unsigned int GetHeight() { return TextureInfo.bmHeight; }

	const string& GetName() { return Name; }

	bool LoadTexture(const string& InName, HINSTANCE InHINst, HDC InHdc, const wstring& InFilePath);
};