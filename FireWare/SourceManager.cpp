#include "SourceManager.h"
#include "Sprite.h"
#include <SDL.h>


SourceManager *SourceManager::m_instace = nullptr;
SourceManager::SourceManager()
{
	LoadSprites();
	LoadSoundEffect();
	LoadMusic();
}


SourceManager::~SourceManager()
{
	if (m_pSpriteSourceMap.size() > 0)
	{
		auto it_map = m_pSpriteSourceMap.begin();
		while (it_map != m_pSpriteSourceMap.end())
		{
			delete it_map->second;
			it_map++;
		}
	}

	if (m_pSoundEffectSourceMap.size() > 0)
	{
		auto it_map = m_pSoundEffectSourceMap.begin();
		while (it_map != m_pSoundEffectSourceMap.end())
		{
			Mix_FreeChunk(it_map->second);
			it_map++;
		}
	}

	if (m_pMusicSourceMap.size() > 0)
	{
		auto it_map = m_pMusicSourceMap.begin();
		while (it_map != m_pMusicSourceMap.end())
		{
			Mix_FreeMusic(it_map->second);
			it_map++;
		}
	}
}

SourceManager * SourceManager::GetInstance()
{
	if (!m_instace)
	{
		m_instace = new SourceManager;
	}
	return m_instace;
}

Sprite * SourceManager::GetSprite(std::string name)
{
	if (!m_instace)
	{
		m_instace = new SourceManager;
	}
	
	Sprite *reslut = m_instace->m_pSpriteSourceMap[name];
	if (reslut)
	{
		return reslut;
	}
	return nullptr;
}

Mix_Chunk * SourceManager::GetSoundEffect(std::string name)
{
	if (!m_instace)
	{
		m_instace = new SourceManager;
	}

	Mix_Chunk *reslut = m_instace->m_pSoundEffectSourceMap[name];
	if (reslut)
	{
		return reslut;
	}
	return nullptr;
}

Mix_Music * SourceManager::GetMusic(std::string name)
{
	if (!m_instace)
	{
		m_instace = new SourceManager;
	}

	Mix_Music *reslut = m_instace->m_pMusicSourceMap[name];
	if (reslut)
	{
		return reslut;
	}
	return nullptr;
}




