#include <iostream>

using namespace std;

class Parent1{
public:
	Parent1(){ cout << "���� Parent1 ������ �Դϴ�" << endl; }
	~Parent1(){ cout << "���� Parent1 �Ҹ��� �Դϴ�" << endl; }

	void Print(){ cout << "���� Parent1 ����Լ� Print �Դϴ�." << endl; }
};

class Parent2{
public:
	Parent2(){ cout << "���� Parent2 ������ �Դϴ�" << endl; }
	~Parent2(){ cout << "���� Parent2 �Ҹ��� �Դϴ�" << endl; }

	void Print(){ cout << "���� Parent2 ����Լ� Print �Դϴ�." << endl; }
};

class Child : public Parent1, public Parent2{
public:
	Child(){ cout << "���� �ڽ��� ������ �Դϴ�" << endl; }
	~Child(){ cout << "���� �ڽ��� �Ҹ��� �Դϴ�" << endl; }

	//void Print(){ cout << "���� �ڽ��� ����Լ� Print �Դϴ�." << endl; }
};

int main(void){
	Child child1;

	//child1.Print(); ���߻���� ��� �θ𿡰� ���������� �ִ� ����Լ��� ȣ���Ҷ�, ����� ȣ������ ��ø� ���־����.
	child1.Parent2::Print();
	getchar();
	return 0;
}                                                                                                                                                                                                                                      