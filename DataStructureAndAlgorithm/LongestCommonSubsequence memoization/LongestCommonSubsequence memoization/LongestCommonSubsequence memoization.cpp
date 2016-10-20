// LongestCommonSubsequence memoization.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

#define MAX_INPUT 100

int LongestCommonSubsequence(int xLen, int yLen, char * str1, char * str2, int ** resArr, int ** viaPos){
	if (xLen < 0 || yLen < 0)
		return 0;

	if (resArr[xLen][yLen] != -1)
		return resArr[xLen][yLen];

	int max = -1;
	int temp1;

	if (str1[xLen] == str2[yLen])
	{
		temp1 = LongestCommonSubsequence(xLen - 1, yLen - 1, str1, str2,resArr,viaPos) + 1;
		if (max < temp1) {
			max = temp1;
			viaPos[xLen][yLen] = 1;
		}
	}
	else
	{
		temp1 = LongestCommonSubsequence(xLen - 1, yLen, str1, str2, resArr, viaPos);
		if (max < temp1) {
			max = temp1;
			viaPos[xLen][yLen] = 2;
		}

		temp1 = LongestCommonSubsequence(xLen, yLen - 1, str1, str2, resArr, viaPos);
		if (max < temp1) {
			max = temp1;
			viaPos[xLen][yLen] = 3;
		}
	}

	resArr[xLen][yLen] = max;
	return max;
}

void PrintResultString(int row, int col, int ** viaPos, char* str1){
	if (viaPos[row][col] == 0)
		return;
	switch (viaPos[row][col])
	{
	case 1:
		PrintResultString(row - 1, col - 1, viaPos, str1);
		printf("%c", str1[row]);
		break;
		
	case 2:
		PrintResultString(row - 1, col, viaPos, str1);
		break;

	case 3:
		PrintResultString(row, col - 1, viaPos, str1);
		break;

	default:
		break;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	char * str1 = "ABCBDAB";
	char * str2 = "BDCABA";
	int xLen = strlen(str1);
	int yLen = strlen(str2);

	int ** resArr = new int *[MAX_INPUT];
	int ** viaPos = new int *[MAX_INPUT];

	for (int i = 0; i <= xLen; ++i){
		resArr[i] = new int[MAX_INPUT];
		viaPos[i] = new int[MAX_INPUT];

		for (int j = 0; j <=yLen; ++j){
			resArr[i][j] = -1;
			viaPos[i][j] = 0;
		}
	}
	printf("%d\n", LongestCommonSubsequence(xLen - 1, yLen - 1, str1, str2, resArr, viaPos));
	for (int i = 0; i < xLen; ++i){
		for (int j = 0; j < yLen; ++j){
			printf("%d ", resArr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	printf("\n");
	for (int i = 0; i < xLen; ++i){
		for (int j = 0; j < yLen; ++j){
			printf("%d ", viaPos[i][j]);
		}
		printf("\n");
	}
	
	PrintResultString(xLen - 1, yLen - 1, viaPos, str1);
	delete[] resArr;
	delete[] viaPos;
	getchar();
	return 0;
}