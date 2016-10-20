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
	//head 노드를 생성
	Node * head = new Node;
	if (head == nullptr){
		printf("head노드 생성 오류\n");
		exit(1);
	}
	head->prev = head;
	head->next = head;
	head->data = 0;//의미없는 데이터(빈 헤드노드)

	//List 의 head 멤버를 head노드로 가리킴
	List * list = new List;
	if (list == nullptr){
		printf("list 생성 오류\n");
		exit(1);
	}
	list->head = head;

	return list;
}

void insertNodeAfter(Node * node, void * data){
	if (node == nullptr){
		printf("파라미터 node 값이 nullptr\n");
		exit(1);
	}
	Node * before = node;
	Node * after = node->next;

	if (after == nullptr){
		printf("after node 값이 nullptr\n");
		exit(1);
	}

	if (before == nullptr){
		printf("before node 값이 nullptr\n");
		exit(1);
	}

	Node * newNode = new Node;
	if (newNode == nullptr){
		printf("파라미터 node 값이 nullptr\n");
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
		printf("node 값이 nullptr\n");
		exit(1);
	}
	Node * before = node->prev;
	Node * after = node->next;

	if (after == nullptr){
		printf("after node 값이 nullptr\n");
		exit(1);
	}

	if (before == nullptr){
		printf("before node 값이 nullptr\n");
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
		printf("list 값이 nullptr\n");
		exit(1);
	}

	if (list->head == nullptr){
		printf("list->head 값이 nullptr\n");
		exit(1);
	}
	bool isSearched = false;
	Node * current = list->head->next;
	while (current != list->head){
		if (current == nullptr){
			printf("current 값이 nullptr\n");
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
		printf("list 값이 nullptr\n");
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
	} while (current != list->head);//list->head의 값이 지워졌지만. 해당 주소값을 사용할 수는 있음

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