#include "AudioEffect.h"
#include "GameObject.h"


AudioEffect::AudioEffect(Mix_Chunk *music, GameObject *pGameobject) :Componentbehavior(pGameobject, "AudioEffect", k_audioEffect)
{
	m_pEffect = music;
	m_pPreEffect = music;
	m_pSelfGameObject->AddComponent(this);
}


AudioEffect::~AudioEffect()
{
	m_pEffect = nullptr;
    m_pPreEffect = nullptr;
}

void AudioEffect::SetClip(Mix_Chunk * music)
{
	m_pEffect = music;
	m_pPreEffect = music;
}

void AudioEffect::SetVolume(double volume)
{
	if (volume < 0) volume = 0;
	if (volume > 1) volume = 1;
	Mix_VolumeChunk(m_pEffect, (int)(volume * 128));
}

void AudioEffect::Play(int loop)
{
	if (m_pEffect == nullptr)
	{
		m_pEffect = m_pPreEffect;
	}
	Mix_PlayChannel(-1, m_pEffect, loop);
}

void AudioEffect::pause()
{
	m_pEffect = nullptr;
}
