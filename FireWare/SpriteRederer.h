#ifndef _SPRITEREDERER_H_
#define  _SPRITEREDERER_H_

class SpriteRederer;
#include "Componentbehavior.h"
#include "Vector2.h"
#include <string>
#include <SDL.h>

class Transform;
class Sprite;
class Vector2;
class SpriteRederer : public Componentbehavior
{
public:
	SpriteRederer(Sprite* sprite, GameObject *pGameobject);
	~SpriteRederer();

	virtual void Awake() override;
	virtual void Start() override;
	virtual void Update() override;

	void SetSprite(Sprite *sprite);
	void Draw();
	void SetAlpha(double alpha);
	double  GetAlpha()const { return m_alpha; }

private:
	SDL_Renderer* m_pRenderer;
	Sprite *m_pSprite;
	Transform* m_pSelfTransform;
	Vector2 m_centerPoint;
	SDL_Rect m_renderRect;
	SDL_Rect m_ShowArea;

	int m_width;
	int m_height;
	double m_alpha;
};

#endif

