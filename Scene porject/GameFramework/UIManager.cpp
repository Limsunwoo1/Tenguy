#include "UIManager.h"
#include "UI.h"
#include "Button.h"
#include "KeyManager.h"

UIManager::UIManager()
{
	
}

UIManager::~UIManager()
{
	for (CUI* myUI : MyUIList)
		delete myUI;

	MyUIList.clear();
}

void UIManager::Init()
{
	
}

void UIManager::Clear(vector<CUI*> InCUI)
{
	/*for (CUI* myUI : MyUIList)
		delete myUI;

	MyUIList.clear();*/
}

void UIManager::Update(float InDeltaTime)
{
	if (MyUIList.size() == 0)
		return;

	for (CUI* myUI : MyUIList)
	{
		bool isColiision = CheckMouseCollision(myUI);

		// 마우스 커서 좌표와 충돌한 경우
		if (isColiision && !myUI->GetMouseOn())
		{
			myUI->MouseFirstOn();
			myUI->SetMouseOn(true);
		}
		else if (isColiision && myUI->GetMouseOn())
		{
			myUI->MouseOn();
		}
		// 충돌하지는 않았지만 이전에 마우스 온 함수가 호출된 경우
		else if(!isColiision && myUI->GetMouseOn())
		{
			myUI->MouseFirstOff();
			myUI->SetMouseOn(false);
		}

		if (isColiision)
		{
			if (KEY_STATE(KEY::LBUTTON) == KEY_STATE::HOLD)
			{
				myUI->MouseLButtonPress();
				myUI->SetMousePrs(true);
			}
			else if (KEY_STATE(KEY::LBUTTON) == KEY_STATE::AWAY)
			{
				myUI->MouseLButtonRelease();
				myUI->SetMousePrs(false);
			}
			if (KEY_STATE(KEY::RBUTTON) == KEY_STATE::HOLD)
				myUI->MouseRButtonPress();
			else if (KEY_STATE(KEY::RBUTTON) == KEY_STATE::AWAY)
				myUI->MouseRButtonRelease();
		}

		myUI->Update(InDeltaTime);
	}
}

void UIManager::Render(HDC Inhdc)
{
	if (MyUIList.size() == 0)
		return;

	for (CUI* myUI : MyUIList)
		myUI->Render(Inhdc);
}

void UIManager::AddUI(CUI* InUI)
{
	MyUIList.push_back(InUI);
}

bool UIManager::CheckMouseCollision(CUI* InUI)
{
	POINT mousePos = MOUSE_POS;

	Vector2D UIPos = InUI->GetPosition();
	Vector2D UIScale = InUI->GetScale();

	if (mousePos.x < UIPos.x - (UIScale.x * 0.5f))
		return false;
	if (mousePos.x > UIPos.x + (UIScale.x * 0.5f))
		return false;
	if (mousePos.y < UIPos.y - (UIScale.y * 0.5f))
		return false;
	if (mousePos.y > UIPos.y + (UIScale.y * 0.5f))
		return false;

	return true;
}

void UIManager::SetUI(vector<CUI*> InCUI)
{
	if (InCUI.size() == 0)
		MyUIList.clear();

	for (CUI* myCUI : InCUI)
	{
		AddUI(myCUI);
	}
}
