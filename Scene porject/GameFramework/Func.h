#pragma once
#include <windows.h>


// �ζ��� �Լ�
// �Լ��� ����� ���ÿ� ��ü���� �����ϴ� �Լ�
inline bool CheckCollision(Vector2D InPosition1, Vector2D InScale1, Vector2D InPosition2, Vector2D InScale2)
{
	if (InPosition1.x + (InScale1.x * 0.5) < InPosition2.x - (InScale2.x * 0.5) ||
		InPosition1.x - (InScale1.x * 0.5) > InPosition2.x + (InScale2.x * 0.5))
		return false;

	if (InPosition1.y + (InScale1.y * 0.5) < InPosition2.y - (InScale2.y * 0.5) ||
		InPosition1.y - (InScale1.y * 0.5) > InPosition2.y + (InScale2.y * 0.5))
		return false;

	return true;
}