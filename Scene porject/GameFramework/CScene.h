#pragma once
class CScene
{
private:

	// std::vector<CObject*> OBJvector;
public:
	CScene();
	virtual ~CScene();

	virtual void Init();	// ������ �ʿ��� ������Ʈ���� ��ü���� �����ؼ� �����Ѵ�
	virtual void Clear();   // ���� ���� ������ ���� �Ҹ��Ų��

	// ���������� �ʿ��Ҽ����ְ� �ʿ�������� �ִ�
	virtual void Update(float InDeltaTime) {}
	// virtual void Render(HDC InHdc);
};

