#pragma once
#include "Ship.h"
#include "BattleShipMap.h"
//#include "PrintUI.h"

enum FromDirection
{
	Up,
	Down,
	Left,
	Right,
	NO,
};

enum attackCheck
{
	ATTACK,
	NOATTACK,
};
class CShipPlayer 
{
public:
	CShipPlayer(void);
	~CShipPlayer(void);
	void			SetPositionRandom();
	int				StartAttack(CShipPlayer * defender);
	void			Initial();
private:
	HitResult		HitCheck(Position hitPos);
	bool			Isvalid(Position pos);
	void			HitChase(Position attackPosition, CShipPlayer* defender);	
	bool			HitChasePosition(Position extenPosition, CShipPlayer* defender);
	void			StartAttackFourPosition( Position attackPosition, CShipPlayer* defender );
protected:
	CShip*			m_Ships[6];
	CBattleShipMap  m_GameMap; ;
	int				m_turnCount, m_destroyCount;
	bool			m_IsCheckMap[MAP_SIZE][MAP_SIZE];
};