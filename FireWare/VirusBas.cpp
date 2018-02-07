#include "VirusBas.h"



VirusBas::VirusBas(std::string name, Scene* const selfScene):GameObject(name, selfScene)
{
	m_tag = "Enemy";
}


VirusBas::~VirusBas()
{
}
