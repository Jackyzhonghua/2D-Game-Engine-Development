#ifndef _VIRUSBAS_H_
#define _VIRUSBAS_H_
#include <iostream>
#include <string.h>
#include "GameObject.h"

class VirusBas : public GameObject
{
public:
	VirusBas(std::string name, Scene* const selfScene);
	~VirusBas();

};

#endif