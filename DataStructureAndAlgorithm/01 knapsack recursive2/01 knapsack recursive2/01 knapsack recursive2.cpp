// 01 knapsack recursive2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <algorithm>
#define MAX_INPUT 100

struct Stuff{
	int number;
	int weight;
	int value;
	float dense;
};

bool cmp(struct Stuff a, struct Stuff b){
	return a.dense > b.dense;
}

int KnapSack(int n, Stuff * arr, int maxWeight, int index){
	if (index < 0 || maxWeight <= 0)
		return 0;

	int max = -1;
	int temp1, temp2;

	if (arr[index].weight <= maxWeight)
	{
		temp1 = KnapSack(n, arr, maxWeight - arr[index].weight, index - 1) + arr[index].value;
		if (max < temp1) max = temp1;
	}
	temp2 = KnapSack(n, arr, maxWeight, index - 1);
	if (max < temp2) max = temp2;

	return max;
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	FILE * filePtr;
	errno_t err;
	int n, maxWeight;
	Stuff * arr = new Stuff[MAX_INPUT];
	int * res = new int;
	*res = -1;
	int * resStuff = new int[MAX_INPUT];
	int * tempStuff = new int[MAX_INPUT];
	int * resCount = new int;

	err = fopen_s(&filePtr, "input.txt", "r");
	if (err != 0){
		printf("file open error\n");
		return -1;
	}

	fscanf_s(filePtr, "%d %d", &n, &maxWeight);
	for (int i = 0; i < n; ++i){
		arr[i].number = i + 1;
		fscanf_s(filePtr, "%d %d", &arr[i].weight, &arr[i].value);
		arr[i].dense = static_cast<float>(arr[i].value / arr[i].weight);
	}

	std::sort(arr, arr + n, cmp);

	printf("%d", KnapSack(n, arr, maxWeight, n - 1));


	for (int i = 0; i < *resCount; ++i){
		printf("%d ", resStuff[i]);
	}
	printf("\n");
	delete[] arr;
	delete[] resStuff;
	delete[] tempStuff;
	delete res;
	delete resCount;
	return 0;
}

