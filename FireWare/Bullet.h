#ifndef _BULLET_H_
#define _BULLET_H_
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet(Scene* const selfScene);
	~Bullet();
};
#endif
