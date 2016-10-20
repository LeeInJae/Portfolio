// Fibonacci-recursive.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int Recursive(int n){
	if (n == 0 || n == 1){
		return n;
	}
	return Recursive(n - 1) + Recursive(n - 2);
}
 
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	scanf_s("%d", &n);
	printf_s("%d\n", Recursive(n));
	getchar(); 
	return 0;
}

