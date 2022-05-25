#include "Player.h"
#include "KeyManager.h"
#include "ObjectManager.h"
#include "BulletObject.h"
#include "CSceneManager.h"
#include "Bullet2.h"
#include "ResourceManager.h"
CPlayer::CPlayer() : CObject(Vector2D{ 100, 100 }, Vector2D{ 50, 50 })
{
	this->life = 3;
	stage_code = 1;
	BulletSpawnCoolTimeMax = 0.1f;
	BulletSpawnCollTimeCurrent = 0.f;
}

CPlayer::CPlayer(Vector2D InVector, Vector2D InScale) : CObject(Vector2D{ InVector.x , InVector.y }, Vector2D{ InScale.x, InScale.y })
{
	this->life = 3;
	stage_code = 2;
	BulletSpawnCoolTimeMax = 0.1f;
	BulletSpawnCollTimeCurrent = 0.f;
}
 
CPlayer::~CPlayer()
{

}

void CPlayer::Update(float InDeltaTime)
{
	BulletSpawnCollTimeCurrent += InDeltaTime;   
	if (stage_code == 1)
	{
		if (KEY_STATE(KEY::SPACE) == KEY_STATE::HOLD)
		{
			if (BulletSpawnCollTimeCurrent > BulletSpawnCoolTimeMax)
			{
				Vector2D PST = Position;

				CObject* Bullet = new BulletObject(Vector2D{ PST.x ,PST.y }, Vector2D{ 20 ,20 });
				Bullet->SetObjectType(EOBJ_TYPE::Bullet);
				Bullet->SetObjectLayer(OBJ_LAYER::BULLET);
				Bullet->SetTexture(CResourceManager::GetInstance()->FindTexture("Bullet"));
				CSceneManager::GetInstance()->AddObject(Bullet);

				BulletSpawnCollTimeCurrent = 0.f;
			}
		}
	}

	if (stage_code == 2)
	{
		if (KEY_STATE(KEY::SPACE) == KEY_STATE::HOLD)
		{
			if (BulletSpawnCollTimeCurrent > BulletSpawnCoolTimeMax)
			{
				Vector2D PST = Position;

				CObject* Bullet = new Bullet2(Vector2D{ PST.x ,PST.y }, Vector2D{ 20 ,20 });
				Bullet->SetObjectType(EOBJ_TYPE::Bullet);
				Bullet->SetObjectLayer(OBJ_LAYER::BULLET);
				Bullet->SetTexture(CResourceManager::GetInstance()->FindTexture("Bullet"));
				CSceneManager::GetInstance()->AddObject(Bullet);

				BulletSpawnCollTimeCurrent = 0.f;
			}
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