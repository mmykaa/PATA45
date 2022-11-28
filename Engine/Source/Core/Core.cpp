#include "Core.h"
#include "Engine.h"
#include "EngineTime.h"
#include "box2d.h"
#include "Time.h"
#include "World.h"
#include <iomanip>
#include <iostream>
#include <stdlib.h>

Core* Core::m_Instance = nullptr;

Core::Core()
{
	m_Instance = nullptr;
}

Core::~Core()
{
	delete m_Instance;
}
int hours;
int minutes;
int seconds;

uint32 Yoh(Uint32 interval, void* param);



void Core::InitEngine()
{
 	Engine::GetInstance()->Init();
	World::GetInstance()->SetupWorld();
	
	

	while (Engine::GetInstance()->IsRunning())
	{
		Engine::GetInstance()->Events();
		Engine::GetInstance()->Update();
		Engine::GetInstance()->Renders();
		EngineTime::GetInstance()->Tick();

	}

	Engine::GetInstance()->Clean();
}
