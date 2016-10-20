// HW.DS2.C2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>

typedef struct array2D{
	int rows, cols;
	int ** arr;
}array2D_t;

int ** make2dArray(int rows, int cols){
	int ** arr = (int **)malloc(sizeof(int *) * rows);
	for (int i = 0; i < rows; ++i){
		arr[i] = (int *)malloc(sizeof(int) * cols);
	}
	return arr;
}

void putData(int ** arr, int rows, int cols){
	int count = 0;

	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			arr[i][j] = ++count;
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
	printf("\n");
}

void matrixSum(int ** result, int ** A, int ** B, int rows, int cols){
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			result[i][j] = A[i][j] + B[i][j];
		}
	}
}

void matrixMulti(int **result, int **matrixA, int rowNumOfA, int colNumOfA, int **matrixB, int rowNumOfB, int colNumOfB){
	for (int i = 0; i < rowNumOfA; ++i){
		for (int j = 0; j < colNumOfB; ++j){
			result[i][j] = 0;
			for (int k = 0; k < colNumOfA; ++k){
				result[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
}

void matrixTranspose(int **matrixA_T, int **matrixA, int rows, int cols){
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			matrixA_T[j][i] = matrixA[i][j];
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	array2D_t arr1, arr2, resultSum, resultMul, resultTranspose;
	arr1.rows = 2;
	arr1.cols = 3;
	
	arr2.rows = 3;
	arr2.cols = 2;

	resultSum.rows = 2;
	resultSum.cols = 2;
	
	resultMul.rows = 2;
	resultMul.cols = 2;
	
	resultSum.rows = 2;
	resultSum.cols = 2;

	resultTranspose.rows = 3;
	resultTranspose.cols = 2;

	arr1.arr = make2dArray(arr1.rows, arr1.cols);
	arr2.arr = make2dArray(arr2.rows, arr2.cols);
	resultSum.arr = make2dArray(resultSum.rows, resultSum.cols);
	resultMul.arr = make2dArray(resultMul.rows, resultMul.cols);
	resultTranspose.arr = make2dArray(arr1.cols, arr1.rows);
	
	putData(arr1.arr, arr1.rows, arr1.cols);
	putData(arr2.arr, arr2.rows, arr2.cols);

	printData(arr1.arr, arr1.rows, arr1.cols);
	printData(arr2.arr, arr2.rows, arr2.cols);

	matrixSum(resultSum.arr, arr1.arr, arr2.arr, arr1.rows, arr1.cols);
	matrixMulti(resultMul.arr, arr1.arr, arr1.rows, arr1.cols,arr2.arr, arr2.rows, arr2.cols);
	matrixTranspose(resultTranspose.arr, arr1.arr, arr1.rows, arr1.cols);

	printData(resultSum.arr, resultSum.rows, resultSum.cols);
	printData(resultMul.arr, resultSum.rows, resultSum.cols);
	printData(resultTranspose.arr, resultTranspose.rows, resultTranspose.cols);
	

	free(arr1.arr);
	free(arr2.arr);
	getchar();
	return 0;
}

