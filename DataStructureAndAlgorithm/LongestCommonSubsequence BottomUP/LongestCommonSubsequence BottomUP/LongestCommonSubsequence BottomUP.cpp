// LongestCommonSubsequence BottomUP.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

#define MAX_INPUT 100

int LongestCommonSubsequence(int xLen, int yLen, char * str1, char * str2, int ** resArr, int ** viaPos){
	for (int i = 0; i < xLen; ++i){
		if (str1[i] == str2[0]){
			for (int j = i; j < xLen; ++j){
				resArr[j][0] = 1;
				viaPos[j][0] = 1;
			}
			break;
		}
	}
	for (int i = 0; i < yLen; ++i){
		if (str1[0] == str2[i]){
			for (int j = i; j < yLen; ++j){
				resArr[0][j] = 1;
				viaPos[0][j] = 1;
			}
			break;
		}
	}

	for (int i = 1; i < xLen; ++i){
		for (int j = 1; j < yLen; ++j){
			if (str1[i] == str2[j]){
				if (i - 1 >= 0 && j - 1 >= 0)
					resArr[i][j] = resArr[i - 1][j - 1] + 1;
				else
					resArr[i][j] = 1;
				viaPos[i][j] = 1;
			}
			else
			{
				if (resArr[i][j] < resArr[i - 1][j]){
					resArr[i][j] = resArr[i - 1][j];
					viaPos[i][j] = 2;
				}
				if(resArr[i][j] < resArr[i][j-1]){
					resArr[i][j] = resArr[i][j - 1];
					viaPos[i][j] = 3;
				}
			}
		}
	}
	return resArr[xLen - 1][yLen - 1];
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

		for (int j = 0; j <= yLen; ++j){
			resArr[i][j] = -1;
			viaPos[i][j] = 0;
		}
	}
	printf("%d\n", LongestCommonSubsequence(xLen, yLen, str1, str2, resArr, viaPos));
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
