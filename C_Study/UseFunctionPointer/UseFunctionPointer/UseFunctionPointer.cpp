#include <iostream>

using namespace std;

typedef void(*SYSTEMFUNC)();

void ForWindows9x();
void ForWindowsNT();
bool IsWindows9x();

void ImportantFunc(void(*func)());
void ImportantFunc2(SYSTEMFUNC pSystemFunc);
void ForWindows9x(){
	cout << "Windows 9x�Լ��� ȣ���" << endl;
}


void ForWindowsNT(){
	cout << "Windows NT�Լ��� ȣ���" << endl;
}
bool IsWindows9x(){
	return false;
}

void ImportantFunc(void(*pSystemFunc)()){
	(*pSystemFunc)();
	(*pSystemFunc)();
}

void ImportantFunc2(SYSTEMFUNC pSystemFunc)
{
	(*pSystemFunc)();
	(*pSystemFunc)();
}

int MyFunc(int a, char strp[]){
	int num = a; 
	return 1;
};

int main(void){
	SYSTEMFUNC pfn;
	if (IsWindows9x())
		pfn = &ForWindows9x;
	else
		pfn = &ForWindowsNT;

	ImportantFunc(pfn);
	ImportantFunc2(pfn);
	
	int(*PTR)(int, char[]);
	PTR = &MyFunc;
	printf("%d\n", (*PTR)(1,"ii"));
	
	getchar();
	
	return 0;
}