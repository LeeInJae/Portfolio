// An Activity-Selection.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>

#define MAX_INPUT 100

struct Activity{
	int number;
	int start, end;
};

int MaxActivityNumber(int n, Activity * arr, int startIndex, int endIndex, int startTime, int endTime, int ** resAct){
	if (startIndex > endIndex) return 0;
	if (startIndex == endIndex){
		if (startTime <= arr[startIndex].start && endTime >= arr[startIndex].end)
			return 1;
		return 0;
	}

	int temp;
	int max = -1;
	
	for (int i = startIndex; i < endIndex; ++i){
		temp = MaxActivityNumber(n, arr, startIndex, i - 1, startTime, arr[i].start, resAct) 
			+ MaxActivityNumber(n,arr,i,i,startTime,endTime,resAct) 
			+ MaxActivityNumber(n, arr, i+1, endIndex, arr[i].end, endTime, resAct);

		if (max < temp){
			max = temp;
			resAct[startIndex][endIndex] = i;
		}
	}
	return max;
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
	int ** resAct = new int * [MAX_INPUT];
	
	fscanf_s(filePtr, "%d", &n);

	for (int i = 0; i <= n; ++i){
		resAct[i] = new int[MAX_INPUT];
		for (int j = 0; j <= n; ++j){
			resAct[i][j] = -1;
		}
	}
	
	for (int i = 0; i < n; ++i){
		arr[i].number = i;
		fscanf_s(filePtr,"%d %d", &arr[i].start, &arr[i].end);
	}
	
	qsort(arr, n, sizeof(Activity), compare);
	printf("%d",MaxActivityNumber(n, arr, 0, n, 0, arr[n-1].end, resAct));
	
	printf("\n");

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			printf("%d  ", resAct[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	delete[] arr;
	delete[] resAct;
	delete res;
	fclose(filePtr);
	getchar();
	return 0;
}