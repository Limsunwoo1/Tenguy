#pragma once
#include "CScene.h"
class CStage1 :
    public CScene
{
private:

public:
    CStage1();
    ~CStage1();

    virtual void Init() override;	// ������ �ʿ��� ������Ʈ���� ��ü���� �����ؼ� �����Ѵ�
    virtual void Clear() override;   // ���� ���� ������ ���� �Ҹ��Ų��

    virtual void Update(float InDeltaTime) override;
};

