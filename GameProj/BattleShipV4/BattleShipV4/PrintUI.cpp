#include "stdafx.h"
#include "PrintUI.h"


/*

CprintUI printUI;

int turn = 33;
char szMsg[16] = {0,};
sprintf_s(szMsg, "Turn : %d", turn); //여기는 로직부분. 이것는 뒤에거를 szMSg에 덧붙여서 출력하라.
printUI.PrintMessage(szMsg);

만약 for 문이 있다면 
for(int i=0; i<10; ++i )
{
++turn;
sprintf_s(szMsg, "Turn : %d", turn); //여기는 로직부분. 이것는 뒤에거를 szMSg에 덧붙여서 출력하라.
printUI.PrintMessage(szMsg);
}
*/
//CPrintUI g_gameview;


//type    //=변수명            //정의

CPrintUI* CPrintUI::m_pInstance = NULL;

CPrintUI::CPrintUI(void)
{
}


CPrintUI::~CPrintUI(void)
{
}

/*
void CPrintUI::PrintMessage( std::string msg, bool newLine  )  //default 인자의 사용법
{
	if( newLine )
		printf_s( "%s\n",msg.c_str() );
	else
		printf_s( "%s",msg.c_str() );
		/개행 옵션 넣은것
	printf_s( "%s",msg.c_str() );
}
*/

void CPrintUI::PrintMessage( std::string msg )  //default 인자의 사용법
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