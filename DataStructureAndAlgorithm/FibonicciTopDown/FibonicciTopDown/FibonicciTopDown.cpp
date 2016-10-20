// FibonicciTopDown.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>
#include <memory.h>

int Recursive(int *memoization, int n){
	if (memoization[n] != -1){
		return memoization[n];
	}

	if (n == 0 || n == 1){
		memoization[n] = n;
		return n;
	}
	
	memoization[n] =  Recursive(memoization, n - 1) + Recursive(memoization, n - 2);
	return memoization[n];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	
	//scanf_s("%d", &n);
	n = 6;
	int * memoization = new int[ 100 ];
	memset(memoization, -1, sizeof(int) * 100);
	printf_s("%d\n", Recursive(memoization, n));
	delete[] memoization;
	getchar();
	return 0;
}

