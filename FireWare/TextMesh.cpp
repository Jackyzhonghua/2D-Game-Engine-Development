#include "TextMesh.h"
#include "WindowCreater.h"
#include <SDL_image.h>
#include "Transform.h"
#include "GameObject.h"



TextMesh::TextMesh(GameObject *pGameobject) :Componentbehavior(pGameobject, "TextMesh", k_textMesh)
{
	m_pSelfTransform = m_pSelfGameObject->GetTransform();
	m_pRenderer = WindowCreater::GetInstance()->GetRenderer();
	m_textColor.a = 255;
	m_textColor.b = 255;
	m_textColor.g = 255;
	m_textColor.r = 255;
	m_pAddress = "Source/Font/RobotoSlab-Regular.ttf";
	LoadContent(m_pAddress, "0", 1);
	m_pSelfGameObject->AddComponent(this);
}


TextMesh::~TextMesh()
{
	m_pSelfTransform = nullptr;
	m_pRenderer = nullptr;
	SDL_DestroyTexture(m_pTextTexture);
	SDL_FreeSurface(m_pTextSurface);
	TTF_CloseFont(m_pFont);
}

void TextMesh::Update()
{
	Draw();
}

void TextMesh::SetFontAddress(char * address)
{
	m_pAddress = address;
}

//load content with new font
void TextMesh::LoadContent(const char * pAddress, const char *content, int size)
{
	m_pFont = TTF_OpenFont(pAddress, size);
	if (!m_pFont)
	{
		SDL_Log("fail to load text");
	}
	m_pTextSurface = TTF_RenderUTF8_Solid(m_pFont, content, m_textColor);
	m_pTextTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pTextSurface);
}

//load content with original font
void TextMesh::LoadContent(const char * content, int size)
{
	m_pFont = TTF_OpenFont(m_pAddress, size);
	if (!m_pFont)
	{
		SDL_Log("fail to load text");
	}
	m_pTextSurface = TTF_RenderUTF8_Solid(m_pFont, content, m_textColor);
	m_pTextTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pTextSurface);
}


void TextMesh::Draw()
{
	SDL_Rect textRect;
	textRect.w = m_pTextSurface->w;
	textRect.h = m_pTextSurface->h;
	textRect.x = static_cast<int>(m_pSelfGameObject->GetTransform()->GetPosition().X()) - textRect.w;
	textRect.y = static_cast<int>(m_pSelfGameObject->GetTransform()->GetPosition().Y()) - textRect.h;
	SDL_Point rotationPoint;
	rotationPoint.x = m_pTextSurface->w;
	rotationPoint.y = 0;
	SDL_RenderCopyEx(m_pRenderer, m_pTextTexture, nullptr, &textRect, 0, &rotationPoint, SDL_FLIP_NONE);
}
