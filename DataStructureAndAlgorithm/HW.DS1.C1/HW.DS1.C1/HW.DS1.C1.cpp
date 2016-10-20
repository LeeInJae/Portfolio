// HW.DS1.C1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

//주어진 배열 list에서 최소값이 있는 곳의 위치를 찾아 출력하는 프로그램

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

	printf("최솟값 위치 : %d", minValuePosIn(list, size));
	getchar();
	return 0;
}

