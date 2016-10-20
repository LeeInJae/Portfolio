#include "stdafx.h"
#include "ShipPlayer.h"
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "BattleShipMap.h"
#include "PrintUI.h"
#include "GameManager.h"

CShipPlayer::CShipPlayer(void)
{
	m_Ships[0] = new CAircraft();
	m_Ships[1] = new CBattleship();
	m_Ships[2] = new CCruiser();
	m_Ships[3] = new CCruiser();
	m_Ships[4] = new CDestroyer();
	m_Ships[5] = new CDestroyer();
	m_turnCount = 0;
	m_destroyCount = 6;
	for( int i=0; i<MAP_SIZE; ++i)
		for( int j=0; j<MAP_SIZE; ++j)
			m_IsCheckMap[i][j] = false; //notdefine
}

CShipPlayer::~CShipPlayer(void)
{
	for each(auto pShip in m_Ships)
	{
		delete pShip;
	}
}

void CShipPlayer::Initial()
{
	m_turnCount = 0;
	m_destroyCount = 6;
	for( int i=0; i<MAP_SIZE; ++i)
		for( int j=0; j<MAP_SIZE; ++j)
			m_IsCheckMap[i][j] = false; //notdefine
}

HitResult CShipPlayer::HitCheck( Position hitPos )
{
	HitResult result;
	int shipCount = 6;

	for(int i = 0; i < shipCount; ++i)
	{
		result = m_Ships[i]->HitCheck(hitPos);

		if(result != MISS)
		{
			return result;
		}
	}
	return MISS;
}


void CShipPlayer::SetPositionRandom( )
{
	m_GameMap.Initial();
	for(int i=0;i<6;++i)
		m_Ships[i]->Initial();

	int							shipCount = 6;
	Position					pos;
	Position					setPos;
	DecideHorizonOrVertical		choiceForm[2] = { HORIZON, VERTICAL };
	int							choiceFormPlace;
	DecideHorizonOrVertical		shapeResult;
	Shiptype					checkMapinfo = EMPTY;

	for(int i=0; i<shipCount;++i)
	{
		do
		{
			pos.x =(char)( ( rand() % MAP_SIZE ) + (int)'A' ); //뱃머리를 정해줌
			pos.y =(char)( ( rand() % MAP_SIZE ) + (int)'1' );

			if( m_GameMap.GetMapInfo( pos ) != EMPTY )
			{
				checkMapinfo = NONE;
				continue;
			}

			choiceFormPlace = rand() % 2;
			shapeResult = choiceForm[ choiceFormPlace ];

			for( int j=0; j<m_Ships[i]->GetHp(); ++j)
			{
				( shapeResult == HORIZON) ?  setPos.y = (char) ( (int)pos.y + j ) :setPos.x = (char) ( (int)pos.x + j );
				checkMapinfo = m_GameMap.GetMapInfo( setPos );

				if( checkMapinfo != EMPTY ) 
					break;
			}

			if( checkMapinfo == EMPTY)
			{
				for( int j=0; j<m_Ships[i]->GetHp(); ++j)
				{
					( shapeResult == HORIZON) ?  setPos.y = (char) ( (int)pos.y + j ) :setPos.x = (char) ( (int)pos.x + j );

					m_GameMap.SetMapInfo( setPos, m_Ships[i]->GetType() );
					setPos.shipHit = false;
					m_Ships[i]->AddPosition(setPos);
				}
			}
		}
		while( checkMapinfo != EMPTY );
	}
	m_GameMap.ShowMap();
	CPrintUI::GetInstance()->PrintMessage("\n\n");
}

