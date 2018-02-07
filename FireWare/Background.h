#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "GameObject.h"

class Background : public GameObject
{
public:
	Background(Scene* const selfScene);
	~Background();

};

#endif