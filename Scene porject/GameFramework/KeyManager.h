#pragma once
#include "framework.h"
#include "Define.h"
#include <vector>
using namespace std;

enum class KEY_STATE
{
	NONE,	// �ȴ���
	TAP,	// ó�� ���� ���
	HOLD,	// ������ �ִ� ���
	AWAY,	// �� ���
};

enum class KEY
{
	SPACE,
	LBUTTON,
	RBUTTON,
	W,
	A,
	S,
	D,
	MAX,
};

typedef struct _KeyInfo {
	KEY_STATE	KeyState; // �ش� Ű�� ���� ����
	bool		PrevPush; // ������ ���ȴ��� ����
}KeyInfo;

class CKeyManager
{
	SINGLE(CKeyManager);

private:
	vector<KeyInfo> KeyInfoArr;
	POINT			MousePos;

public:
	void Init();
	void Update(float InDeltaTime);

	KEY_STATE GetKeyState(KEY InKey);
	POINT GetMousePos() { return MousePos; }
};

