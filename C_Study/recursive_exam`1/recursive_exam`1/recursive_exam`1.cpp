// recursive_exam`1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

//10진수를 2진수로 표현( 재귀적으로 구하기)
void TenToTwo(int n){
	if (n <= 0){
		return;
	}

	TenToTwo(n / 2);	
	printf("%d", n % 2);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 10;
	TenToTwo(n);
	getchar();
	return 0;
}

