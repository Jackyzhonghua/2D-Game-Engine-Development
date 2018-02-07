#include "AudioSource.h"
#include "GameObject.h"


AudioSource::AudioSource(Mix_Music *music, GameObject *pGameobject, int f) :Componentbehavior(pGameobject, "AudioSource", k_audioSource)
{
	m_pMusic = music;
	m_fade = f;
	if (m_fade <= 0)
	{
		Mix_PlayMusic(m_pMusic, -1);
	}
	else
	{
		Mix_FadeInMusic(m_pMusic, -1, m_fade);
	}
	m_pSelfGameObject->AddComponent(this);
}


AudioSource::~AudioSource()
{
	m_pMusic = nullptr;
}

void AudioSource::SetAudio(Mix_Music *music)
{
	m_pMusic = music;
	m_pPreMusic = music;
	if (m_fade <= 0)
	{
		Mix_PlayMusic(music, -1);
	}
	else
	{
		Mix_FadeInMusic(music, -1, m_fade);
	}
}

void AudioSource::SetAudio(Mix_Music *music, int f)
{
	m_pMusic = music;
	m_pPreMusic = music;
	m_fade = f;
	if (m_fade <= 0)
	{
		Mix_PlayMusic(m_pMusic, -1);
	}
	else
	{
		Mix_FadeInMusic(m_pMusic, -1, m_fade);
	}
}

void AudioSource::Play(int f)
{
	m_pMusic = m_pPreMusic;
	m_fade = f;
	if (m_fade <= 0)
	{
		Mix_PlayMusic(m_pMusic, -1);
	}
	else
	{
		Mix_FadeInMusic(m_pMusic, -1, m_fade);
	}
}


void AudioSource::Stop()
{
	m_pMusic = nullptr;
}
