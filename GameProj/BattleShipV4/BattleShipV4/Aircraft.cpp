#include "stdafx.h"
#include "Aircraft.h"

CAircraft::CAircraft(void)
{
	m_Hp = 5;
	m_Type = AIRCRAFT;
	m_Name = "AIRCRAFT";
	memset(m_Pos, 0, sizeof(Position) * 5);
}


CAircraft::~CAircraft(void)
{
	
}

HitResult CAircraft::HitCheck( Position hitPos )
{
	HitResult result = CShip::HitCheck(hitPos);
	
	if(result == DESTROY)
	{
		return DESTROY_AIRCRAFT;
	}
	return result;
}

void CAircraft::Initial()
{
	m_Hp = 5;
	m_PosCount =0;
	memset(m_Pos, 0, sizeof(Position) * 5);
}