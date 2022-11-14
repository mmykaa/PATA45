#include "Player.h"
#include "../Graphics/TextureManager.h"
#include "../Core/InputHandler.h"
#include "../Core/CodingHelper.h"

Player::Player(Properties* props) : Character(props) {
	
	m_Animation = new Animation();
	SetAnimationState(Idle, 0);

	CodingHelper::GetInstance()->IncrementAmountToClearCounter(1);
}


Player::~Player()
{
    delete m_Animation;

	CodingHelper::GetInstance()->DecrementAmountToClearCounter(1);
}


void Player::Draw()
{
	m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}


void Player::Update(float deltaTime)
{
	HandleInput();
	SetOriginPoint();
    m_Animation->Update(deltaTime);
}



void Player::HandleInput()
{

	if (InputHandler::GetInstance()->GetAxisKeys(HORIZONTAL) > -1 && InputHandler::GetInstance()->GetAxisKeys(HORIZONTAL) < 1)
	{
		SetAnimationState(Idle, 0);
	}
	
	if (InputHandler::GetInstance()->GetAxisKeys(HORIZONTAL) == 1)
	{
 		SetAnimationState(MovingX, 1);
	}

	if (InputHandler::GetInstance()->GetAxisKeys(HORIZONTAL) == -1)
	{
		SetAnimationState(MovingX, -1);
	}

	
}

void Player::SetOriginPoint()
{
	m_Origin->X = m_Transform->X + m_Width / 2;
	m_Origin->Y = m_Transform->Y + m_Height / 2;
}

void Player::SetAnimationState(AnimationStates inCurrentAnimationState, float inAxisValue)
{

	if (inCurrentAnimationState == Idle && inAxisValue == 0)
	{
		m_Animation->SetProperties("ShipIdle", 1, 0, 1, 50, true);
	}

	if (inCurrentAnimationState == MovingX && inAxisValue > 0)
	{
		m_Animation->SetProperties("ShipRight", 1, 0, 3, 100, false);
	}


	if (inCurrentAnimationState == MovingX && inAxisValue < 0)
	{
		m_Animation->SetProperties("ShipLeft", 1, 0, 3, 100, false);
	}
}

void Player::Clean()
{
    TextureManager::GetInstance()->Clean();
}
