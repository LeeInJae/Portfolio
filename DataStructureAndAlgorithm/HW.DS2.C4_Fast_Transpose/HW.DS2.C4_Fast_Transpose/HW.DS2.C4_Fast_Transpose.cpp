// HW.DS2.C4_Fast_Transpose.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#define MAX_TERMS 100

typedef struct term{
	int rid, cid, value;
}term_t;

void initMatrix(term_t a[], int rows, int cols, int elements){
	a[0].rid = rows;
	a[0].cid = cols;
	a[0].value = elements;
}

void putData(term_t a[], int pos, int rid, int cid, int value){
	a[pos].rid = rid;
	a[pos].cid = cid;
	a[pos].value = value;
}

void fastTranspose(term_t A[], term_t T_A[], int startingPos[]){
	T_A[0].rid = A[0].rid;
	T_A[0].cid = A[0].cid;
	T_A[0].value = A[0].value;

	for (int i = 1; i <= A[0].value; ++i){
		T_A[startingPos[A[i].cid]].rid = A[i].cid;
		T_A[startingPos[A[i].cid]].cid = A[i].rid;
		T_A[startingPos[A[i].cid]].value = A[i].value;
		startingPos[A[i].cid]++;
	}
}

void printMatrix(term_t A[]){
	for (int i = 0; i <= A[0].value; ++i){
		printf("%d %d %d\n", A[i].rid, A[i].cid, A[i].value);
	}
	printf("\n");
}

void initRowTerms(term_t matrix_A[], int rowTerms[]){
	for (int i = 0; i < matrix_A[0].cid; ++i)
		rowTerms[i] = 0;

	for (int i = 1; i <= matrix_A[0].value; ++i){
		rowTerms[matrix_A[i].cid]++;
	}
}

void initStartingPos(int startingPos[], int rowTerms[], int n){
	startingPos[0] = 1;

	for (int i = 1; i <= n; ++i){
		startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	term_t matrix_A[MAX_TERMS], transpos_A[MAX_TERMS];
	int rowTerms[MAX_TERMS];
	int startingPos[MAX_TERMS];

	initMatrix(matrix_A, 6, 6, 8);
	
	putData(matrix_A, 1, 0, 0, 15);
	putData(matrix_A, 2, 0, 3, 22);
	putData(matrix_A, 3, 0, 5, -15);
	putData(matrix_A, 4, 1, 1, 11);
	putData(matrix_A, 5, 1, 2, 3);
	putData(matrix_A, 6, 2, 3, -6);
	putData(matrix_A, 7, 4, 0, 91);
	putData(matrix_A, 8, 5, 2, 28);
	
	initRowTerms(matrix_A, rowTerms);
	initStartingPos(startingPos, rowTerms, matrix_A[0].cid);
	fastTranspose(matrix_A, transpos_A, startingPos);
	printMatrix(matrix_A);
	printMatrix(transpos_A);

	getchar();
	return 0;
}