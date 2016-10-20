#pragma once
#include "ship.h"
class CAircraft :
	public CShip
{
public:
	CAircraft(void);
	~CAircraft(void);

private:
	HitResult HitCheck(Position hitPos);
	void Initial();
};