void SourceManager::LoadSprites() 
{

	//player
	m_pSpriteSourceMap["Leukocyte"] = new Sprite("Source/Image/Leukocyte.png");
	m_pSpriteSourceMap["LeukocyteLight"] = new Sprite("Source/Image/LeukocyteLight.png");

	//weapons
	m_pSpriteSourceMap["Bullet"] = new Sprite("Source/Image/Bullet.png");


	m_pSpriteSourceMap["cannonball_01"] = new Sprite("Source/Image/cannonball_01.png");
	m_pSpriteSourceMap["cannonball_02"] = new Sprite("Source/Image/cannonball_02.png");
	m_pSpriteSourceMap["cannonball_03"] = new Sprite("Source/Image/cannonball_03.png");
	m_pSpriteSourceMap["cannonball_04"] = new Sprite("Source/Image/cannonball_04.png");
	m_pSpriteSourceMap["cannonball_05"] = new Sprite("Source/Image/cannonball_05.png");



	//viruses
	m_pSpriteSourceMap["VirusSmall_body"] = new Sprite("Source/Image/VirusSmall_body.png");
	m_pSpriteSourceMap["VirusSmall_highLight"] = new Sprite("Source/Image/VirusSmall_highLight.png");

	m_pSpriteSourceMap["VirusSmall_Explosion_01"] = new Sprite("Source/Image/VirusSmall_Explosion_01.png");
	m_pSpriteSourceMap["VirusSmall_Explosion_02"] = new Sprite("Source/Image/VirusSmall_Explosion_02.png");
	m_pSpriteSourceMap["VirusSmall_Explosion_03"] = new Sprite("Source/Image/VirusSmall_Explosion_03.png");
	m_pSpriteSourceMap["VirusSmall_Explosion_04"] = new Sprite("Source/Image/VirusSmall_Explosion_04.png");



	m_pSpriteSourceMap["VirusMiddle_body"] = new Sprite("Source/Image/VirusMiddle_body.png");
	m_pSpriteSourceMap["VirusMiddle_highLight"] = new Sprite("Source/Image/VirusMiddle_highLight.png");

	m_pSpriteSourceMap["VirusMiddle_Explosion_01"] = new Sprite("Source/Image/VirusMiddle_Explosion_01.png");
	m_pSpriteSourceMap["VirusMiddle_Explosion_02"] = new Sprite("Source/Image/VirusMiddle_Explosion_02.png");
	m_pSpriteSourceMap["VirusMiddle_Explosion_03"] = new Sprite("Source/Image/VirusMiddle_Explosion_03.png");
	m_pSpriteSourceMap["VirusMiddle_Explosion_04"] = new Sprite("Source/Image/VirusMiddle_Explosion_04.png");
	m_pSpriteSourceMap["VirusMiddle_Explosion_05"] = new Sprite("Source/Image/VirusMiddle_Explosion_05.png");
	m_pSpriteSourceMap["VirusMiddle_Explosion_06"] = new Sprite("Source/Image/VirusMiddle_Explosion_06.png");


	m_pSpriteSourceMap["VirusBig_body"] = new Sprite("Source/Image/VirusBig_body.png");
	m_pSpriteSourceMap["VirusBig_sideLight"] = new Sprite("Source/Image/VirusBig_sideLight.png");
	m_pSpriteSourceMap["VirusBig_highLight"] = new Sprite("Source/Image/VirusBig_highLight.png");

	m_pSpriteSourceMap["VirusBig_Explosion_01"] = new Sprite("Source/Image/VirusBig_Explosion_01.png");
	m_pSpriteSourceMap["VirusBig_Explosion_02"] = new Sprite("Source/Image/VirusBig_Explosion_02.png");
	m_pSpriteSourceMap["VirusBig_Explosion_03"] = new Sprite("Source/Image/VirusBig_Explosion_03.png");
	m_pSpriteSourceMap["VirusBig_Explosion_04"] = new Sprite("Source/Image/VirusBig_Explosion_04.png");
	m_pSpriteSourceMap["VirusBig_Explosion_05"] = new Sprite("Source/Image/VirusBig_Explosion_05.png");


	//gifts
	m_pSpriteSourceMap["CannonBallGift"] = new Sprite("Source/Image/CannonBallGift.png");



	//UI
	m_pSpriteSourceMap["BackGround"] = new Sprite("Source/Image/BackGround.png");
	m_pSpriteSourceMap["GameResultBackGround"] = new Sprite("Source/Image/GameResultBackGround.png");
	m_pSpriteSourceMap["StartMenuBackground"] = new Sprite("Source/Image/StartMenuBackground.png");
	m_pSpriteSourceMap["CannonUI"] = new Sprite("Source/Image/CannonUI.png");

}

void SourceManager::LoadSoundEffect()
{
	m_pSoundEffectSourceMap["Hit"] = Mix_LoadWAV("Source/Sound/Hit.wav");
	if (m_pSoundEffectSourceMap["Hit"] == nullptr)
		SDL_Log("Failed to open audio %s: %s", "Source/Sound/Hit.wav", Mix_GetError());

	m_pSoundEffectSourceMap["Shoot"] = Mix_LoadWAV("Source/Sound/Shoot.wav");
	if (m_pSoundEffectSourceMap["Shoot"] == nullptr)
		SDL_Log("Failed to open audio %s: %s", "Source/Sound/Shoot.wav", Mix_GetError());

	m_pSoundEffectSourceMap["Explosion"] = Mix_LoadWAV("Source/Sound/Explosion.wav");
	if (m_pSoundEffectSourceMap["Explosion"] == nullptr)
		SDL_Log("Failed to open audio %s: %s", "Source/Sound/Explosion.wav", Mix_GetError());

	m_pSoundEffectSourceMap["Gift"] = Mix_LoadWAV("Source/Sound/Gift.wav");
	if (m_pSoundEffectSourceMap["Gift"] == nullptr)
		SDL_Log("Failed to open audio %s: %s", "Source/Sound/Gift.wav", Mix_GetError());
}

void SourceManager::LoadMusic()
{
	m_pMusicSourceMap["BackGroundMusic"] = Mix_LoadMUS("Source/Sound/BackGroundMusic.mp3");
	if (m_pMusicSourceMap["BackGroundMusic"] == nullptr)
		SDL_Log("Failed to open audio %s: %s", "Source/Sound/BackGroundMusic.mp3", Mix_GetError());
}

