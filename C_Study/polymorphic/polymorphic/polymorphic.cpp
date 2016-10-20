#include <iostream>

using namespace std;

class Parent1{
public:
	Parent1(){ cout << "나는 Parent1 생성자 입니다" << endl; }
	~Parent1(){ cout << "나는 Parent1 소멸자 입니다" << endl; }

	virtual void Print(){ cout << "나는 Parent1 멤버함수 Print 입니다." << endl; }
};

class Child : public Parent1{
public:
	Child(){ cout << "나는 자식의 생성자 입니다" << endl; }
	~Child(){ cout << "나는 자식의 소멸자 입니다" << endl; }

	virtual void Print(){ cout << "나는 자식의 멤버함수 Print 입니다." << endl; }
};

int main(void){
	Child child1;
	child1.Print();

	Parent1 * arr[5];
	Child * pCh1 = new Child;
	Child * pCh2 = new Child;
	Child * pCh3 = new Child;
	Child * pCh4 = new Child;
	Child * pCh5 = new Child;

	arr[0] = pCh1;
	arr[1] = pCh2;
	arr[2] = pCh3;
	arr[3] = pCh4; 
	arr[4] = pCh5;
	
	for (int i = 0; i < 5; ++i){
		arr[i]->Print();
		delete arr[i];
		arr[i] = nullptr;
	}
	getchar();
	return 0;
}