#pragma once

#include "../Objects/Character.h"
#include "Bullet.h"
#include "box2d.h"
#include <vector>
#include "Companion.h"

// custom player game side 

enum AnimationStates
{
	Idle,
	MovingX,
	MovingY,
	Dead
};


class Player : public Character
{
public:

	Player(Properties* props);

	virtual void Init();
	virtual void Draw(); 
	virtual void Update(float deltaTime);
	virtual void Clean();
	virtual void CheckCollision(GameObject* otherGameObject);

	void TakeDamage(int inDamage);
	void AddPowerUp();
private:

	void SetupBody();
	void BindAxisAndActions();
	void SetOriginPoint();
	void SetAnimationState(AnimationStates inCurrentAnimationState, float inAxisValue);
	void Move();

	void SpawnFirstCompanion();
	void SpawnSecondCompanion();

public:
	void FireGun();

private:
	SDL_TimerID myTimerID;

	bool bIdle, bMovingRight, bMovingLeft, canShoot, isDead;
	float fSpeed;
	int maxHealth = 100;
	int currentHealth = 100;
	int m_PowerLevel;
	int m_MaxPowerLevel;
	
	Companion* FirstCompanion;
	b2Vec2 firstCompanionPosition;
	Companion* SecondCompanion;
	b2Vec2 secondCompanionPosition;
	float fireRate;
	
	Vector2 m_MoveAxis;

	~Player();
};

