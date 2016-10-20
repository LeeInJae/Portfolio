#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(void){
	string cppstr = "I am good boy";
	char * cstr = new char[cppstr.size() + 1];

	strcpy_s(cstr, cppstr.size() + 1, cppstr.c_str());
	cstr[0] = 'K';

	cout << cstr << endl;
	cout << cppstr << endl;

	delete[] cstr;
	cstr = nullptr;

	getchar();
	return 0;
}