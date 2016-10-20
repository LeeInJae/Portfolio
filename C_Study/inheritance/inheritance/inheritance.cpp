#include <iostream>

using namespace std;

class Parent{
public:
	Parent(){ cout << "나는 부모의 생성자 입니다" << endl; }
	~Parent(){ cout << "나는 부모의 소멸자 입니다" << endl; }

	void Print(){ cout << "나는 부모의 멤버함수 Print 입니다." << endl; }
};

class Child : public Parent{
public:
	Child(){ cout << "나는 자식의 생성자 입니다" << endl; }
	~Child(){ cout << "나는 자식의 소멸자 입니다" << endl; }

	void Print(){ cout << "나는 자식의 멤버함수 Print 입니다." << endl; }
};
int main(void){
	Parent p1;
	Child c1;
	cout << "---------------------------------------------" << endl;
	p1.Print();
	c1.Print();
	cout << "---------------------------------------------" << endl;
	Parent * pParent1 = new Parent();
	Child * pChild1 = new Child();
	cout << "---------------------------------------------" << endl;
	pParent1->Print();
	pChild1->Print();

	cout << "---------------------------------------------" << endl;
	Parent * pParent2 = &c1;
	pParent2->Print(); //실제 가리키는 객체가 무엇이든간에 상관없이 포인터의 타입을 기준으로 호출될 함수를 결정.(가상함수를 안쓴다면...)

	//Child * pChild2 = &p1; 오류 자식이 부모를 담을 수 없음( 부모의 그릇(?)을 따라가지 못함)

	cout << "---------------------------------------------" << endl;
	Parent * pParent3 = pChild1; //자식클래스의 포인터가 부모클래스의 포인터로 형변환 하는 것을 업캐스트라고 한다.
	pParent3->Print();
	getchar();
	return 0;
}