// An Activity-Selection Recurcive2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>

#define MAX_INPUT 100

struct Activity{
	int number;
	int start, end;
};

void MaxActivityNumber(int n, Activity * arr, int count, int curTime, int * res, int index, int * resAct, int * tempAct){
	if (index >= n){
		if (*res < count){
			*res = count;
			for (int i = 0; i < count; ++i){
				resAct[i] = tempAct[i];
			}
		}
		return;
	}

	for (int i = index; i < n; ++i){
		if (curTime <= arr[i].start){
			tempAct[count] = arr[i].number + 1;
			MaxActivityNumber(n, arr, count + 1, arr[i].end, res, i + 1, resAct, tempAct);
			tempAct[count] = -1;
		}
	}
}

int compare(const void * a, const void * b){
	Activity * arg1 = (Activity *)a;
	Activity * arg2 = (Activity *)b;
	if (arg1->start < arg2->start)
		return -1;
	else if (arg1->start > arg2->start)
		return 1;
	else if (arg1->start == arg2->start && arg1->end > arg2->end)
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
		arr[i].number = i;
		fscanf_s(filePtr, "%d %d", &arr[i].start, &arr[i].end);
	}

	qsort(arr, n, sizeof(Activity), compare);
	MaxActivityNumber(n, arr, 0, 0, res, 0, resAct, tempAct);

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