#pragma once
#include "CScene.h"
#include "Object.h"
#include "Array.h"

class CStage1 :
    public CScene
{
private:
    CObject* Player;

    float	BoxSpawnCoolTimeMax;
    float	BoxSpawnCoolTimeCurrent;

    float	BoxAttackObjectSpawnCoolTimeMax;
    float	BoxAttackObjectSpawnCoolTimeCurrent;
    float	BoxAttackObjectSpawnTimeCurrent;
public:
    CStage1();
    ~CStage1();

    virtual void Init() override;	// 씬에서 필요한 오브젝트같은 객체들을 생성해서 세팅한다
    virtual void Clear() override;   // 현재 씬의 정보를 전부 소멸시킨다
    virtual void  Update(float InDeltaTime) override;
    void BoxAttackObject(float InDeltaTime);
};

