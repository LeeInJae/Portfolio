// HW.DS1.C2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

//selection sort구현

#include "stdafx.h"
#define INT_MAX 100000000

void Swap(int * a, int * b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//isIncrease가 true면 오름차순, false면 내림차순.
void selectionSort(int list[], int size, bool isIncrease){
	int min, minPos;

	for (int i = 0; i < size - 1; ++i){
		min = list[i];
		minPos = i;
		for (int j = i + 1; j < size; ++j){ 
			if (isIncrease == true)
			{
				if (min > list[j]){
					min = list[j];
					minPos = j;
				}
			}
			else
			{
				if (min < list[j]){
					min = list[j];
					minPos = j;
				}
			}
		}
		Swap(&list[i], &list[minPos]);
	}
}

void printList(int list[], int size){
	for (int i = 0; i < size; ++i){
		printf("%d ", list[i]);
	}
	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	//int list[10] = { 10, 3, 4, 1, 6, 9, 8, 2, 5, 7 };
	int list[] = { 10, 3 };
	int size = sizeof(list) / sizeof(int);

	printList(list, size);
	selectionSort(list, size, false);
	printList(list, size);

	getchar();
	return 0;
}