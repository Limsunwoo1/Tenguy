#pragma once
#include "CScene.h"
#include "Button.h"
#include <vector>
class CTitleScene :
    public CScene
{
protected:
    std::vector <CUI*> TiltleUI;
public:

    CTitleScene();
    ~CTitleScene();

    virtual void Init() override;	// ������ �ʿ��� ������Ʈ���� ��ü���� �����ؼ� �����Ѵ�
    virtual void Clear() override;   // ���� ���� ������ ���� �Ҹ��Ų��

    virtual void Update(float InDeltaTime) override;

    bool GetTrue() { return test; };

};

