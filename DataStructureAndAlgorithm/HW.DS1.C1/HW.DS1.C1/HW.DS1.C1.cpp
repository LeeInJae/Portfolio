// HW.DS1.C1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

//�־��� �迭 list���� �ּҰ��� �ִ� ���� ��ġ�� ã�� ����ϴ� ���α׷�

#include "stdafx.h"
#define INT_MAX 100000000

int minValuePosIn(int list[], int size){
	int minPos = -1;
	int min = INT_MAX;
	for (int i = 0; i < size; ++i){
		if (min > list[i]){
			min = list[i];
			minPos = i;
		}
	}
	return minPos;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int list[10] = { 10, 3, 4, 1, 6, 9, 8, 2, 5, 7 };
	int size = sizeof(list) / sizeof(int);

	printf("�ּڰ� ��ġ : %d", minValuePosIn(list, size));
	getchar();
	return 0;
}

