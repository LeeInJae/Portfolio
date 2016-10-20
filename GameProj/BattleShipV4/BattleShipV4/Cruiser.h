#pragma once
#include "ship.h"
class CCruiser :
	public CShip
{
public:
	CCruiser(void);
	~CCruiser(void);
private:
	HitResult HitCheck(Position hitPos);
	void Initial();
};

