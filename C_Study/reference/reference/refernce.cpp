#include <iostream>

void Func(int &a, int b, int *c){
	if (c != nullptr){
		*c = 10;
	}
	a = 20;
	b = 50;
}

int main(void){
	int a = 0, b = 0, c = 0;
	Func(a, b, &c);

	printf("%d %d %d\n", a, b, c);
	getchar();                                                                 

	return 0;
}