// Test_Class.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

	//�̱��� ���� ���
	

	getchar();//�׳� �����ϸ� ����Ǳ����� �Ҹ��ڴ� ������ �ȵ�
	
	return 0;
}