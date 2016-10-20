// Matrix-chain Recursive.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#define MAX_INPUT 100
#define INF 100000

struct Matrix{
	int p, q;
};

int MatrixChain(int n, Matrix * arr, int start, int end){
	if (start == end){
		return 0;
	}
	
	int min = INF;

	for (int i = start; i <= end-1; ++i){
		int temp1 = MatrixChain(n, arr, start, i) + MatrixChain(n, arr, i+1, end) + arr[start].p * arr[i].q * arr[end].q;
		if (min > temp1){
			min = temp1;
		}
	}

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
	
	fscanf_s(filePtr,"%d", &n);
	for (int i = 1; i <= n; ++i){
		fscanf_s(filePtr,"%d %d", &arr[i].p, &arr[i].q);
	}
	
	printf("%d\n", MatrixChain(n, arr, 1, n));
	fclose(filePtr);
	getchar();
	return 0;
}