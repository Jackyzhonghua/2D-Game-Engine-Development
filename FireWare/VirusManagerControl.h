#ifndef _VIRUS_MANAGER_CONTROL_H_
#define _VIRUS_MANAGER_CONTROL_H_
#include "GameBehavior.h"
#include <iostream>
#include <vector>



class VirusBas;
class VirusSmallExplosion;
class VirusMiddleExplosion;
class VirusBigExplosion;

class VirusManagerControl : public GameBehavior
{
public:
	VirusManagerControl(GameObject *pGameobject);
	~VirusManagerControl();


	virtual void Update() override;


	void GetExplosion();

	VirusSmallExplosion* GetVirusSmallExplosion();
	VirusMiddleExplosion* GetVirusMiddleExplosion();
	VirusBigExplosion* GetVirusBigExplosion();


private:


	std::vector<VirusBas*> m_virusSmall;
	std::vector<VirusBas*> m_virusMiddle;
	std::vector<VirusBas*> m_virusBig;

	std::vector<VirusSmallExplosion*> m_pVirusSmallExplosions;
	std::vector<VirusMiddleExplosion*> m_pVirusMiddleExplosions;
	std::vector<VirusBigExplosion*> m_pVirusBigExplosions;

	double m_timer;
	double m_totalTime;

	void SpawnControl();
	void SpawnVirus();

};
#endif
