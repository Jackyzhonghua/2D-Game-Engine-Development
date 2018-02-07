#ifndef _SCENEMANGER_H_
#define _SCENEMANGER_H_

#include <vector>
#include <string>

class Scene;
class SceneManger
{
public:
	~SceneManger();
	void GameUpdate();
	void GameEnd();

	static void LoadScene(Scene* scene);
	static void DeleteScene();
	static SceneManger* getInstance();
	void pause();
	void play();


	Scene *GetCurScene();

private:
	static SceneManger* instance;

	static Scene *m_curScene;
	bool m_pauseGame;


	static void Awake();
	static void Start();
	SceneManger();

};
#endif

