#pragma once
#include "WorldObject.h"
#include "../Graphics/Animation.h"


// base character of the player with animation
// third level 

class Character : public WorldObject
{
public:
	Character(Properties* props);

	virtual void Init() = 0;
	virtual void Draw() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Clean() = 0;

protected:
// 	int m_Row;
// 	int m_Frame;
// 	int m_FrameCount;
// 	int m_AnimationSpeed;

	Animation* m_Animation;
};

