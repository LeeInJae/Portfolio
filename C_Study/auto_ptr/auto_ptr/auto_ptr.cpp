#include <iostream>
#include <memory>
using namespace std;

int main(void){
	auto_ptr<int> p(new int); //auto_ptr�� new[] �����ڸ� ����� �� ����.

	*p = 100;
	cout << *p << endl;
	getchar();
	return 0;//auto_ptr�� ���α׷��� ����Ǹ� �ڵ����� �޸�����.
}