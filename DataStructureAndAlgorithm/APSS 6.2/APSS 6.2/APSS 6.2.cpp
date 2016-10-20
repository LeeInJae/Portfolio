// APSS 6.2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string>

void recur(char* str, bool* check, int n, int m, int choiceCOunt, int sp){
	if (m == choiceCOunt){
		for (int i = 0; i < n; ++i){
			if (check[i]){
				printf("%c ", str[i]);
			}
		}
		printf("\n");
		return;
	}
	for (int i = sp; i < n; ++i){
		check[i] = true;
		recur(str, check, n, m, choiceCOunt + 1, i + 1);
		check[i] = false;
	}
}

void recur2(char* str, bool* check, int n,int choiceCOunt, int sp){
	if (choiceCOunt == 0){
		for (int i = 0; i < n; ++i){
			if (check[i]){
				printf("%c ", str[i]);
			}
		}
		printf("\n");
		return;
	}
	for (int i = sp; i < n; ++i){
		check[i] = true;
		recur2(str, check, n, choiceCOunt - 1, i + 1);
		check[i] = false;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char str[10] = { 'a', 'b', 'c', 'd' };
	bool check[10] = { false, };

	//recur(str, check, strlen(str), 2, 0, 0);
	recur2(str, check, strlen(str), 2, 0);
	getchar();
	return 0;
}

