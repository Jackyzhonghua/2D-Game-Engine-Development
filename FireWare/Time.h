#ifndef _TIME_H_
#define _TIME_H_
#include <SDL.h>
class Time
{
public:
	~Time();
	static Time *GetInstance();
	void Update();
	static double DeltaTime() { return m_deltaTime; }
	void PauseGame();
	void RunGame();
	void RunGameSpeed(double size);

private:
	static Time *m_instance;
	static double m_deltaTime;
	double m_deltaTimeSize;
	double m_maxSpeed;

	uint64_t m_lastTime;
	uint64_t m_currentTime;
	Time();
};
#endif 

