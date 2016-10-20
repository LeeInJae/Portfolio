#include <iostream>

using namespace std;

void Dog(){
	cout << "I'm a dog" << endl;
}

void Cat(){
	cout << "I'm a cat" << endl;
}

int main(void){
	void (*p)() = &Dog;
	p = &Dog;
	(*p)();
	p();
	p = &Cat;
	(*p)();
	p();
	getchar();
	return 0;
}