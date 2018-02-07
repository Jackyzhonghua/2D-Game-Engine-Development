#include "SpriteRederer.h"
#include "WindowCreater.h"
#include <SDL_image.h>
#include "Transform.h"
#include "GameObject.h"
#include "Sprite.h"



SpriteRederer::SpriteRederer(Sprite *sprite, GameObject *pGameobject):Componentbehavior(pGameobject, "SpriteRederer", k_spriteRenderer)
{
	m_pRenderer = WindowCreater::GetInstance()->GetRenderer();
	SetSprite(sprite);
	m_pSelfTransform = static_cast<Transform*>(m_pSelfGameObject->GetComponent(k_transform));
	m_pSelfGameObject->AddComponent(this);

	m_alpha = 255;
}

SpriteRederer::~SpriteRederer()
{
	m_pRenderer = nullptr;
	m_pSprite = nullptr;
	m_pSelfTransform = nullptr;
}

void SpriteRederer::Awake()
{
}

void SpriteRederer::Start()
{
}

void SpriteRederer::Update()
{
	Draw();
}

void SpriteRederer::SetSprite(Sprite* sprite)
{
	m_pSprite = sprite;
	m_width = m_pSprite->GetSurface()->w;
	m_height = m_pSprite->GetSurface()->h;
	m_renderRect.x = 0;
	m_renderRect.y = 0;
	m_renderRect.w = m_width;
	m_renderRect.h = m_height;
}

void SpriteRederer::Draw()
{
	
	m_ShowArea.x = static_cast<int>(m_pSelfTransform->GetPosition().X()- (m_width /2) * m_pSelfTransform->GetScale().X());
	m_ShowArea.y = static_cast<int>(m_pSelfTransform->GetPosition().Y() - (m_height / 2) * m_pSelfTransform->GetScale().Y());
	m_ShowArea.w = static_cast<int>(m_width * m_pSelfTransform->GetScale().X());
	m_ShowArea.h = static_cast<int>(m_height * m_pSelfTransform->GetScale().Y());
	
	SDL_RenderCopyEx(m_pRenderer, m_pSprite->GetTexture(), &m_renderRect, &m_ShowArea, m_pSelfTransform->GetRotation(), NULL, SDL_FLIP_NONE);
}

void SpriteRederer::SetAlpha(double alpha)
{
	if (alpha >= 1)
	{
		m_alpha = 1;
	}
	else if (alpha <= 0)
	{
		m_alpha = 0;
	}
	else
	{
		m_alpha = alpha;
	}
	SDL_SetTextureAlphaMod(m_pSprite->GetTexture(), (Uint8)(m_alpha*255));
}
