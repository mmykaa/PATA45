#include "LonerEnemy.h"

LonerEnemy::LonerEnemy(Properties* props) : BaseEnemy(props)
{

}

void LonerEnemy::Init()
{
	__super::Init();
}

void LonerEnemy::Draw()
{
	__super::Draw();
}

void LonerEnemy::Update(float deltaTime)
{
	__super::Update(deltaTime);
}

void LonerEnemy::Clean()
{
	__super::Clean();
}

void LonerEnemy::CheckColision()
{
	__super::CheckColision();
}
