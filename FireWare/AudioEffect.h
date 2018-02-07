#ifndef _AUDIO_EFFECT_H_
#define _AUDIO_EFFECT_H_
#include "Componentbehavior.h"
#include <SDL_mixer.h>


class AudioEffect : public Componentbehavior
{
public:
	AudioEffect(Mix_Chunk *music, GameObject *pGameobject);
	~AudioEffect();

	void SetClip(Mix_Chunk *music);
	void SetVolume(double volume);
	void Play(int loop = 0);
	void pause();

private:
	Mix_Chunk *m_pEffect;
	Mix_Chunk *m_pPreEffect;
};

#endif
