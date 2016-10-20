#include "stdafx.h"
#include "Destroyer.h"


CDestroyer::CDestroyer(void)
{
	m_Hp = 2;
	m_Type = DESTROYER;
	m_Name = "DESTROYER";
	memset(m_Pos, 0, sizeof(Position) * 5);
}


CDestroyer::~CDestroyer(void)
{
}

HitResult CDestroyer::HitCheck( Position hitPos )
{
	HitResult result = CShip::HitCheck(hitPos);
	if(result == DESTROY)
	{
		return DESTROY_DESTROYER;
	}
	return result;

}

void CDestroyer::Initial()
{
	m_Hp = 2;
	m_PosCount = 0;
	memset(m_Pos, 0, sizeof(Position) * 5);
}
