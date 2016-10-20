// LongestCommonSubsequence recursive2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

#define MAX_INPUT 100

void LongestCommonSubsequence(int xLen, int yLen, int xCurLen, int yCurlen, char * str1, char * str2, int ** resArr,int * res, int count, char * resStr, char *tempStr){

	if (xCurLen >= xLen || yCurlen >= yLen){
		if (*res < count){
			*res = count;
			strcpy_s(resStr, sizeof(char)*MAX_INPUT, tempStr);
			resArr[xCurLen][yCurlen] = *res;
		}
		return;
	}

	if (str1[xCurLen] == str2[yCurlen]){
		tempStr[count] = str1[xCurLen];
		if (resArr[xCurLen + 1][yCurlen+1] == -1)
			LongestCommonSubsequence(xLen, yLen, xCurLen + 1, yCurlen + 1, str1, str2, resArr, res, count + 1, resStr, tempStr);
		tempStr[count] = 0;
	}
	if (resArr[xCurLen + 1][yCurlen] == -1)
		LongestCommonSubsequence(xLen, yLen, xCurLen + 1, yCurlen, str1, str2, resArr, res, count, resStr, tempStr);
	if (resArr[xCurLen][yCurlen + 1] == -1)
		LongestCommonSubsequence(xLen, yLen, xCurLen, yCurlen + 1, str1, str2, resArr, res, count, resStr, tempStr);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char * str1 = "ABCBDAB";
	char * str2 = "BDCABA";
	int xLen = strlen(str1);
	int yLen = strlen(str2);

	int ** resArr = new int *[MAX_INPUT];
	int * res = new int;
	char * resStr = new char[MAX_INPUT];
	char * tempStr = new char[MAX_INPUT];

	for (int i = 0; i < MAX_INPUT; ++i){
		resStr[i] = 0;
		tempStr[i] = 0; 
	}
	for (int i = 0; i <= xLen; ++i){
		resArr[i] = new int[MAX_INPUT];

		for (int j = 0; j <= yLen; ++j){
			resArr[i][j] = -1;
		}
	}

	LongestCommonSubsequence(xLen, yLen, 0, 0, str1, str2, resArr, res, 0, resStr, tempStr);
	
	printf("%d\n", *res);
	
	for (int i = 0; i < *res; ++i)
		printf("%c", resStr[i]);

	delete[] resArr;
	delete res;
	delete[] resStr;
	delete[] tempStr;

	getchar();
	return 0;
}