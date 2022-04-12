#pragma once
#include "Define.h"
#include <windows.h>
#include <vector>

class CUI;

class UIManager
{
	SINGLE(UIManager);

private:
	std::vector<CUI*> MyUIList;

public:
	void Init();
	void Update(float InDeltaTime);
	void Render(HDC Inhdc);

	void AddUI(CUI* InUI);

	bool CheckMouseCollision(CUI* InUI);
};

