#include "stdafx.h"
#include "Ship.h"
#include <string.h>
#include "GameManager.h"

#define INF 1000000

CShip::CShip(void)
{
	m_Hp = 0;
	m_PosCount = 0;
	memset(m_Pos, 0, sizeof(Position) * 5); //���ۺ���, �ʱ�ȭ��, ������ ũ��
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
				
				sprintf_s( szMsg, "%s �� �ı��� ����  = %d\n", m_Name.c_str(), destroyNumber );
				CPrintUI::GetInstance()->PrintMessage( szMsg );
			}
			return ( m_Hp <= 0 ) ? DESTROY : HIT;  //�񱳿��� �ְ�, Ʈ���ϋ� : false �϶�
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


//���׿����ڴ� bool ������ ���� ����
//bool pass = ( point > 60) ? true : false;
//bool pass = ( point > 60) ? FuncA() : FuncB(); �Լ��� ������ �� ����.