#include <iostream>
#define INF 2147483647

struct Node
{
	struct Node* prev;
	struct Node* next;
	int data;
};

void Add_Node( struct Node* phead, int data )
{
	struct Node* new_node = new struct Node;
	
	new_node->data = data;
	new_node->prev = phead;
	new_node->next = phead->next;
	
	phead->next = new_node;
	phead->next->prev = new_node;
}

int Search_Node( struct Node* phead, int data )
{
	struct Node* tail = phead;

	while( tail->next != nullptr && tail->data != data )
	{
		tail = tail->next;
	}
	if( tail->data != data )
	{
		std::cout << "찾는 데이터가 없습니다" << std::endl;
		return INF;
	}
	else if( tail->data == data )
	{
		std::cout << "찾는 데이터가 있습니다" << std::endl;
		return tail->data;
	}
	return INF;
}

void Delete_Node( struct Node* phead, int data )
{
	struct Node* prev_tail = phead;
	struct Node* tail = phead;

	while( tail->next != nullptr && tail->data != data )
	{
		prev_tail = tail;
		tail = tail->next;
	}

	if( tail->data != data )
	{
		std::cout << "찾는 데이터가 없습니다" << std::endl;
	}
	else if( tail->data == data )
	{
		std::cout << "찾는 데이터를 지웁니다" << std::endl;
		prev_tail->next = tail->next;
		tail->next->prev = prev_tail;
		delete tail;
	}
}

void Print_Node( struct Node* phead )
{
	struct Node* tail = phead->next;

	while( tail->next != nullptr )
	{
		std::cout << tail->data << "  ";
		tail = tail->next;

	}

	if( tail != nullptr )
	{
		std::cout << tail->data << "  " << std::endl;
	}
}

void DoubleLinkedList()
{
	struct Node* list = new struct Node;
	
	list->data = -1;
	list->next = nullptr;
	list->prev = nullptr;

	Add_Node( list, 1 );
	Add_Node( list, 2 );
	Add_Node( list, 3 );
	Add_Node( list, 4 );
	Print_Node( list );
	Delete_Node( list, 2 );
	Delete_Node( list, 4 );
	Print_Node( list );
	Delete_Node( list, 4 );
	Add_Node( list, 100 );
	Print_Node( list );
}
int main( void )
{
	DoubleLinkedList();
	getchar();
	return 0;
}