#include "MainGame.h"
#include "TimerManager.h"
#include "KeyManager.h"
#include "UIManager.h"
#include "CSceneManager.h"
#include "Player.h"
#include <iostream>
#include <windows.h>
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(0, 980);
std::uniform_int_distribution<int> Dis(50, 150);

// ����
// 1. ����� ����غ��鼭 �����ϱ�
// 2. Scene ���� �����ϱ�
// 3. �ּ� Title, Stage1, Stage2 �� �����غ���
//		Stage1, Stage2 ���� ���� ��� Title �� ���ƿ;� �Ѵ�.
//		Title ���� Stage1, Stage2 �� ��ٷ� �� �� �־�� �Ѵ�.
//		Title ���� ���� ���� ȭ���� ���̵���
// 4. Scene ���� ������ MainGame �� ���� ���ʿ��� ���� ���� ���� �ű��
//		( MainGame�� ���� ������ �ʿ��� Manager�� Ŭ���� �� �ֿ� ������ ���ư��� �Ѵ� )

// ������ ������
// Texture �̹���, �ִϸ��̼�

CMainGame::CMainGame()
{

}

CMainGame::~CMainGame()
{
	// ====================================
	SelectObject(BackHdc, BitMap);
	DeleteObject(BackBitMap);
	DeleteDC(BackHdc);
	// ====================================

	delete Player;
}

void CMainGame::Init(HWND InHwnd, HINSTANCE InHInstance)
{
	// ====================================
	HInstance = InHInstance;
	Hwnd = InHwnd;
	Hdc = GetDC(Hwnd);

	// �̱��ϵ� �ʱ�ȭ ����
	ObjectManager::GetInstance()->Init();
	CTimerManager::GetInstance()->Init();
	CKeyManager::GetInstance()->Init();
	UIManager::GetInstance()->Init();
	CSceneManager::GetInstance()->Init();
	//

	// ������۸�
	BackHdc = CreateCompatibleDC(Hdc);
	BackBitMap = CreateCompatibleBitmap(Hdc, 1920, 1080);
	BitMap = (HBITMAP)SelectObject(BackHdc, BackBitMap);   
	// ====================================

	Player = new CPlayer();
	Player->SetObjectType(EOBJ_TYPE::Player);
	ObjectManager::GetInstance()->SetPlayer(Player);

	BoxSpawnCoolTimeMax = 0.3f;
	BoxSpawnCoolTimeCurrent = 0.f;

	BoxAttackObjectSpawnCoolTimeMax = 0.1f;
	BoxAttackObjectSpawnCoolTimeCurrent = 0.f;
}

void CMainGame::Logic()
{
	// ====================================
	CTimerManager::GetInstance()->Update();
	float deltaTime = CTimerManager::GetInstance()->GetDeltaTime();
	Update(deltaTime);
	Render();
	// ====================================
}

void CMainGame::Update(float InDeltaTime)
{
	CObject* test_Obj = ObjectManager::GetInstance()->GetPlayer();        //�� ��ȯ
	CPlayer* testPobj = static_cast<CPlayer*>(test_Obj);

	// ====================================
	CKeyManager::GetInstance()->Update(InDeltaTime);
	CSceneManager::GetInstance()->Update(InDeltaTime);
	ObjectManager::GetInstance()->Update(InDeltaTime);
	UIManager::GetInstance()->Update(InDeltaTime);
	// ====================================

	static float currdelta;

	/*if (testPobj->GetPlayerLIfe() == 0)
		DestroyWindow(Hwnd);*/

	currdelta += InDeltaTime;
	
	if (ObjectManager::GetInstance()->Player_Hit() == true)
	{
		if (currdelta > 1.0f)
		{
			testPobj->SetPlayerLIfe(testPobj->GetPlayerLIfe() - 1);
			currdelta = 0.f;
		}
	}
	

	BoxSpawnCoolTimeCurrent += InDeltaTime;

	if (BoxSpawnCoolTimeCurrent > BoxSpawnCoolTimeMax)
	{
		BoxSpawnCoolTimeCurrent = 0.f;
		AddBox(InDeltaTime);
	}

	BoxAttackObject(InDeltaTime);           //������ ���鼭 ��ǥ�� üũ	 �� ������ ������ �ڽ�������Ʈ�� �������� ������ �Ҽ� �ְ��ؾ���
}

void CMainGame::Render()
{
	// ====================================
	Rectangle(BackHdc, 0, 0, 980, 680);

	ObjectManager::GetInstance()->Render(BackHdc);
	UIManager::GetInstance()->Render(BackHdc);

	BitBlt(Hdc, 0, 0, 980, 680, BackHdc, 0, 0, SRCCOPY);
	// ====================================
}

void CMainGame::AddBox(float InDeltaTime)
{
	float rand = (float)Dis(gen);
	Box = new BoxObject(Vector2D{ (float)980 ,(float)dis(gen) }, Vector2D{ rand ,rand }, 600);
	Box->SetObjectType(EOBJ_TYPE::RECTANGLE);
	Box->SetDeltaTime(InDeltaTime);
	ObjectManager::GetInstance()->AddObject(Box);
}

void CMainGame::BoxAttackObject(float InDeltaTime)
{
	vector<CObject*> InVect = ObjectManager::GetInstance()->Get_Object();
	for (int i = 0; i < InVect.size(); ++i)
	{
		if (InVect[i]->GetObjectType() != EOBJ_TYPE::RECTANGLE)
			continue;

		BoxAttackObjectSpawnCoolTimeCurrent = InVect[i]->GetDeltaTime();
		BoxAttackObjectSpawnCoolTimeCurrent += InDeltaTime;

		if (BoxAttackObjectSpawnCoolTimeCurrent < BoxAttackObjectSpawnCoolTimeMax)
		{
			InVect[i]->SetDeltaTime(BoxAttackObjectSpawnCoolTimeCurrent);
			continue;
		}

		if (BoxAttackObjectSpawnCoolTimeCurrent > BoxAttackObjectSpawnCoolTimeMax)
		{
			BoxAttack = new BoxObject(Vector2D{ InVect[i]->GetPosition().x, InVect[i]->GetPosition().y }, Vector2D{ 20,20 }, 1200);
			BoxAttack->SetObjectType(EOBJ_TYPE::Bullet);
			InVect[i]->SetDeltaTime(0.f);

			ObjectManager::GetInstance()->AddObject(BoxAttack);
		}
	}
}