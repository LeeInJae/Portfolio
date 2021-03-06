#pragma once
#include "NNScene.h"
#include <vector>
#include "BHDefine.h"

class NNAnimation;
class NNPlayerCharacter;
class NNPlayerCharacterBottom;
class NNMap_A;
class NNPooManager;
class NNMapManager;
class NNLabel;
class NNSprite;
class NNSoundManager;


struct BIRD_BORN_TIME
{
	BIRD_TYPE	birdType;
	float		bornTime;
	float		bornCoolTime;
};

//실제 게임이 실행되고 있는 화면( 게임 씬 클래스)
class NNGameScene : public NNScene
{
public:
	NNGameScene(void);
	~NNGameScene(void);
	
	NNPlayerCharacter*&	GetPlayerCharacter(){ return m_Character; }

protected:

	NNMapManager*				m_Map;
	NNPlayerCharacter*			m_Character;
	NNPlayerCharacterBottom*	m_CharacterBottom;
	NNPooManager*				m_PooManager;
		
	NNLabel*			m_ElapsedPlayTimeLabel;
	NNLabel*			m_GameOverLabel;
	NNLabel*			m_FPSLabel;
	NNLabel*			m_AmmoLabel;

	NNAnimation*			m_LandedPoo1;
	NNAnimation*			m_LandedPoo2;
	NNAnimation*			m_LandedPoo3;

	NNAnimation*		m_GameOverPoo;
	float				m_GameOverPooSpeed;
	float				m_GameOverPooAccelSpeed;
	NNAnimation*		m_GameOverExplosion;
	NNSprite*			m_GameOver;

	virtual void	Render();
	virtual void	UIUpdate( float dTime );
	virtual void	Update( float dTime );
	void			UIInit();
	
	float			m_SumTime;
	
	wchar_t			m_PlayTimeString[20];
	wchar_t			m_LandedPooString[20];
	wchar_t			m_FPSString[200];
	wchar_t			m_GameOverString[20];
	wchar_t			m_AmmoString[20];

private:
	bool			m_CheckGameOver;
	bool			m_CheckGameStart;
	bool			m_CheckElapsedTenSec;
	bool			m_DieEndCheck;
	bool			m_CheckElapsedHundredSec;
	bool			m_CheckBgmStarted;
	bool			m_CheckDie;
	bool			m_CheckPollutionMax;
	bool			m_CheckGameOverByPollution;
	BIRD_BORN_TIME	m_BirdBornCheckArray[ BIRD_ALL_NUMBER ];
	float			m_PauseTime;
	float			m_GameSceneStartTime;
	float			m_AppearTime;
	float			m_ChangeGameOVerTime;
	GOING_DIRECTION m_DieDirection;
	bool			m_CheckLodingAddChild;
	bool			m_CheckPlayingAddChild;
	NNAnimation*	m_PlayerCharacterAppear;
	NNAnimation*	m_PlayerCharacterRightDie;
	NNAnimation*	m_PlayerCharacterLeftDie;
	NNAnimation*	m_PlayerCharacterDie;

	NNAnimation*	m_Shield;

	NNSprite*		m_LeftEndPlayerSprite;
	NNSprite*		m_RightEndPlayerSprite;

	NNSprite*		m_SkillFirstBar;
	NNSprite*		m_SkillSecondBar;

	NNSprite*		m_ItemSprite[10];
	NNSprite*		m_ItemGunSprite;
};