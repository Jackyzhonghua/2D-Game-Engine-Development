#ifndef _GAMEB_EHAVIOR_H_
#define _GAMEB_EHAVIOR_H_
class GameBehavior;
#include "Componentbehavior.h"
#include <iostream>
#include <vector>

class Collider;
class GameBehavior : public Componentbehavior
{
public:
	GameBehavior(GameObject *pGameobject, std::string name);
	GameBehavior();
	~GameBehavior();

	virtual void Awake() override {}
	virtual void Start() override {}
	virtual void Update() override {}



	virtual void OntriggerEnter(Collider &other);
	void UpdateTriggerCheck();
private:
	void CheckOtherCollider(std::vector<GameObject*> *gameItems);

};

#endif