#ifndef _VIRUS_SMALL_EXPLOSION_H_
#define _VIRUS_SMALL_EXPLOSION_H_
#include <string.h>
#include "GameObject.h"

class VirusSmallExplosion : public GameObject
{
public:
	VirusSmallExplosion(Scene* const selfScene);
	~VirusSmallExplosion();
};
#endif
