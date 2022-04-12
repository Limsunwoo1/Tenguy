#pragma once
#include "Define.h"

class CScene;

class CSceneManager
{
	SINGLE(CSceneManager);

private:
	CScene*	 CurScene;

public:
	void Init();
	void Update(float InDeltaTime);

	void SetCurScene(CScene* InNewScene);
};

