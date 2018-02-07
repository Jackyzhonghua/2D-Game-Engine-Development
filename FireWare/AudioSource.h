#ifndef _AUDIO_SOURCE_H_
#define _AUDIO_SOURCE_H_
#include "Componentbehavior.h"
#include <SDL_mixer.h>

class AudioSource : public Componentbehavior
{
public:
	AudioSource(Mix_Music *music, GameObject *pGameobject, int f = 0);
	~AudioSource();

	void SetAudio(Mix_Music *music);
	void SetAudio(Mix_Music *music, int f = 0);
	void Play(int f = 0);
	void Stop();

private:
	Mix_Music *m_pMusic;
	Mix_Music *m_pPreMusic;
	int m_fade;

};
#endif
