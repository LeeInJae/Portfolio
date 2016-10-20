#include <iostream>
using namespace std;

int& RefRetFuncOne(int &ref){//ref는 num1의 참조자지만, 이는 이 함수내에서만 살아있는 변수이다.
	ref++;
	return ref;
}

int main(void){
	int num1 = 1;
	int num2 = RefRetFuncOne(num1); // RefRetFuncOne 함수가 참조자를 반환했고, 이를 단지 변수에 저장하고 있다.(가능하다)
	//즉 num2는 완전히 num1과는 다른 변수이다.
	num1++;
	num2+=100; 
	cout << "num1 : " << num1 << endl;
	cout << "num2 : " << num2 << endl;
	getchar();
	return 0;
}