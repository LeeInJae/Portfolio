#pragma once
#include "ship.h"
class CSubmarine :
	public CShip
{
public:
	CSubmarine(void);
	~CSubmarine(void);
private:
	HitResult HitCheck(Position hitPos);
	void Initial();
};

