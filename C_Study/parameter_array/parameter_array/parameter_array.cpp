#include <iostream>

int main(void){
	int array[10][10][10];
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 10; ++k)
				array[i][j][k] = i * 100 + j * 10 + k;

	int (*pArr)[10][10][10] = &array; //pArr �̶�� �����Ͱ� int������ [10][10][10] ¥���� �迭�� ����Ű���� ��.

	(*pArr)[5][5][5] = 200;
	
	printf("%d\n", (*pArr)[5][5][5]);
	getchar();
	return 0;
}