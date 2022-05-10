#pragma once
#include "Object.h"
class CPlayer :
    public CObject
{
    int Speed;
    int life;
    int stage_code;

    float	BulletSpawnCoolTimeMax;
    float   BulletSpawnCollTimeCurrent;
public:
    CPlayer();
    CPlayer(Vector2D InVector, Vector2D InScale);
    ~CPlayer();

    virtual void Update(float InDeltaTime) override;
    void SetPlayerLIfe(int SetLife);
    int GetPlayerLIfe();
    void SetStageCode(int InCode) { stage_code = InCode; };
    int GetStageCode() {return stage_code;}
};

