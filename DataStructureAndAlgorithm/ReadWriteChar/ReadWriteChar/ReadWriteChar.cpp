// ReadWriteChar.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	while (1){
		int ch = getchar();
		if (ch == EOF)
			break;
		putchar(ch);
	}
	return 0;
}