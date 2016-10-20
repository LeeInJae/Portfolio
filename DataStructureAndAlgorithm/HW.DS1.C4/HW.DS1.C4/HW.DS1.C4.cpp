// HW.DS1.C4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

void printList(int list[], int size){
	for (int i = 0; i < size; ++i){
		printf("%d ", list[i]);
	}
	printf("\n");
}

int searchLeftmost(int list[], int left, int right, int key){
	if (left>right || left < 0 || right < 0)
		return -1;

	int leftPos = -1;

	while (left <= right){
		int mid = left + (right - left) / 2;

		if (key < list[mid]){
			right = mid - 1;
		}
		else if (key > list[mid]){
			left = mid + 1;
		}
		else if (key == list[mid]){
			leftPos = mid;
			right = mid - 1;
		}
	}
	return leftPos;
}

int searchRightmost(int list[], int left, int right, int key){
	if (left>right || left < 0 || right < 0)
		return -1;

	int rightPos = -1;

	while (left <= right){
		int mid = left + (right - left) / 2;

		if (key < list[mid]){
			right = mid - 1;
		}
		else if (key > list[mid]){
			left = mid + 1;
		}
		else if (key == list[mid]){
			rightPos = mid;
			left = mid + 1;
		}
	}
	return rightPos;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int key;
	int list[10] = { 1, 3, 8, 8, 8, 8, 8, 10, 25, 30 };
	int size = sizeof(list) / sizeof(int);
	int leftPos, rightPos;

	printList(list, size);

	key = 8;
	leftPos = searchLeftmost(list, 0, size - 1, key);
	rightPos = searchRightmost(list, 0, size - 1, key);

	if (leftPos != -1 && rightPos != -1)
		printf("key's cover is from %d to %d\n", leftPos, rightPos);
	else
		printf("key %d not found\n", -1);

	getchar();
	return 0;
}