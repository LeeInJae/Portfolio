// recursive_exam`1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

//10������ 2������ ǥ��( ��������� ���ϱ�)
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

