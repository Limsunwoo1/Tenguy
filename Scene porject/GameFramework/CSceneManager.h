#pragma once
#include "Define.h"

class CScene;

class CSceneManager
{
	SINGLE(CSceneManager);

private:

public:
	CScene*	 CurScene;     //��ó���
	void Init();
	void Update(float InDeltaTime);

	void SetCurScene(CScene* InNewScene);
};

