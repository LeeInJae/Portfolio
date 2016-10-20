// HW.DS1.C5.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	if (left > right || left < 0 || right < 0)
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

int recursiveBinarySearch(int list[], int left, int right, int key){

	if (left > right){
		return -1;
	}
	
	int mid = left + (right - left) / 2;
	int pos;
	if (key < list[mid]){
		pos = recursiveBinarySearch(list, left, mid - 1, key);
	}
	else if (key > list[mid]){
		pos = recursiveBinarySearch(list, mid + 1, right, key);
	}
	else if (key == list[mid]){
		pos = mid;
	}
	return pos;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int key;
	int list[10] = { 1, 3, 4, 5, 6, 7, 8, 9, 12, 20 };
	int size = sizeof(list) / sizeof(int);
	int pos;

	printList(list, size);

	key = 205;
	
	pos = recursiveBinarySearch(list, 0, size - 1, key);
	if (pos != -1)
		printf("key at %d\n", pos);
	else
		printf("key %d not found\n", -1);

	getchar();
	return 0;
}