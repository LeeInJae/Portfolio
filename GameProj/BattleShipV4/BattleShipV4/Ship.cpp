#include "stdafx.h"
#include "Ship.h"
#include <string.h>
#include "GameManager.h"

#define INF 1000000

CShip::CShip(void)
{
	m_Hp = 0;
	m_PosCount = 0;
	memset(m_Pos, 0, sizeof(Position) * 5); //버퍼변수, 초기화값, 사이즈 크기
}

CShip::~CShip(void)
{
}

void CShip::AddPosition( Position pos )
{
	if( m_PosCount >= m_Hp ) 
	{
		printf( "CShip m_PosCount Error\n" );
		return; 
	}

	m_Pos[ m_PosCount ] = pos;
	++m_PosCount;
}

HitResult CShip::HitCheck(Position hitPos) 
{
	int arraySize = sizeof(m_Pos) / sizeof(m_Pos[0]);

	for(int i = 0; i< arraySize; ++i)
	{
		if( m_Pos[i].x == hitPos.x && m_Pos[i].y == hitPos.y )
		{
			if( m_Pos[i].shipHit == false )
				--m_Hp;
			else
				return HIT;
				
			m_Pos[ i ].shipHit = true;

			if( m_Hp <= 0)
			{
				char szMsg[100];
				int destroyNumber = CGameManager::GetInstance()->GetDestroyNumber();
				
				sprintf_s( szMsg, "%s 가 파괴된 순서  = %d\n", m_Name.c_str(), destroyNumber );
				CPrintUI::GetInstance()->PrintMessage( szMsg );
			}
			return ( m_Hp <= 0 ) ? DESTROY : HIT;  //비교연산 넣고, 트루일떄 : false 일때
		}
	}
	return MISS;

}

void CShip::Initial()
{ 
	m_Hp = 0;
	m_PosCount = 0;
	memset(m_Pos, 0, sizeof(Position) * 5);
}


//삼항연산자는 bool 변수에 많이 쓰임
//bool pass = ( point > 60) ? true : false;
//bool pass = ( point > 60) ? FuncA() : FuncB(); 함수는 대입할 수 없음.