#pragma once
#include "Ship.h"

#define MAP_SIZE 8
class CBattleShipMap
{
public:
	CBattleShipMap(void);
	virtual ~CBattleShipMap(void);
	Shiptype	GetMapInfo(Position pos);
	void		ShowMap();
	void		Initial();
	void		SetMapInfo(Position pos, Shiptype shipType	);
private:
	bool IsValid(Position pos);
protected:
	Shiptype m_mapInfo[MAP_SIZE][MAP_SIZE];
};