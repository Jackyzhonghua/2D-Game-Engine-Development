#include "GameBehavior.h"
#include "GameObject.h"
#include "Collider.h"
#include "CheckCollider.h"
#include "Scene.h"
#include <SDL.h>





GameBehavior::GameBehavior(GameObject *pGameobject, std::string name): Componentbehavior(pGameobject, name, k_gameBehavior)
{
	m_pSelfGameObject->AddComponent(this);
}

GameBehavior::GameBehavior() : Componentbehavior(nullptr, "", k_gameBehavior)
{
}

GameBehavior::~GameBehavior()
{
}


void GameBehavior::OntriggerEnter(Collider &other)
{
}

void GameBehavior::CheckOtherCollider(std::vector<GameObject*> *gameItems)
{
	if (!m_pSelfGameObject->GetActive()) return;
	Collider *pSelfCollider = static_cast<Collider*>(m_pSelfGameObject->GetComponent(k_collider));
	if (!pSelfCollider) return;
	if (gameItems->empty()) return;

	for (auto g : *gameItems)
	{
		Collider *pOtherCollider = nullptr;
		pOtherCollider = (Collider*)g->GetComponent(k_collider);
		if (pOtherCollider == pSelfCollider)
			continue;	
		if (pOtherCollider)
		{
			if (!pOtherCollider->GetGameObject()->GetActive())
				continue;
			//check do they got overlay
			
			if (CheckCollider::CheckColliders(pSelfCollider, pOtherCollider))
			{
				OntriggerEnter(*pOtherCollider);
			}	
		}
	}
}

void GameBehavior::UpdateTriggerCheck()
{
	Scene *scene = m_pSelfGameObject->GetSelfScene();
	if(scene)
		CheckOtherCollider(scene->GetItems());
}