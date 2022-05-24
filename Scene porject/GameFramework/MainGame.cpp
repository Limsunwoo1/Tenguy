#include "MainGame.h"
#include "TimerManager.h"
#include "KeyManager.h"
#include "UIManager.h"
#include "CSceneManager.h"
#include "Player.h"
#include <iostream>
#include <windows.h>
#include "ResourceManager.h"
//std::random_device rd;
//std::mt19937 gen(rd());
//std::uniform_int_distribution<int> dis(0, 980);
//std::uniform_int_distribution<int> Dis(50, 150);

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

	//delete Player;
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
	CSceneManager::GetInstance()->Init();
	UIManager::GetInstance()->Init();
	CResourceManager::GetInstance()->Init(HInstance, Hdc);
	//

	// 더블버퍼링
	BackHdc = CreateCompatibleDC(Hdc);
	BackBitMap = CreateCompatibleBitmap(Hdc, 1920, 1080);
	BitMap = (HBITMAP)SelectObject(BackHdc, BackBitMap);   
	// ====================================

	
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

	// ====================================
	CKeyManager::GetInstance()->Update(InDeltaTime);
	CSceneManager::GetInstance()->Update(InDeltaTime);
	ObjectManager::GetInstance()->Update(InDeltaTime);
	UIManager::GetInstance()->Update(InDeltaTime);
	// ====================================

}

void CMainGame::Render()
{
	// ====================================
	Rectangle(BackHdc, 0, 0, 980, 680);

	ObjectManager::GetInstance()->Render(BackHdc);
	CSceneManager::GetInstance()->Render(BackHdc);
	UIManager::GetInstance()->Render(BackHdc);

	BitBlt(Hdc, 0, 0, 980, 680, BackHdc, 0, 0, SRCCOPY);
	// ====================================
}

