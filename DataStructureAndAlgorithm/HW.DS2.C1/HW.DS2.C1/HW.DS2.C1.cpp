// HW.DS2.C1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <stdlib.h>

int ** make2dArray(int rows, int cols){
	int ** arr = (int **)malloc( sizeof(int *) * rows);
	for (int i = 0; i < rows; ++i){
		arr[i] = (int *)malloc(sizeof(int) * cols);
	}
	return arr;
}

void putData(int ** arr, int rows, int cols){
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			arr[i][j] = i*rows + j;
		}
	}
}

void printData(int ** arr, int rows, int cols){
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int rows = 3, cols = 5;
	int ** arr = make2dArray(rows, cols);
	
	putData(arr, rows, cols);
	printData(arr, rows, cols);
	
	free(arr);
	getchar();
	return 0;
}