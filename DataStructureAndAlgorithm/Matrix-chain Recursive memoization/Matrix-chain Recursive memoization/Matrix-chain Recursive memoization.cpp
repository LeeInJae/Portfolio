// Matrix-chain Recursive memoization.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <memory.h>

#define MAX_INPUT 100
#define INF 100000

struct Matrix{
	int p, q;
};

int MatrixChain(int n, Matrix * arr, int start, int end, int ** resArr){
	if (resArr[start][end] != -1){
		return resArr[start][end];
	}
	if (start == end){
		resArr[start][end] = 0;
		return 0;
	}

	int min = INF;

	for (int i = start; i <= end - 1; ++i){
		int temp1 = MatrixChain(n, arr, start, i, resArr) + MatrixChain(n, arr, i + 1, end, resArr) + arr[start].p * arr[i].q * arr[end].q;
		if (min > temp1){
			min = temp1;
		}
	}
	resArr[start][end] = min;
	return min;
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
	 
	fscanf_s(filePtr, "%d", &n);
	for (int i = 1; i <= n; ++i){
		fscanf_s(filePtr, "%d %d", &arr[i].p, &arr[i].q);
	}

	
	for (int i = 1; i <= n; ++i){
		resArr[i] = new int[MAX_INPUT];
		memset(resArr[i], -1, sizeof(int)*(n+1));
	}
	printf("%d\n", MatrixChain(n, arr, 1, n, resArr));

	delete[] arr;
	delete[] resArr;
	fclose(filePtr);
	getchar();
	return 0;
}

