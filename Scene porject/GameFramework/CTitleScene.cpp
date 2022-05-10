#include "CTitleScene.h"
#include "Button.h"
#include "UIManager.h"
#include <string>
#include "Func.h"
#include "CSceneManager.h"
#include "CStage1.h"
#include "UI.h"
#include "CStage2.h"

CTitleScene::CTitleScene() 
{
	string Text_1 = "STAGE 1";
	CButton* button = new CButton(Vector2D(500.f, 200.f), Vector2D(400.f, 150.f));
	button->SetButtonText(Text_1);
	TiltleUI.push_back(button);

	string Text_2 = "STAGE 2";
	CButton* Button = new CButton(Vector2D(500.f, 500.f), Vector2D(400.f, 150.f));
	Button->SetButtonText(Text_2);
	TiltleUI.push_back(Button);
}

CTitleScene::~CTitleScene()
{
	delete TiltleUI[0];
	delete TiltleUI[1];
}

void CTitleScene::Init()
{
	UIManager::GetInstance()->SetUI(TiltleUI);
}

void CTitleScene::Clear()
{	
	TiltleUI.clear();
	UIManager::GetInstance()->SetUI(TiltleUI);
}

void CTitleScene::Update(float InDeltaTime)
{
	if (TiltleUI[0]->GetMouseOn() == true && TiltleUI[0]->GetMousePrs() == true)
	{
		CScene* Stage1 = new CStage1();
		CSceneManager::GetInstance()->SetCurScene(Stage1);
		return;
	}
	if (TiltleUI[1]->GetMouseOn() == true && TiltleUI[1]->GetMousePrs() == true)
	{
		CScene* Stage2 = new CStage2();
		CSceneManager::GetInstance()->SetCurScene(Stage2);
		return;
	}
}