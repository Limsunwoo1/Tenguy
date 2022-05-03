#include "Player.h"
#include "KeyManager.h"
#include "ObjectManager.h"
#include "BulletObject.h"
#include "CSceneManager.h"

CPlayer::CPlayer() : CObject(Vector2D{ 100, 100 }, Vector2D{ 50, 50 })
{
	this->life = 3;

	BulletSpawnCoolTimeMax = 0.1f;
	BulletSpawnCollTimeCurrent = 0.f;
}

CPlayer::CPlayer(Vector2D& InVector, Vector2D& InScale) : CObject(Vector2D{ InVector.x , InVector.y }, Vector2D{ InScale.x, InScale.y })
{
	this->life = 3;

	BulletSpawnCoolTimeMax = 0.1f;
	BulletSpawnCollTimeCurrent = 0.f;
}
 
CPlayer::~CPlayer()
{

}

void CPlayer::Update(float InDeltaTime)
{
	BulletSpawnCollTimeCurrent += InDeltaTime;     //이부분 이해도 늘리기 += 하면 작동 = 하면 작동 x 

	if (KEY_STATE(KEY::SPACE) == KEY_STATE::HOLD)
	{
		if (BulletSpawnCollTimeCurrent > BulletSpawnCoolTimeMax)
		{
			Vector2D PST = Position;

			BulletObject* Bullet = new BulletObject(Vector2D{ PST.x ,PST.y }, Vector2D{ 20 ,20 });
			Bullet->SetObjectType(EOBJ_TYPE::ELLIPSE);
			CSceneManager::GetInstance()->AddObject(Bullet);

			BulletSpawnCollTimeCurrent = 0.f;
		}
	}

	if (KEY_STATE(KEY::W) == KEY_STATE::HOLD)
	{
		Vector2D position = Position;
		position.y -= 1500 * InDeltaTime;

		if (position.y <= 20)
		{
			position.y = 20;
		}

		Position = position;
	}

	if (KEY_STATE(KEY::A) == KEY_STATE::HOLD)
	{
		Vector2D position = Position;
		position.x -= 1500 * InDeltaTime;

		if (position.x < 20)
		{
			position.x = 20;
		}

		Position = position;
	}

	if (KEY_STATE(KEY::S) == KEY_STATE::HOLD)
	{
		Vector2D position = Position;
		position.y += 1500 * InDeltaTime;

		if (position.y > 620)
		{
			position.y = 620;
		}

		Position = position;
	}

	if (KEY_STATE(KEY::D) == KEY_STATE::HOLD)
	{
		Vector2D position = Position;
		position.x += 1500 * InDeltaTime;

		if (position.x > 940)
		{
			position.x = 940;
		}

		Position = position;
	}

}

void CPlayer::SetPlayerLIfe(int SetLife)
{
	this->life = SetLife;
}

int CPlayer::GetPlayerLIfe()
{
	if (this == nullptr)
		return 0;

	return this->life;
}