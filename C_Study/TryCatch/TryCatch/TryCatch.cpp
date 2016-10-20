#include <iostream>

using namespace std;

float Divide(int a, int b){
	if (b == 0){
		throw "피제수가 0 입니다 !";
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
		cout << "예외 종류 : " << ex << endl;
	}
	getchar();
	return 0;
}