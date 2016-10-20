#pragma once
#include "ship.h"

class CBattleship :
	public CShip
{
public:
	CBattleship(void);
	~CBattleship(void);
private:
	HitResult HitCheck(Position hitPos);
	void	  Initial();
};