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

	// c_str() : vector<char> ������ string ������ char const* ���·� ��ȯ����
	TextOutA(InHdc, Position.x - (ButtonText.size() * 5.f), Position.y, ButtonText.c_str(), ButtonText.size());
	// ��Ʈ���� Ư¡�� �ٸ��� ���� ����� ���ĺ����� �۾��� ���̰� �ٸ�
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