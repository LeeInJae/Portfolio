#include <iostream>
#include <string>

using namespace std;

int main(void){
	string cppstr = "I am a good Boy";
	const char * cstr = NULL;

	cstr = cppstr.c_str();

	cout << cstr << endl;
	cout << cppstr << endl;
	getchar();
	return 0;
}
