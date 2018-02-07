#include "GamePlayingScene.h"
#include "Transform.h"
#include "GameObject.h"
#include "Leukocyte.h"
#include "Background.h"
#include "GameBehavior.h"
#include "BackGroundMovement.h"
#include "LeukocyteLight.h"
#include "VirusManager.h"
#include "GameResult.h"
#include "GameResultBackGround.h"
#include "StartMenuBackground.h"
#include "GameManager.h"
#include "VirusSmallExplosion.h"
#include "UI.h"
#include "Gifts.h"




GamePlayingScene::GamePlayingScene(): Scene("GamePlayingScene")
{
	GameObject *pGameManager = new GameManager(this);
	GameObject *pBackGround = new Background(this);
	GameBehavior *BackGroundMove = new BackGroundMovement(pBackGround);

	GameObject *pBackGround1 = new Background(this);
	Transform *pTgb = static_cast<Transform*>(pBackGround1->GetComponent(k_transform));
	pTgb->SetPosition(pTgb->GetPosition().X(), -750);
	GameBehavior *BackGroundMove1 = new BackGroundMovement(pBackGround1);

	GameObject *pGLeukocyte = new Leukocyte(this);
	GameObject *pGLeukocyteLight = new LeukocyteLight(this);

	GameObject *pVirusManager = new VirusManager(this);

	GameObject* pUI = new UI(this);
	


	GameObject *pGameResultBackGround = new GameResultBackGround(this);
	GameObject *pGameResult = new GameResult(this);
	GameObject *pStartMenuBackground = new StartMenuBackground(this);

	//GameObject *pCannonBallGift = new CannonBallGift(this);
	GameObject* pGifts = new Gifts(this);
}


GamePlayingScene::~GamePlayingScene()
{
}
