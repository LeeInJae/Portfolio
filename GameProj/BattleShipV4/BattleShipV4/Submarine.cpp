#include "stdafx.h"
#include "Submarine.h"

CSubmarine::CSubmarine(void)
{
	m_Hp = 1;
	m_Type = SUBMARINE;
	m_Name = "SUBMARINE";
	memset(m_Pos, 0, sizeof(Position) * 5);
}


CSubmarine::~CSubmarine(void)
{
}

HitResult CSubmarine::HitCheck( Position hitPos )
{
	HitResult result = CShip::HitCheck(hitPos);
	if(result == DESTROY)
	{
		return DESTROY_SUBMARINE;
	}
	return result;

}

void CSubmarine::Initial()
{
	m_Hp = 1;
	m_PosCount = 0;
	memset(m_Pos, 0, sizeof(Position) * 5);
}
