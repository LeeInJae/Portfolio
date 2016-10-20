// combination.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

void combination(char list[], int isBit[], int size, int curPos, int curCount, int rCount){
	if (curCount == rCount){
		for (int i = 0; i < size; ++i){
			if (isBit[i]){
				printf("%c", list[i]);
			}
		}
		printf("\n");
		return;
	}

	for (int i = curPos; i < size; ++i){
		isBit[i] = 1;
		combination(list, isBit, size, i+1, curCount + 1, rCount);
		isBit[i] = 0;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char list[] = "abc";
	const int size = (sizeof(list) / sizeof(char)) - 1;
	int isBit[size] = { 0, };
	
	for (int i = 1; i <= size; ++i){
		combination(list, isBit, size, 0, 0, i);
	}
		
	getchar();
	return 0;
}