#include <iostream>

using namespace std;

float Divide(int a, int b){
	if (b == 0){
		throw "�������� 0 �Դϴ� !";
	}
	return (float)a / (float)b;
}

int main(void){
	try
	{
		cout << Divide(10, 2) << endl;
		cout << Divide(10, 5) << endl;
		cout << Divide(10, 3) << endl;
		cout << Divide(10, 0) << endl;
	}
	catch (const char * ex){
		cout << "���� ���� : " << ex << endl;
	}
	getchar();
	return 0;
}