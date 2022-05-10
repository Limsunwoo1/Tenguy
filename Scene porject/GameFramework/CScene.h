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

	virtual void Init();	// 씬에서 필요한 오브젝트같은 객체들을 생성해서 세팅한다
	virtual void Clear();   // 현재 씬의 정보를 전부 소멸시킨다

	// 구조에따라 필요할수도있고 필요없을수도 있다
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

