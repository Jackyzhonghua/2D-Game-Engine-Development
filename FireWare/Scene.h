#ifndef _SCENE_H_
#define _SCENE_H_
#include <string.h>
#include <vector>

enum Scenes;
class SceneManger;
class GameObject;
class Scene
{
public:
	Scene(std::string name);
	virtual ~Scene();

	void Awake();
	void Start();
	void Run();
	
	GameObject* findGameObject(std::string name);

	void AddGameObject(GameObject *pGameObject);

	std::string GetSceneName() { return m_name; }
	static void SetPauseGame(bool bpause);
	static bool GetPauseGame() { return m_pausegame; }

	std::vector<GameObject*> *GetItems() const;
protected:
	std::string m_name;
	static bool m_pausegame;


	std::vector<GameObject*> *m_pGameItems;
};
#endif