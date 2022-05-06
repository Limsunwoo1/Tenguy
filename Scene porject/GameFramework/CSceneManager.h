#pragma once
#include "Define.h"
#include "Object.h"
#include <vector>

class CScene;

class CSceneManager
{
	SINGLE(CSceneManager);

private:
	CScene*	 CurScene;     //잠시내림

    CObject* Bullet;
    //CObject* Box;
    CObject* BoxAttack;

    POINT BoxAttackObjectPosition;

    float	BoxSpawnCoolTimeMax;
    float	BoxSpawnCoolTimeCurrent;

    float	BoxAttackObjectSpawnCoolTimeMax;
    float	BoxAttackObjectSpawnCoolTimeCurrent;
    float	BoxAttackObjectSpawnTimeCurrent;

public:
	void Init();
	void Update(float InDeltaTime);
    void Render(HDC InHdc);

	void SetCurScene(CScene* InNewScene);
	void AddObject(CObject* InObject);
    //void AddBox(float InDeltaTime);

    void BoxAttackObject(float InDeltaTime);
    bool Player_Hit();
    void SetVectorSize(std::vector<CObject*> InVC);
    std::vector<CObject*> Get_Object();

};

