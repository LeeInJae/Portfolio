#include "stdafx.h"
#include "GameManager.h"
#include "ShipPlayer.h"

CGameManager* CGameManager::m_pInstance = NULL;

CGameManager::CGameManager(void)
{
	//CPrintUI::GetInstance()->PrintMessage("test\n");
	m_destroyNumber = 0;
}


CGameManager::~CGameManager(void)
{
}  

void CGameManager::Run()
{
	CShipPlayer* pAttacker = new CShipPlayer();
	CShipPlayer* pDefender = new CShipPlayer();

	int totalTurn = 0;
	int average = 0;
	char szMsg[50];
	for(int i=0; i<10; ++i)
	{
		pDefender -> SetPositionRandom();
		totalTurn = pAttacker -> StartAttack(pDefender);
		average += totalTurn;
	
		sprintf_s( szMsg, "totalTurn = %d\n", totalTurn );
		CPrintUI::GetInstance()->PrintMessage( szMsg );
		pAttacker->Initial();
		pDefender->Initial();
		CGameManager::GetInstance()->InitialDestroyNumber();
	}
	average /= 10;
	sprintf_s( szMsg, "10번의 총 평균 수 : %d\n\n", average );
	CPrintUI::GetInstance()->PrintMessage( szMsg );
}
//게임매니저 싱글톤
//카운터
//getset메소드
//ship에서 제어

CGameManager* CGameManager::GetInstance()
{
	if( m_pInstance == NULL )
	{
		m_pInstance = new CGameManager();
	}
	return m_pInstance;
}

void CGameManager::Release()
{
	if( m_pInstance )
	{
		delete m_pInstance;
		m_pInstance = NULL;
	}
}

void CGameManager::AddDestroyNumber()
{
	++m_destroyNumber;
}

void CGameManager::InitialDestroyNumber()
{
	m_destroyNumber = 0;
}

