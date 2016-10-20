#include "stdafx.h"
#include "Cruiser.h"

CCruiser::CCruiser(void)
{
	m_Hp = 3;
	m_Type = CRUISER;
	m_Name = "CRUISER";
	memset(m_Pos, 0, sizeof(Position) * 5);
}

CCruiser::~CCruiser(void)
{
}

HitResult CCruiser::HitCheck( Position hitPos )
{
	HitResult result = CShip::HitCheck(hitPos);
	
	if(result == DESTROY)
	{
		return DESTROY_CRUISER;
	}
	return result;

}

void CCruiser::Initial()
{
	m_Hp = 3;
	m_PosCount = 0;
	memset(m_Pos, 0, sizeof(Position) * 5);
}
