#include "Button.h"
#include <iostream>
using namespace std;

CButton::CButton(Vector2D InPosition, Vector2D InScale)
: CUI(InPosition, InScale)
, ButtonText("GAME")
{
	
}

CButton::~CButton()
{

}

void CButton::Render(HDC InHdc)
{
	CObject::Render(InHdc);

	// c_str() : vector<char> 형태의 string 변수를 char const* 형태로 반환해줌
	TextOutA(InHdc, Position.x - (ButtonText.size() * 5.f), Position.y, ButtonText.c_str(), ButtonText.size());
	// 폰트마다 특징이 다른데 보통 영어는 알파벳마다 글씨의 길이가 다름
}

void CButton::MouseFirstOn()
{
	cout << __FUNCTION__ << endl;
	
}

void CButton::MouseOn()
{

}

void CButton::MouseFirstOff()
{
	cout << __FUNCTION__ << endl;
	//CurButton = true;
}

void CButton::MouseLButtonPress()
{
	cout << __FUNCTION__ << endl;
	//CurButton = true;
}

void CButton::MouseLButtonRelease()
{
	cout << __FUNCTION__ << endl;
}

void CButton::MouseRButtonPress()
{
	cout << __FUNCTION__ << endl;
}

void CButton::MouseRButtonRelease()
{
	cout << __FUNCTION__ << endl;
}