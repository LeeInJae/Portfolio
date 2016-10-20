#include "stdafx.h"
#include "BattleShipMap.h"
#include "PrintUI.h"


CBattleShipMap::CBattleShipMap(void)
{
	for(int i=0; i< MAP_SIZE; ++i)
		for(int j=0; j<MAP_SIZE; ++j)
			m_mapInfo[i][j] = EMPTY;
}


CBattleShipMap::~CBattleShipMap(void)
{
}

void CBattleShipMap::SetMapInfo( Position pos, Shiptype shipType )
{
	if( IsValid(pos) == true)
	{
		m_mapInfo[pos.x-'A'][pos.y-'1'] = shipType;
	}
}

Shiptype CBattleShipMap::GetMapInfo( Position pos )
{
	if( IsValid(pos) == true ) 
		return m_mapInfo[pos.x-'A'][pos.y-'1'];

	return NONE;
}

bool CBattleShipMap::IsValid( Position pos )
{
	if ( pos.x < 'A' )			return false;
	if ( pos.x > 'A' + MAP_SIZE -1 ) return false;
	if ( pos.y < '1' )			return false;
	if ( pos.y > '1' + MAP_SIZE -1 ) return false;
	
	return true;
}

void CBattleShipMap::Initial()
{
	for(int i=0; i< MAP_SIZE; ++i)
		for(int j=0; j<MAP_SIZE; ++j)
			m_mapInfo[i][j] = EMPTY;
}

void CBattleShipMap::ShowMap()
{
	char szMsg[20] = {0,};
	for(int i=0; i< MAP_SIZE; ++i)
	{
		for(int j=0; j<MAP_SIZE; ++j)
		{
			sprintf_s( szMsg, "%d ", m_mapInfo[i][j] );
			CPrintUI::GetInstance()->PrintMessage( szMsg );
		}
		CPrintUI::GetInstance()->PrintMessage("\n");
	}
}
