#include <iostream>

using namespace std;

typedef struct _Node{
	_Node * prev;
	_Node * next;
	void * data;
}Node;

typedef struct _List{
	Node * head;
}List;

List * CreateList(){
	//head ��带 ����
	Node * head = new Node;
	if (head == nullptr){
		printf("head��� ���� ����\n");
		exit(1);
	}
	head->prev = head;
	head->next = head;
	head->data = 0;//�ǹ̾��� ������(�� �����)

	//List �� head ����� head���� ����Ŵ
	List * list = new List;
	if (list == nullptr){
		printf("list ���� ����\n");
		exit(1);
	}
	list->head = head;

	return list;
}

void insertNodeAfter(Node * node, void * data){
	if (node == nullptr){
		printf("�Ķ���� node ���� nullptr\n");
		exit(1);
	}
	Node * before = node;
	Node * after = node->next;

	if (after == nullptr){
		printf("after node ���� nullptr\n");
		exit(1);
	}

	if (before == nullptr){
		printf("before node ���� nullptr\n");
		exit(1);
	}

	Node * newNode = new Node;
	if (newNode == nullptr){
		printf("�Ķ���� node ���� nullptr\n");
		exit(1);
	}
	newNode->data = data;
	newNode->next = after;
	newNode->prev = before;

	after->prev = newNode;
	before->next = newNode;
}

void RemoveNode(Node * node, bool deleteData){
	if (node == nullptr){
		printf("node ���� nullptr\n");
		exit(1);
	}
	Node * before = node->prev;
	Node * after = node->next;

	if (after == nullptr){
		printf("after node ���� nullptr\n");
		exit(1);
	}

	if (before == nullptr){
		printf("before node ���� nullptr\n");
		exit(1);
	}

	before->next = after;
	after->prev = before;

	if (deleteData && node){
		delete node;
	}
}

bool SearchData(List * list, int data){
	if (list == nullptr){
		printf("list ���� nullptr\n");
		exit(1);
	}

	if (list->head == nullptr){
		printf("list->head ���� nullptr\n");
		exit(1);
	}
	bool isSearched = false;
	Node * current = list->head->next;
	while (current != list->head){
		if (current == nullptr){
			printf("current ���� nullptr\n");
			exit(1);
		}
		const int * curData = (int *)(current->data);
		if ((*curData) == data){
			isSearched = true;
			break;
		}
		current = current->next;
	}
	return isSearched;
}

void RemoveList(List * list, bool deleteData){
	if (list == nullptr){
		printf("list ���� nullptr\n");
		exit(1);
	}
	
	Node * current = list->head;

	do{
		Node * next = current->next;
		if (deleteData && current){
			delete current->data;
			delete current;  
		}
		current = next;
	} while (current != list->head);//list->head�� ���� ����������. �ش� �ּҰ��� ����� ���� ����

	delete list;
}

void ShowAll(List * intList){
	Node * current = intList->head->next;
	while (current != intList->head){
		const int * cur = (int *)(current->data);
		printf("%d ", (*cur));
		current = current->next;
	}
}

void AddData(List * intList, int data){
	int * newNode = new int;
	*newNode = data;
	insertNodeAfter(intList->head, newNode);
}

class A{
public:
	A(){};
	int x = 3;
};

int main(void){
	A pt1, pt2, pt3;

	pt1 = pt2 = pt3;
	List * intList = nullptr;
	intList = CreateList();

	AddData(intList, 3);
	AddData(intList, 1);
	AddData(intList, 2);
	AddData(intList, 5);
	
	printf("%d\n", SearchData(intList, 3));
	printf("%d\n", SearchData(intList, 4));
	printf("%d\n", SearchData(intList, 5));

	ShowAll(intList);
	RemoveList(intList, true);
	getchar();
	return 0;
}