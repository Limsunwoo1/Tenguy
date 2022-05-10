#pragma once
#include "BoxObject.h"

class Box2 :
    public BoxObject
{
private:
    int speed;
public:
    Box2();
    Box2(Vector2D InPoint, Vector2D InScale, int Speed);
    ~Box2();

    virtual void Update(float InDeltaTime) override;
    void BoxRemove();
};

