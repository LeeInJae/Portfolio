// VoidTypePointer.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

void SoSimpleFunc(){
	printf("hihihi");
}

int _tmain(int argc, _TCHAR* argv[])
{
	int num = 20;
	void * ptr;

	ptr = &num;
	printf("%p \n", ptr);

	ptr = SoSimpleFunc;
	printf("%p\n", ptr);
	getchar();
	return 0;
}

