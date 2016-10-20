// Longest CommonSubsequence.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

#define MAX_INPUT 100

int LongestCommonSubsequence(int xLen, int yLen, char * str1, char * str2){
	if (xLen == 0){
		for (int i = 0; i <= yLen; ++i)
			if (str1[xLen] == str2[i])
				return 1;
		return 0;
	}
	else if (yLen == 0){
		for (int i = 0; i <= xLen; ++i)
			if (str1[i] == str2[yLen])
				return 1;
		return 0;
	}

	int max = -1;
	int temp1;

	if (str1[xLen] == str2[yLen])
	{
		temp1 = LongestCommonSubsequence(xLen - 1, yLen - 1, str1, str2) + 1;
		if (max < temp1) max = temp1;
	}
	else
	{
		temp1 = LongestCommonSubsequence(xLen - 1, yLen, str1, str2);
		if (max < temp1) max = temp1;
		
		temp1 = LongestCommonSubsequence(xLen, yLen - 1, str1, str2);
		if (max < temp1) max = temp1;
	}

	return max;
}
int _tmain(int argc, _TCHAR* argv[])
{
	char * str1 = "ABCBDAB";
	char * str2 = "BDCABA";
	int xLen = strlen(str1);
	int yLen = strlen(str2);
	
	printf("%d\n", LongestCommonSubsequence(xLen-1, yLen-1, str1, str2));
	getchar();
	return 0;
}

