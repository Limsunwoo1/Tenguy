#pragma once
#include "Define.h"
#include <windows.h>
#include <vector>
#include "Button.h"
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

	void SetUI(vector<CUI*> InCUI);
	void Clear(vector<CUI*> InCUI);

};

