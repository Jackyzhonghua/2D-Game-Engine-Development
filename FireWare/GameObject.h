#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_


#include "Componentbehavior.h"
#include <vector>
#include <string>

class Scene;
class Transform;
class SpriteRederer;

class GameObject
{
public:
	GameObject();
	GameObject(std::string name);
	GameObject(std::string name,  Scene* const selfScene);
	~GameObject();

	//access
	std::string GetName() const { return m_name; }
	void SetActive(bool bActive);
	bool GetActive();
	Scene *GetSelfScene()const { return m_pSelfScene; }


	void AddComponent(Componentbehavior *com);
	void SetTransform(Transform *t);

	Transform *GetTransform()const { return m_PTransform; }
	void SetParent(GameObject *parent);

	std::string GetTag() const { return m_tag; }

	Componentbehavior *GetComponent(std::string name);
	Componentbehavior *GetComponent(Components type);



	void Awake();
	void Start();
	void Update();
	void Render();

protected:
	std::string m_tag;


private:
	Transform *m_PTransform;
	SpriteRederer* m_pSpriteRenderer;
	std::vector<Componentbehavior*> m_components;
	std::string m_name;
	Scene *m_pSelfScene;
	bool m_bActive;
	bool m_bParentActive;

};
#endif




