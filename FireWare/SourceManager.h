#ifndef _SOURCEMANGER_H_
#define _SOURCEMANGER_H_

#include <SDL_mixer.h>
#include <iostream>
#include <string.h>
#include  <map>

class Sprite;
class SourceManager
{
public: 
	~SourceManager();

	static SourceManager *GetInstance();
	static Sprite *GetSprite(std::string name);
	static Mix_Chunk *GetSoundEffect(std::string name);
	static Mix_Music *GetMusic(std::string name);

private:
	static SourceManager *m_instace;
	std::map<std::string, Sprite*> m_pSpriteSourceMap;
	std::map<std::string, Mix_Chunk*> m_pSoundEffectSourceMap;
	std::map<std::string, Mix_Music*> m_pMusicSourceMap;

	SourceManager();
	void LoadSprites();
	void LoadSoundEffect();
	void LoadMusic();
};


#endif
