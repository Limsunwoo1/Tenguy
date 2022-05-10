#pragma once
#include "Object.h"
class Bullet2 :
    public CObject
{
public:
    Bullet2();
    Bullet2(Vector2D InPosition, Vector2D InScale);
    ~Bullet2();

    virtual void Update(float InDeltaTime) override;
    void Bullet2Remove();
};

