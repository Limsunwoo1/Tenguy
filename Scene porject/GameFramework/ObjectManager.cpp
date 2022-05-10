#include "ObjectManager.h"
#include <iostream>
#include "framework.h"
#include "Func.h"
#include "Player.h"
#include <windows.h>
#include "CSceneManager.h"

 HBRUSH BLACK_ = CreateSolidBrush(RGB(0, 0, 0));
 //HBRUSH RED = CreateSolidBrush(RGB(255, 0, 0));
 HBRUSH GREEN_ = CreateSolidBrush(RGB(0, 128, 0));
 HBRUSH BACKGROUND_ = CreateSolidBrush(RGB(255, 255, 255));

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{

}

void ObjectManager::Init()
{

}

void ObjectManager::Update(float InDeltaTime)
{
	if (Player)
		Player->Update(InDeltaTime);
}

void ObjectManager::Render(HDC Inhdc)
{

	SelectObject(Inhdc, GREEN_);
	if (Player)
		Player->Render(Inhdc);

	if (Player)
	{
		testPobj = static_cast<CPlayer*>(Player);

		wchar_t buffer[100] = {};
		swprintf_s(buffer, L"%d", testPobj->GetPlayerLIfe());

		SelectObject(Inhdc, BLACK_);
		TextOut(Inhdc, Player->GetPosition().x, Player->GetPosition().y, buffer, 1); // 플레이어의 라이프 표시

	}
	SelectObject(Inhdc, BACKGROUND_);
}

void ObjectManager::SetPlayer(CPlayer* InPayer)
{
	Player = InPayer;
}

CPlayer* ObjectManager::GetPlayer()
{
	return testPobj = static_cast<CPlayer*>(Player);;
}

CPlayer* ObjectManager:: Dynamic_Cast(CObject* InPlayer)
{
	testPobj = static_cast<CPlayer*>(Player);
	return static_cast<CPlayer*>(InPlayer);

}

