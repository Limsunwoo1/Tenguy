#pragma once
#include "CScene.h"
class CStage2 :
    public CScene
{
private:

public:
    CStage2();
    ~CStage2();

    virtual void Init() override;	// ������ �ʿ��� ������Ʈ���� ��ü���� �����ؼ� �����Ѵ�
    virtual void Clear() override;   // ���� ���� ������ ���� �Ҹ��Ų��

    virtual void Update(float InDeltaTime) override;
};

