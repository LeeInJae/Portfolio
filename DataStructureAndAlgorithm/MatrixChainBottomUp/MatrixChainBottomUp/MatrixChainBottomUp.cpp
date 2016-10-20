// MatrixChainBottomUp.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <memory.h>

#define MAX_INPUT 100
#define INF 100000

struct Matrix{
	int p, q;
};

int Min(int a, int b){
	if (a < b){
		return a;
	}
	return b;
}
int MatrixChain(int n, Matrix * arr,int ** resArr, int ** cutPos){
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n - i + 1; ++j){
			if (j == j + i - 1){
				resArr[j][j + i - 1] = 0;
				cutPos[j][j + i - 1] = 0;
				continue;
			}
			
			for (int k = j; k <= j + i - 2; ++k){
				resArr[j][j + i - 1] = Min(resArr[j][j + i - 1], resArr[j][k] + resArr[k+1][j + i - 1] + arr[j].p * arr[k+1].p * arr[j + i - 1].q);
				cutPos[j][j + i - 1] = k;
			}
		}
	}
	return resArr[1][n];
}

void PrintMatrix(int n, int start, int end, int ** cutPos){
	if (start == end)
	{
		printf("A%d ", start ); 
		return;
	}
	
	printf("(");
	PrintMatrix(n, start, cutPos[start][end], cutPos);
	PrintMatrix(n, cutPos[start][end] + 1, end, cutPos);
	printf(")");
}

int _tmain(int argc, _TCHAR* argv[])
{
	errno_t err;
	FILE * filePtr;
	err = fopen_s(&filePtr, "input.txt", "r");
	if (err != 0){
		printf("File Open Error\n");
		return -1;
	}

	int n;
	Matrix * arr = new Matrix[MAX_INPUT];
	int ** resArr = new int *[MAX_INPUT];
	int ** cutPos = new int *[MAX_INPUT];

	fscanf_s(filePtr, "%d", &n);
	for (int i = 1; i <= n; ++i){
		fscanf_s(filePtr, "%d %d", &arr[i].p, &arr[i].q);
	}

	for (int i = 1; i <= n; ++i){
		resArr[i] = new int[MAX_INPUT];
		cutPos[i] = new int[MAX_INPUT];
		for (int j = 1; j <= n; ++j){
			resArr[i][j] = INF;
			cutPos[i][j] = -1;
		}
	}


	printf("%d\n", MatrixChain(n, arr, resArr,cutPos));
	
	PrintMatrix(n, 1, n, cutPos);
	delete[] arr;
	delete[] resArr;
	getchar();
	return 0;
}



