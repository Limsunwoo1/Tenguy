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

    virtual void Init() override;	// ������ �ʿ��� ������Ʈ���� ��ü���� �����ؼ� �����Ѵ�
    virtual void Clear() override;   // ���� ���� ������ ���� �Ҹ��Ų��
    virtual void  Update(float InDeltaTime) override;
    void BoxAttackObject(float InDeltaTime);
};

