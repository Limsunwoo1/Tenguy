#pragma once
#include "UI.h"
#include <string>
using namespace std;

class CButton :
    public CUI
{
private:
    string ButtonText;
public:
    CButton(Vector2D InPosition, Vector2D InScale);
    virtual ~CButton();

    virtual void Render(HDC InHdc) override;

    virtual void MouseFirstOn() override;
    virtual void MouseOn() override;
    virtual void MouseFirstOff() override;

    virtual void MouseLButtonPress() override;
    virtual void MouseLButtonRelease() override;
    virtual void MouseRButtonPress() override;
    virtual void MouseRButtonRelease() override;

public:
    void SetButtonText(const string& InButtonText) { ButtonText = InButtonText; }
};

