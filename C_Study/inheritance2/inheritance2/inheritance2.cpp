#include <iostream>

using namespace std;

class Parent1{
public:
	Parent1(){ cout << "나는 Parent1 생성자 입니다" << endl; }
	~Parent1(){ cout << "나는 Parent1 소멸자 입니다" << endl; }

	void Print(){ cout << "나는 Parent1 멤버함수 Print 입니다." << endl; }
};

class Parent2{
public:
	Parent2(){ cout << "나는 Parent2 생성자 입니다" << endl; }
	~Parent2(){ cout << "나는 Parent2 소멸자 입니다" << endl; }

	void Print(){ cout << "나는 Parent2 멤버함수 Print 입니다." << endl; }
};

class Child : public Parent1, public Parent2{
public:
	Child(){ cout << "나는 자식의 생성자 입니다" << endl; }
	~Child(){ cout << "나는 자식의 소멸자 입니다" << endl; }

	//void Print(){ cout << "나는 자식의 멤버함수 Print 입니다." << endl; }
};

int main(void){
	Child child1;

	//child1.Print(); 다중상속의 경우 부모에게 공통적으로 있는 멤버함수를 호출할때, 어떤것을 호출할지 명시를 해주어야함.
	child1.Parent2::Print();
	getchar();
	return 0;
}                                                                                                                                                                                                                                      