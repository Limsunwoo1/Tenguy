#pragma once
#include "Object.h"
class CUI :
    public CObject
{
private:
    bool IsMouseOn;     // ���콺�� �÷����ִ°�
    bool IsMousePrs;    // ���콺�� ���ȴ°�

public:
    CUI();
    CUI(Vector2D InPosition, Vector2D InScale);
    virtual ~CUI();

    virtual void MouseFirstOn() {}            // ���콺�� �������� ���� ���
    virtual void MouseOn() {}                 // ���콺�� �������� ���� ���
    virtual void MouseFirstOff() {}           // ���콺�� ���� ���� ���� ��� ȣ��

                                              // Ŭ���� ��ư�� �������� ���� �߻��Ѵ�
    virtual void MouseLButtonPress() {}       // ���� ���콺 ��ư�� �������� ��
    virtual void MouseLButtonRelease() {}     // ���� ���콺 ��ư�� �������� ����
    virtual void MouseRButtonPress() {}       // ������ ���콺 ��ư�� �������� ��
    virtual void MouseRButtonRelease() {}     // ������ ���콺 ��ư�� �������� ����

public:
    void SetMouseOn(bool InMouseOn) {IsMouseOn = InMouseOn;}
    bool GetMouseOn() {return IsMouseOn;}

    void SetMousePrs(bool InMousePrs) { IsMousePrs = InMousePrs; }
    bool GetMousePrs() { return IsMousePrs; }

};

