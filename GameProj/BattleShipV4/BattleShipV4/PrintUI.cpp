#include "stdafx.h"
#include "PrintUI.h"


/*

CprintUI printUI;

int turn = 33;
char szMsg[16] = {0,};
sprintf_s(szMsg, "Turn : %d", turn); //����� �����κ�. �̰ʹ� �ڿ��Ÿ� szMSg�� ���ٿ��� ����϶�.
printUI.PrintMessage(szMsg);

���� for ���� �ִٸ� 
for(int i=0; i<10; ++i )
{
++turn;
sprintf_s(szMsg, "Turn : %d", turn); //����� �����κ�. �̰ʹ� �ڿ��Ÿ� szMSg�� ���ٿ��� ����϶�.
printUI.PrintMessage(szMsg);
}
*/
//CPrintUI g_gameview;


//type    //=������            //����

CPrintUI* CPrintUI::m_pInstance = NULL;

CPrintUI::CPrintUI(void)
{
}


CPrintUI::~CPrintUI(void)
{
}

/*
void CPrintUI::PrintMessage( std::string msg, bool newLine  )  //default ������ ����
{
	if( newLine )
		printf_s( "%s\n",msg.c_str() );
	else
		printf_s( "%s",msg.c_str() );
		/���� �ɼ� ������
	printf_s( "%s",msg.c_str() );
}
*/

void CPrintUI::PrintMessage( std::string msg )  //default ������ ����
{
	printf_s( "%s",msg.c_str() );
}
CPrintUI* CPrintUI::GetInstance()
{
	if( m_pInstance == NULL )
	{
		m_pInstance = new CPrintUI();
	}
	return m_pInstance;
// 	if( m_pInstance)
// 	{
// 		return m_pInstance;
// 	}
// 	else
// 	{
// 		m_pInstance = new CPrintUI();
// 		return m_pInstance;
// 	}
}

void CPrintUI::Release()
{
	if( m_pInstance )
	{
		delete m_pInstance;
		m_pInstance = NULL;
	}
}