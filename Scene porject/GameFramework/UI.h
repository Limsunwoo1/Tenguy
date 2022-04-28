#pragma once
#include "Object.h"
class CUI :
    public CObject
{
private:
    bool IsMouseOn;     // 마우스가 올려져있는가
    bool IsMousePrs;    // 마우스가 눌렸는가

public:
    CUI();
    CUI(Vector2D InPosition, Vector2D InScale);
    virtual ~CUI();

    virtual void MouseFirstOn() {}            // 마우스가 영역으로 들어온 경우
    virtual void MouseOn() {}                 // 마우스가 영역으로 들어온 경우
    virtual void MouseFirstOff() {}           // 마우스가 영역 밖을 나간 경우 호출

                                              // 클릭은 버튼이 떼어지는 순간 발생한다
    virtual void MouseLButtonPress() {}       // 왼쪽 마우스 버튼이 눌려지는 중
    virtual void MouseLButtonRelease() {}     // 왼쪽 마우스 버튼이 떼어지는 순간
    virtual void MouseRButtonPress() {}       // 오른쪽 마우스 버튼이 눌려지는 중
    virtual void MouseRButtonRelease() {}     // 오른쪽 마우스 버튼이 떼어지는 순간

public:
    void SetMouseOn(bool InMouseOn) {IsMouseOn = InMouseOn;}
    bool GetMouseOn() {return IsMouseOn;}

    void SetMousePrs(bool InMousePrs) { IsMousePrs = InMousePrs; }
    bool GetMousePrs() { return IsMousePrs; }

};

