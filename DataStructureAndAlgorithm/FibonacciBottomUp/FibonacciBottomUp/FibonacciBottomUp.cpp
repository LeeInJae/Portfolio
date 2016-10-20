// FibonacciBottomUp.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <memory.h>

int Fibonacci(int n)
{
	int * res = new int[100];
	memset(res, 0, sizeof(int) * 100);
	res[0] = 0;
	res[1] = 1;

	for (int i = 2; i <= n; ++i){
		res[i] = res[i - 1] + res[i - 2];
	}
	int result = res[n];
	delete[] res;

	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	n = 6;

	printf("%d", Fibonacci(n));
	getchar();
	return 0;
}

