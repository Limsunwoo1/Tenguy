#pragma once
#include "CScene.h"
class CTitleScene :
    public CScene
{
private:

public:
    CTitleScene();
    ~CTitleScene();

    virtual void Init() override;	// ������ �ʿ��� ������Ʈ���� ��ü���� �����ؼ� �����Ѵ�
    virtual void Clear() override;   // ���� ���� ������ ���� �Ҹ��Ų��

    virtual void Update(float InDeltaTime) override;
};

