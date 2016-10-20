#include "stdafx.h"
#include "Battleship.h"


CBattleship::CBattleship(void)
{
	m_Hp = 4;
	m_Type = BATTLESHIP;
	m_Name = "BATTLESHIP";
	memset(m_Pos, 0, sizeof(Position) * 5);
}


CBattleship::~CBattleship(void)
{
}

HitResult CBattleship::HitCheck( Position hitPos )
{
	HitResult result = CShip::HitCheck(hitPos);
	if(result == DESTROY)
	{
		return DESTROY_BATTLESHIP;
	}
	return result;

}

void CBattleship::Initial()
{
	m_Hp = 4;
	m_PosCount = 0;
	memset(m_Pos, 0, sizeof(Position) * 5);
}

//함수는 대문자로 시작
//변수명을 제대로 할 것