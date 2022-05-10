#pragma once
#include "CScene.h"
#include "Player.h"

class CStage2 :
    public CScene
{
private:

public:
    CPlayer* Player;

    float	BoxSpawnCoolTimeMax;
    float	BoxSpawnCoolTimeCurrent;

    float	BoxAttackObjectSpawnCoolTimeMax;
    float	BoxAttackObjectSpawnCoolTimeCurrent;
    float	BoxAttackObjectSpawnTimeCurrent;
public:
    CStage2();
    ~CStage2();

    virtual void Init() override;	// ������ �ʿ��� ������Ʈ���� ��ü���� �����ؼ� �����Ѵ�
    virtual void Clear() override;   // ���� ���� ������ ���� �Ҹ��Ų��
    virtual void  Update(float InDeltaTime) override;

    void BoxAttackObject(float InDeltaTime);
};

