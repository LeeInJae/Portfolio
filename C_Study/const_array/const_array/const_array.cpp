#include <iostream>

using namespace std;

void Func(const char arr[]){ //const char * arr = array;
	cout << "Func : arr =" << arr << endl;
	//arr[5] = "!"; error
}

int main(void){
	char array[] = "Hi, Hello Injae?"; 
	Func(array);

	printf("%s\n", array);
	getchar();
	return 0;
}