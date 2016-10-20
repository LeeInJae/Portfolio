// 2dArray.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


void Func(int (* arr)[2]){
	for (int i = 0; i < 2; ++i){
		for (int j = 0; j < 2; ++j){
			printf("%d" , arr[i][j]);
		}
		printf("\n");
	}
}

void Func2(int arr[][2]){
	for (int i = 0; i < 2; ++i){
		for (int j = 0; j < 2; ++j){
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}

void Func3(int arr[][2][2]){
	for (int i = 0; i < 2; ++i){
		for (int j = 0; j < 2; ++j){
			for (int k = 0; k < 2; ++k){
				printf("%d", arr[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int arr[2][2] = { { 1, 2 }, { 3, 4 } };
	int arr3[2][2][2] = { { { 1, 2 }, { 3, 4 } }, { { 5, 6 }, { 7, 8 } }};
	Func3(arr3);
	Func2(arr);
	getchar();
	return 0;
}