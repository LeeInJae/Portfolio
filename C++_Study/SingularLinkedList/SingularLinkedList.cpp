#include <iostream>

struct Node
{
	struct Node* next;
	int data;
};

void Init( Node* phead ) //빈 Node 한개를 만들어서 head노드로 칭함( 더블포인터의 수고를 덜기 위해)
{
	phead->next = nullptr;
}

void Add_Node( Node* phead, int data )
{
	Node* new_node = new Node;

	new_node->data = data;

	new_node->next = phead->next;
	phead->next = new_node;
}

void Search_Node( Node* phead, int data )
{
	Node* node = phead;

	while( node->data != data && node->next != nullptr )
	{
		node = node->next;
	}

	if( node->next == nullptr )
		std::cout << "해당 데이터는 list에 없습니다" << std::endl;
	else
		std::cout << "해당 데이터는 list에 있습니다" << std::endl;
}

void Delete_Node( Node* phead, int data )
{
	Node* find = nullptr;
	Node* node = phead;

	while( node->data != data && node->next != nullptr )
	{
		find = node;
		node = node->next;
	}
	find->next = node->next;
	delete node;
}

int Count( Node* phead )
{
	int count = 0;
	Node* node = phead;

	while( node->next != nullptr )
	{
		node = node->next;
		++count;
		std::cout << node->data << " ";
	}
	std::cout << " list  의 총 개수 " << count <<  std::endl;
	return count;
}

void SingularLinkedList()
{
	struct Node* list = new Node;

	Init( list );
	
	Add_Node(list, 1);
	Add_Node(list, 2);
	Add_Node(list, 3);
	Add_Node(list, 4);

	Count( list );
	Search_Node( list, 3 );
	Delete_Node( list, 3 );
	Search_Node( list, 3 );
	Search_Node( list, 5 );
	Count( list );
}

int main ( void )
{
	SingularLinkedList();
	getchar();
	return 0;
}