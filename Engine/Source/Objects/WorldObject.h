#pragma once
#include "GameObject.h"
#include <string>

class WorldObject : public GameObject
{
public:
	WorldObject(Properties *props) : GameObject(props) {}

	virtual void Draw() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Clean() = 0;

protected:
	std::string m_Name;
};

