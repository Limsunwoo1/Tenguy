#pragma once
#include "CScene.h"
#include "Object.h"
#include "Array.h"

class CStage1 :
    public CScene
{
private:
    CArray<CObject*> ObjectArray;
    CObject* Player;
    CObject* Bullet;
    CObject* Box;
    CObject* BoxAttack;

    POINT BoxAttackObjectPosition;

    float	BoxSpawnCoolTimeMax;
    float	BoxSpawnCoolTimeCurrent;

    float	BoxAttackObjectSpawnCoolTimeMax;
    float	BoxAttackObjectSpawnCoolTimeCurrent;
    float	BoxAttackObjectSpawnTimeCurrent;

public:
    CStage1();
    ~CStage1();

    virtual void Init() override;	// ������ �ʿ��� ������Ʈ���� ��ü���� �����ؼ� �����Ѵ�
    virtual void Clear() override;   // ���� ���� ������ ���� �Ҹ��Ų��

    virtual void Update(float InDeltaTime) override;

public:
    virtual void AddBox(float InDeltaTime) override;
    virtual void BoxAttackObject(float InDeltaTime) override;
};

