#include <iostream>

#define INF 2147483647

struct Node
{
	struct Node* prev;
	struct Node* next;
	int data;
};

void Add_Node( struct Node* phead , int data )
{
	struct Node* new_node = new struct Node;

	new_node->data = data;
	
	struct Node* tail = phead->prev;

	tail->next->prev = new_node;
	tail->next = new_node;
	new_node->next = phead;
	new_node->prev = tail;
}

void Search_Node( struct Node* phead, int data )
{
	struct Node* tail = phead;

	while( tail->next != nullptr && tail->data != data && tail->next != phead )
	{
		tail = tail->next;
	}

	if( tail->data == data )
	{
		std::cout << "data 가 있습니다." << std::endl;
	}
	else
	{
		std::cout << "data가 없습니다." << std::endl;
	}
}

void Delete_Node( struct Node* phead, int data )
{
	struct Node* prev_tail = phead;
	struct Node* tail = phead;

	while( tail->next != nullptr && tail->data != data && tail->next != phead )
	{
		prev_tail = tail;
		tail = tail->next;
	}

	if( tail->data == data )
	{
		std::cout << "data 를 지웁니다." << std::endl;
		prev_tail->next = tail->next;
		tail->next->prev = prev_tail;
		delete tail;
	}
	else
	{
		std::cout << "data가 없습니다." << std::endl;
	}
}

void Proint_Node( struct Node* phead )
{
	struct Node* tail = phead->next;

	while( tail->next != nullptr && tail->next != phead )
	{
		std::cout << tail->data << "  ";
		tail = tail->next;
	}

	if( tail != nullptr )
	{
		std::cout << tail->data << std::endl;
	}
}

void CircularDoubleLinkedList()
{
	struct Node* list = new struct Node;
	list->next = list;
	list->prev = list;
	list->data = INF;

	Add_Node( list, 1 );
	Add_Node( list, 2 );
	Add_Node( list, 3 );
	Add_Node( list, 4 );
	Add_Node( list, 5 );
	Proint_Node( list );
	Search_Node( list , 10 );
	Search_Node( list , 7 );
	Delete_Node( list ,3 );
	Delete_Node( list ,5 );
	Proint_Node( list );

}

int main( void )
{
	CircularDoubleLinkedList();
	getchar();
	return 0;
}