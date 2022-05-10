#pragma once
#include <vector>
#include "Object.h"
class CScene
{
private:
	 std::vector<CObject*> OBJvector;
	 CObject* Box;
public:
	CScene();
	virtual ~CScene();

	virtual void Init();	// ������ �ʿ��� ������Ʈ���� ��ü���� �����ؼ� �����Ѵ�
	virtual void Clear();   // ���� ���� ������ ���� �Ҹ��Ų��

	// ���������� �ʿ��Ҽ����ְ� �ʿ�������� �ִ�
	virtual void Update(float InDeltaTime) ;
	void SetVectorSize(std::vector<CObject*>& InVC);
	void AddObject(CObject* InObject);
	void AddBox(float InDeltaTime);

	virtual void BoxAttackObject(float InDeltaTime) {};
	std::vector<CObject*>& Get_Object();
	void Render(HDC InHdc);
	bool Player_Hit();
	void ClearObject();
};

