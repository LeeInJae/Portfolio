#include <iostream>

using namespace std;

void ForWindows9x();
void ForWindowsNT();
bool IsWindows9x();
void ImportantFunc();

void ForWindows9x(){
	cout << "Windows 9x�Լ��� ȣ���" << endl;
}


void ForWindowsNT(){
	cout << "Windows NT�Լ��� ȣ���" << endl;
}
bool IsWindows9x(){
	return false;
}

void ImportantFunc(){
	if (IsWindows9x())
		ForWindows9x();
	else
		ForWindowsNT();

	//////
	if (IsWindows9x())
		ForWindows9x();
	else
		ForWindowsNT();
}

int main(void){
	ImportantFunc();
	getchar();
	return 0;
}