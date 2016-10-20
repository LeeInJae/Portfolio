// Test_Class.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Ship.h"
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Submarine.h"
#include "ShipPlayer.h"
#include "GameManager.h"
#include "PrintUI.h"
#include <time.h>

int _tmain()
{
	srand( (unsigned int) time(NULL) );
	
	//CGameManager gameManager;
	CPrintUI::GetInstance()->PrintMessage(" BattleShip Game Start!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	CPrintUI::GetInstance()->PrintMessage("------------------------------------------------\n");

	CGameManager::GetInstance()->Run();
	CPrintUI::Release();

	//싱글톤 해제 방법
	

	getchar();//그냥 생성하면 종료되기전에 소멸자는 실행이 안됨
	
	return 0;
}