int CShipPlayer::StartAttack( CShipPlayer * defender )
{
	Position attackPositinon;
	Position pivotPosition;

	pivotPosition.x = MAP_SIZE / 2 -1;
	pivotPosition.y = MAP_SIZE / 2 -1;

	for( int i=0; i<MAP_SIZE/2; ++i )
	{ 
		attackPositinon.x = (char) (pivotPosition.x + (int)'A'+ i) ;
		attackPositinon.y = (char) (pivotPosition.y + (int)'1' + i );
		StartAttackFourPosition( attackPositinon, defender ) ;
		if( m_destroyCount <= 0) return m_turnCount;

		attackPositinon.x = (char) (pivotPosition.x + (int)'A'- i) ;
		attackPositinon.y = (char) ( pivotPosition.y + (int)'1' + i );
		StartAttackFourPosition( attackPositinon, defender ) ;
		if( m_destroyCount <= 0) return m_turnCount;

		attackPositinon.x = (char) (pivotPosition.x + (int)'A'- i) ;
		attackPositinon.y = (char) (pivotPosition.y + (int)'1'- i );
		StartAttackFourPosition( attackPositinon, defender ) ;
		if( m_destroyCount <= 0) return m_turnCount;

		attackPositinon.x = (char) (pivotPosition.x + (int)'A'+ i) ;
		attackPositinon.y = (char) ( pivotPosition.y + (int)'1'- i );
		StartAttackFourPosition( attackPositinon, defender ) ;
		if( m_destroyCount <= 0) return m_turnCount;
	}

	attackPositinon.x = (char) ((int)'A' + MAP_SIZE-1 ) ;
	attackPositinon.y = (char) ((int)'1' + MAP_SIZE-1 );
	StartAttackFourPosition( attackPositinon, defender ) ;
	if( m_destroyCount <= 0) return m_turnCount;

	for(int i=0; i<MAP_SIZE; ++i )
	{
		int j;
		(i % 2 == 1) ? j=1 : j=0;
		while( j<=MAP_SIZE )
		{
			attackPositinon.x = (char) ((int)'A' + i ) ;
			attackPositinon.y = (char) ((int)'1' + j );
			StartAttackFourPosition( attackPositinon, defender ) ;
			if( m_destroyCount <= 0) return m_turnCount;
			j+=2;
		}
	}

	if( m_destroyCount >= 0 )
	{
		for( int i=0; i<MAP_SIZE; ++i )
		{
			for( int j=0; j<MAP_SIZE; ++j )
			{
				if( m_IsCheckMap[i][j] == false )
				{
					attackPositinon.x = (char)( (int)'A' + i );
					attackPositinon.y = (char)( (int)'1' + j );
					StartAttackFourPosition( attackPositinon, defender ) ;
					if( m_destroyCount <= 0) return m_turnCount;
				}
			}
		}
	}
	return m_turnCount;
}

void CShipPlayer::StartAttackFourPosition( Position attackPositinon, CShipPlayer* defender )
{
	HitResult result;

	if( Isvalid(attackPositinon) == true )
	{
		++m_turnCount;
		result = defender->HitCheck( attackPositinon ); 
		m_IsCheckMap[attackPositinon.x - 'A'][attackPositinon.y -'1'] = true;

		if( result > DESTROY )
		{
			--m_destroyCount;
			CGameManager::GetInstance()->AddDestroyNumber();
		}

		if( result == HIT || result >=DESTROY) 
		{
			HitChase(attackPositinon, defender);
		}
	}
}

bool CShipPlayer::HitChasePosition( Position extenPosition, CShipPlayer* defender )
{
	HitResult result;

	if( Isvalid( extenPosition ) == false ) return false;
	++m_turnCount;				
	result = defender->HitCheck( extenPosition );
	m_IsCheckMap[extenPosition.x - 'A'][extenPosition.y -'1'] = true;

	if( result > DESTROY )
	{
		--m_destroyCount;
		CGameManager::GetInstance()->AddDestroyNumber();
		if( m_destroyCount <= 0) return false;
	}
	else if( result == MISS) return false;
	return true;
}

void CShipPlayer::HitChase( Position attackPositinon, CShipPlayer* defender )
{
	Position extenPosition={0,};
	bool endCheck;

	for(int i=1; i<MAP_SIZE; ++i) //left
	{
		extenPosition.x = attackPositinon.x;
		extenPosition.y = (char)((int)attackPositinon.y - i);
		endCheck = HitChasePosition(extenPosition, defender);
		if( endCheck == false) break;
	}

	for(int i=1; i<MAP_SIZE; ++i) //right
	{
		extenPosition.x = attackPositinon.x;
		extenPosition.y = (char)((int)attackPositinon.y + i);
		endCheck = HitChasePosition(extenPosition, defender);
		if( endCheck == false) break;
	}
	for(int i=1; i<MAP_SIZE; ++i) //up
	{
		extenPosition.x = (char)((int)attackPositinon.x - i);
		extenPosition.y = attackPositinon.y;	
		endCheck = HitChasePosition(extenPosition, defender);
		if( endCheck == false) break;
	}
	for(int i=1; i<MAP_SIZE; ++i)//down
	{
		extenPosition.x = (char)((int)attackPositinon.x + i);
		extenPosition.y = attackPositinon.y;
		endCheck = HitChasePosition(extenPosition, defender);
		if( endCheck == false) break;
	}
}

bool CShipPlayer::Isvalid( Position pos )
{
	if ( pos.x < 'A' )			return false;
	if ( pos.x > 'A' + MAP_SIZE -1 ) return false;
	if ( pos.y < '1' )			return false;
	if ( pos.y > '1' + MAP_SIZE -1 ) return false;

	if( m_IsCheckMap[pos.x - 'A'][pos.y - '1'] == true ) return false;  //already attack
	return true;
}


//ctrl+shift+f -> 찾고자 하는 코드 찾는 부분