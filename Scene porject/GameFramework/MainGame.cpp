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

// 과제
// 1. 깃허브 사용해보면서 개발하기
// 2. Scene 구조 구현하기
// 3. 최소 Title, Stage1, Stage2 씬 구현해보기
//		Stage1, Stage2 에서 죽은 경우 Title 로 돌아와야 한다.
//		Title 에서 Stage1, Stage2 을 곧바로 들어갈 수 있어야 한다.
//		Title 에서 게임 시작 화면이 보이도록
// 4. Scene 구조 구현후 MainGame 에 기존 불필요한 게임 로직 전부 옮길것
//		( MainGame은 게임 구동에 필요한 Manager급 클래스 등 주요 로직만 돌아가야 한다 )

// 다음에 나갈것
// Texture 이미지, 애니메이션

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

	// 싱글턴들 초기화 구간
	ObjectManager::GetInstance()->Init();
	CTimerManager::GetInstance()->Init();
	CKeyManager::GetInstance()->Init();
	UIManager::GetInstance()->Init();
	CSceneManager::GetInstance()->Init();
	//

	// 더블버퍼링
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
	CObject* test_Obj = ObjectManager::GetInstance()->GetPlayer();        //형 변환
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

	BoxAttackObject(InDeltaTime);           //루프를 돌면서 좌표값 체크	 및 이전에 생성된 박스오브젝트가 지속적인 공격을 할수 있게해야함
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