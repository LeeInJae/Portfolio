#include <iostream>
using namespace std;

int& RefRetFuncOne(int &ref){//ref�� num1�� ����������, �̴� �� �Լ��������� ����ִ� �����̴�.
	ref++;
	return ref;
}

int main(void){
	int num1 = 1;
	int num2 = RefRetFuncOne(num1); // RefRetFuncOne �Լ��� �����ڸ� ��ȯ�߰�, �̸� ���� ������ �����ϰ� �ִ�.(�����ϴ�)
	//�� num2�� ������ num1���� �ٸ� �����̴�.
	num1++;
	num2+=100; 
	cout << "num1 : " << num1 << endl;
	cout << "num2 : " << num2 << endl;
	getchar();
	return 0;
}