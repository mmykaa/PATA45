#include "LonerEnemy.h"
#include "World.h"
#include "EnemyBullet.h"
#include "EngineTime.h"
#include <iostream>



Uint32 Fire(Uint32 interval, void* data)
{
	EnemyBullet* bullet = nullptr;
	bullet = new EnemyBullet(new Properties("EnemyBullet", ((LonerEnemy*)data)->m_Body->GetPosition().x, 
		((LonerEnemy*)data)->m_Body->GetPosition().y + 50, 16, 16, SDL_FLIP_NONE));
	
	World::GetInstance()->LoadObjects(bullet);


	return interval;
}


LonerEnemy::LonerEnemy(Properties* props) : BaseEnemy(props)
{
	m_GoingRight = true;

	m_MaxHealth = { 1 };

	m_CurrentHealth = m_MaxHealth;

	
}


void LonerEnemy::Init()
{
	__super::Init();



	EngineTime::GetInstance()->StartTimer(5000, Fire, (LonerEnemy*)this);

	//Handle Animations
	m_Animation->SetProperties("Loner", 1, 0, 16, 50, true);

}

void LonerEnemy::Draw()
{
	__super::Draw();
}

void LonerEnemy::Update(float deltaTime)
{
	__super::Update(deltaTime);

	m_Animation->Update(deltaTime);

	SetOriginPoint();

	//Handle Movement
	if (m_GoingRight && m_Body->GetPosition().x < 960 - m_Width / 2)
	{
		m_Body->SetLinearVelocity(b2Vec2(1.5f, 0.4f));
	}

	if (m_GoingRight && m_Body->GetPosition().x >= 960 - m_Width / 2)
	{
		m_GoingRight = false;
	}

	if (!m_GoingRight && m_Body->GetPosition().x > 900 - m_Width / 2)
	{
		m_Body->SetLinearVelocity(b2Vec2(-1.5f, 0.4f));
	}

	if (!m_GoingRight && m_Body->GetPosition().x <= 0 + m_Width / 2)
	{
		m_GoingRight = true;
	}

	//Handle Out of screen destroy
	if (m_Body->GetPosition().y > 640.0f + m_Height / 2 && !m_IsDead)
	{
		m_IsDead = true;
		m_Body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));

	}

	if (m_IsDead)
	{
		m_Animation->SetProperties("ExplosionMob", 1, 0, 11, 50, false);

		if (GetAnimation()->GetCurrentSprite() >= 10)
		{
			Clean();
		}
	}
}


void LonerEnemy::TakeDamage(int inDamage)
{
	m_CurrentHealth -= inDamage;

	if (m_CurrentHealth <= 0)
	{
		m_IsDead = true;
		m_Body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));

		m_Animation->SetProperties("ExplosionMob", 1, 0, 11, 50, false);
	}
}

void LonerEnemy::SetOriginPoint()
{
	m_Origin->X = m_Body->GetPosition().x;
	m_Origin->Y = m_Body->GetPosition().y;

}

void LonerEnemy::Clean()
{
	World::GetInstance()->DestroyGameObject(this, m_Body);
}

void LonerEnemy::CheckCollision(GameObject* otherGameObject)
{

}




