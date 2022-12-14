#include "RusherEnemy.h"
#include "BaseEnemy.h"
#include "World.h"



RusherEnemy::RusherEnemy(Properties* props) : BaseEnemy(props)
{
	m_MaxHealth = { 1 };

	m_CurrentHealth = m_MaxHealth;
}

void RusherEnemy::Init()
{
	__super::Init();

	//Handle Animations
	m_Animation->SetProperties("Rusher", 1, 0, 24, 50, true);
	m_Body->SetLinearVelocity(b2Vec2(0.f, 1.5f));

}

void RusherEnemy::Draw()
{
	__super::Draw();
}

void RusherEnemy::Update(float deltaTime)
{
	__super::Update(deltaTime);

	SetOriginPoint();

	if (m_Body->GetPosition().y > 700.0f && !m_IsDead && m_Body != nullptr)
	{
		m_IsDead = true;
		m_Height = m_Width;
		if (!World::GetInstance()->GetWorld()->IsLocked())
		{
			m_Body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
		}
		m_Animation->SetProperties("ExplosionMob", 1, 0, 11, 150, false);
		m_Animation->SetCurrentSprite(0);

	}

	if (m_IsDead)
	{
		if (GetAnimation()->GetCurrentSprite() >= 10)
		{
			Clean();
		}
	}

	m_Animation->Update(deltaTime);

}

void RusherEnemy::TakeDamage(int inDamage)
{
	m_CurrentHealth -= inDamage;

	if (m_CurrentHealth <= 0 && !m_IsDead)
	{
		m_IsDead = true;
		m_Height = m_Width;
		if (!World::GetInstance()->GetWorld()->IsLocked())
		{
			m_Body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
		}
		m_Animation->SetProperties("ExplosionMob", 1, 0, 11, 150, false);
		m_Animation->SetCurrentSprite(0);
	}
}

void RusherEnemy::SetOriginPoint()
{
	if (m_Body == nullptr)
	{
		return;
	}

	m_Origin->X = m_Body->GetPosition().x;
	m_Origin->Y = m_Body->GetPosition().y;
}

void RusherEnemy::Clean()
{
	m_PendingKill = true;
	//World::GetInstance()->DestroyGameObject(this, m_Body);
}

void RusherEnemy::CheckCollision(GameObject* otherGameObject)
{

}
