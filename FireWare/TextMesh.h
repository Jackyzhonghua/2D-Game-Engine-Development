#ifndef _TEXT_MESH_H_
#define _TEXT_MESH_H_

class TextMesh;
#include "Componentbehavior.h"
#include <SDL_ttf.h>

class Transform;
class TextMesh : public Componentbehavior
{
public:
	TextMesh(GameObject *pGameobject);
	~TextMesh();

	virtual void Update() override;

	void SetFontAddress(char* address);
	void LoadContent(const char * address, const char *content, int size);
	void LoadContent(const char *content, int size);

private:
	Transform *m_pSelfTransform;
	SDL_Renderer* m_pRenderer;
	char *m_pAddress;
	TTF_Font *m_pFont;
	SDL_Color m_textColor;
	SDL_Surface* m_pTextSurface;
	SDL_Texture* m_pTextTexture;

	void Draw();
};
#endif
