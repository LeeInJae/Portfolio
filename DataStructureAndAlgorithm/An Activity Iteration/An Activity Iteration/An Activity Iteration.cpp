// An Activity Iteration.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>

#define MAX_INPUT 100

struct Activity{
	int number;
	int start, end;
};

int MaxActivityNumber(int n, Activity * arr, int * resAct){
	int curTime = 0;
	int count = 0;
	for (int i = 0; i < n; ++i){
		if (arr[i].start >= curTime){
			resAct[count] = arr[i].number;
			++count;
			curTime = arr[i].end;
		}
	}
	return count;
}

int compare(const void * a, const void * b){
	Activity * arg1 = (Activity *)a;
	Activity * arg2 = (Activity *)b;
	if (arg1->end < arg2->end)
		return -1;
	else if (arg1->end > arg2->end)
		return 1;
	else if (arg1->end == arg2->end && arg1->start > arg2->start)
		return 1;
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char * fileName = "input.txt";
	FILE * filePtr;
	errno_t err;

	err = fopen_s(&filePtr, fileName, "r");
	if (err != 0){
		printf("file open error\n");
		return -1;
	}

	int n;
	Activity * arr = new Activity[MAX_INPUT];
	int * res = new int;
	int * resAct = new int[MAX_INPUT];
	int * tempAct = new int[MAX_INPUT];

	fscanf_s(filePtr, "%d", &n);
	for (int i = 0; i < n; ++i){
		arr[i].number = i + 1;
		fscanf_s(filePtr, "%d %d", &arr[i].start, &arr[i].end);
	}

	qsort(arr, n, sizeof(Activity), compare);
	*res = MaxActivityNumber(n, arr, resAct);

	printf("%d\n", *res);
	for (int i = 0; i < *res; ++i){
		printf("%d ", resAct[i]);
	}
	printf("\n");
	delete[] arr;
	delete[] resAct;
	delete[] tempAct;
	delete res;
	fclose(filePtr);
	getchar();
	return 0;
}