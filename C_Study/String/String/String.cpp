#include <iostream>
#include <string>

using namespace std;

int main(void){
	char cstr[] = "Are you a string, too";
	string cppstr;
	
	cppstr = cstr;
	cppstr += "hihi";
	cout << cstr << endl;
	cout << cppstr << endl;
	getchar();
	return 0;
}
