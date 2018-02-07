#ifndef _COMPONENTBEHAVIOR_H_
#define _COMPONENTBEHAVIOR_H_

#include <string>
#include <iostream>
#include <map>
#include <vector>

class Collider;
enum Components
{
	k_transform,
	k_spriteRenderer,
	k_collider,
	k_gameBehavior,
	k_textMesh,
	k_audioSource,
	k_audioEffect
};

class GameObject;
class Componentbehavior
{
public:
	Componentbehavior(GameObject *gameobject, std::string  name, Components type);
	Componentbehavior(); 
	virtual ~Componentbehavior();
	
	virtual void Awake(){}
	virtual void Start(){}
	virtual void Update();

	virtual void SetEnable(bool bEnable);
	
	bool GetEnable();


    std::string GetName() const { return m_name; }
	Components GetType() const { return m_type; }

	GameObject * GetGameObject() const { return m_pSelfGameObject; }

	

protected:	
	GameObject *m_pSelfGameObject;
	std::string  m_name;
	Components m_type;
	bool m_bEnable;

	//static std::map<Components, std::string> m_componentsMap;
	

	
};
#endif
