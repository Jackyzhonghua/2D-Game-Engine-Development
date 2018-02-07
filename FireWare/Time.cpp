#include "Time.h"


Time *Time::m_instance = nullptr;
double Time::m_deltaTime = 0;

Time::Time()
{
	m_lastTime = SDL_GetPerformanceCounter();

	//*************************************************
	//it will getting very slow by time going
	//************************************************
	m_maxSpeed = 1;
	m_deltaTimeSize = m_maxSpeed;
}


Time::~Time()
{
	m_instance = nullptr;
}

Time * Time::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new Time;
	}
	return m_instance;
}

void Time::Update()
{
	m_currentTime = SDL_GetPerformanceCounter();
	int64_t timeDifference = m_currentTime - m_lastTime;
	m_lastTime = m_currentTime;
	m_deltaTime = static_cast<float>(timeDifference / static_cast<double>(SDL_GetPerformanceFrequency()));
	m_deltaTime *= m_deltaTimeSize;
}

void Time::PauseGame()
{
	m_deltaTimeSize = m_maxSpeed * 0;
}

void Time::RunGame()
{
	m_deltaTimeSize = m_maxSpeed;
}

void Time::RunGameSpeed(double size)
{
	m_deltaTimeSize = m_maxSpeed * size;
}
