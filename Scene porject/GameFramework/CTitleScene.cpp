#include "CTitleScene.h"
#include "Button.h"
#include "UIManager.h"
#include <string>
#include "Func.h"
#include "CSceneManager.h"
#include "CStage1.h"
#include "UI.h"

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
	/*for (int i = 0;i < TiltleUI.size();i++)
	{
		delete TiltleUI[i];
	}*/
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
	for (int i = 0; i < TiltleUI.size(); i++)
	{
		if (TiltleUI[i]->GetMouseOn() == true && TiltleUI[i]->GetMousePrs() == true)
		{
			CScene* Stage1 = new CStage1();
			CSceneManager::GetInstance()->SetCurScene(Stage1);
			break;
		}
		else
		{
			continue;
		}
	}

}