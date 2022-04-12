#pragma once
#include "Define.h"
#include <windows.h>

class CTimerManager
{
	SINGLE(CTimerManager);
private:
// -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807
	LARGE_INTEGER CurTickCount;
	LARGE_INTEGER PrevTickCount;
	LARGE_INTEGER Frequency;

	double DeltaTime;		// �ð� ��ȭ��
	// Acc : �����̶�� �ǹ̷� ���α׷��ֿ��� ���
	double AccDeltaTime;		// ���� ��Ÿ Ÿ��
	int CallCount;			// �Լ� ȣ�� Ƚ��
	int FramePerSecond;		// �ʴ� ������ Ƚ��

public:
	void Init();
	void Update();

	double GetDeltaTime() {return DeltaTime;}
};

