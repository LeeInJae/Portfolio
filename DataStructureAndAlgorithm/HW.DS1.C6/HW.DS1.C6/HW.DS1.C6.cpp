// HW.DS1.C6.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string>

void swapChar(char * ch1, char * ch2){
	char tmp;
	tmp = *ch1;
	*ch1 = *ch2;
	*ch2 = tmp;
}

void printPerm(char * list, int startId, int endId){
	if (startId > endId){
		printf("%s\n", list);
		return;
	}
	
	for (int i = startId; i <= endId; ++i){
		swapChar(&list[startId], &list[i]);
		printPerm(list, startId + 1, endId);
		swapChar(&list[startId], &list[i]);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char list[] = "abc";

	printPerm(list, 0, strlen(list) - 1);
	getchar();
	return 0;
}

