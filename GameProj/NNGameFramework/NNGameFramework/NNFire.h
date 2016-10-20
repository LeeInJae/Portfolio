#pragma once
#include "nneffect.h"

class NNSprite;

class NNFire : public NNEffect
{
public:
	NNFire( void );
	~NNFire(void);
	void	Update( float dTime );
	void RemoveCheck();

	
private:
	float	m_FireSpeed ;
	float	m_AccelSpeed;
	NNSprite* m_CheckBox;
};