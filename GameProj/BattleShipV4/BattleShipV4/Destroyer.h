#pragma once
#include "ship.h"
class CDestroyer :
	public CShip
{
public:
	CDestroyer(void);
	~CDestroyer(void);
private:
	HitResult HitCheck(Position hitPos);
	void Initial();
};

