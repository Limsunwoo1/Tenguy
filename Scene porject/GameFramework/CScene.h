#pragma once
#include <vector>
#include "Object.h"
class CScene
{
private:
	std::vector<CObject*> OBJvector[(int)OBJ_LAYER::MAX];
public:
	CScene();
	virtual ~CScene();

	virtual void Init();	// ������ �ʿ��� ������Ʈ���� ��ü���� �����ؼ� �����Ѵ�
	virtual void Clear();   // ���� ���� ������ ���� �Ҹ��Ų��

	// ���������� �ʿ��Ҽ����ְ� �ʿ�������� �ִ�
	virtual void Update(float InDeltaTime) ;
	void SetVectorSize(OBJ_LAYER InLayer, int count);
	void AddObject(CObject* InObject);
	void AddBox(float InDeltaTime);

	virtual void BoxAttackObject(float InDeltaTime) {};
	const std::vector<CObject*>& Get_Object(OBJ_LAYER InLayer);
	void Render(HDC InHdc);
	bool Player_Hit();
	void ClearObject();
};

