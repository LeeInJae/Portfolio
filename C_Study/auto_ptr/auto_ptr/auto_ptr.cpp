#include <iostream>
#include <memory>
using namespace std;

int main(void){
	auto_ptr<int> p(new int); //auto_ptr은 new[] 연산자를 사용할 수 없음.

	*p = 100;
	cout << *p << endl;
	getchar();
	return 0;//auto_ptr은 프로그램이 종료되면 자동으로 메모리해제.
}