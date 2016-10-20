#include <iostream>
#include <string>
using namespace std;


int main(void){
	char cs[20];
	string cpps;

	cin.getline(cs, 20);
	getline(cin, cpps);

	cout << cs << endl;
	cout << cpps << endl;
	getchar();
	return 0;
}