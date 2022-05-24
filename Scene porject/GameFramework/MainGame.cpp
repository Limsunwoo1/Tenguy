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

	//delete Player;
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
	CSceneManager::GetInstance()->Init();
	UIManager::GetInstance()->Init();
	CResourceManager::GetInstance()->Init(HInstance, Hdc);
	//

	// ������۸�
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

