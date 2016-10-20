#include <iostream>

using namespace std;

class Parent{
public:
	Parent(){ cout << "���� �θ��� ������ �Դϴ�" << endl; }
	~Parent(){ cout << "���� �θ��� �Ҹ��� �Դϴ�" << endl; }

	void Print(){ cout << "���� �θ��� ����Լ� Print �Դϴ�." << endl; }
};

class Child : public Parent{
public:
	Child(){ cout << "���� �ڽ��� ������ �Դϴ�" << endl; }
	~Child(){ cout << "���� �ڽ��� �Ҹ��� �Դϴ�" << endl; }

	void Print(){ cout << "���� �ڽ��� ����Լ� Print �Դϴ�." << endl; }
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
	pParent2->Print(); //���� ����Ű�� ��ü�� �����̵簣�� ������� �������� Ÿ���� �������� ȣ��� �Լ��� ����.(�����Լ��� �Ⱦ��ٸ�...)

	//Child * pChild2 = &p1; ���� �ڽ��� �θ� ���� �� ����( �θ��� �׸�(?)�� ������ ����)

	cout << "---------------------------------------------" << endl;
	Parent * pParent3 = pChild1; //�ڽ�Ŭ������ �����Ͱ� �θ�Ŭ������ �����ͷ� ����ȯ �ϴ� ���� ��ĳ��Ʈ��� �Ѵ�.
	pParent3->Print();
	getchar();
	return 0;
}