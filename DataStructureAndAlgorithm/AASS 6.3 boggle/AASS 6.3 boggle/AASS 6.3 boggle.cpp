// AASS 6.3 boggle.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#define DIR 8

const int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

char ** get2dArray(int n, int m){
	char ** arr = new char *[n];
	for (int i = 0; i < n; ++i){
		arr[i] = new char[m];
	}
	return arr;
}

void initArr(char ** arr, int n, int m){
	
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			arr[i][j] = '\0';
		}
	}

	arr[0] = { "URLPM" };
	arr[1] = { "XPRET" };
	arr[2] = { "GIAET" };
	arr[3] = { "XTNZY" };
	arr[4] = { "XOQRS" };
}

void printArr(char ** arr, int n, int m){

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}


bool hasWord(char ** board, char * word, int n, int m, int x, int y, int len, int curPos){
	if (x < 0 || x >= n || y < 0 || y >= m)
		return false;

	if (board[x][y] != word[curPos])
		return false;

	if (curPos == len)
		return true;
	
	bool check;

	for (int i = 0; i < DIR; ++i){
		check = hasWord(board, word, n, m, x + dx[i], y + dy[i], len, curPos + 1);
		if (check == true){
			return true;
		}
	}
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n, m;
	
	/*
	std::string str = "We think in generalities, but we live in details.";
	// (quoting Alfred N. Whitehead)

	std::string str3 = str.substr(2);     // get from "live" to the end

	std::cout << str3 << '\n';
	*/

	n = 6;
	m = 6;
	char ** arr = get2dArray(n, m);
	char * word = "GG";
	bool flag = false;

	initArr(arr, n, m);
	printArr(arr, n, m);
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			flag = hasWord(arr, word, n, m, i, j, strlen(word), 0);
			if (flag){
				printf("%s 는 존재한다\n", word);
				break;
			}
		}
		if (flag)
			break;
	}
	if (!flag){
		printf("%s 는 존재하지 않음\n", word);
	}
	getchar();
	return 0;
}

