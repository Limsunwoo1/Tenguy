#pragma once
#include "Array.h"
#include "Object.h"
#include "Define.h"
#include "Player.h"
#include <vector>
#define USER = 0;
#define DP_BULLET = 1;
#define HURDLE = 2;


class ObjectManager
{
	SINGLE(ObjectManager);
private:
	CObject* Player;
	CPlayer* testPobj;
public:
	void Init();
	void Update(float InDeltaTime);
	void Render(HDC Inhdc);
	void SetPlayer(CPlayer* InPlayer);
	CPlayer* GetPlayer();
	CPlayer* Dynamic_Cast(CObject* InPlayer);
};

