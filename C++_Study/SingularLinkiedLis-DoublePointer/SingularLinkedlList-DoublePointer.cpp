#include <iostream>
#define INF 214748647

struct Node
{
	struct Node* next;
	int data;
};

void Add_Node( struct Node** phead, int data)
{
	struct Node* new_node = new struct Node;
	
	new_node->data = data;
	new_node->next = nullptr;

	if( *phead == nullptr )
	{
		*phead = new struct Node;
		(*phead)->data = data;
		(*phead)->next = nullptr;
	}
	else
	{
		struct Node* tail = *phead;
		
		while( tail->next != nullptr )
		{
			tail = tail->next;
		}
		tail->next = new_node;
	}
}

int Search_Node( Node** phead, int data )
{
	if( *phead == nullptr )
	{
		std::cout << "데이터가 존재하지 않습니다" << std::endl;
		return INF;
	}
	else
	{
		struct Node* tail = *phead;
		while( tail->next != nullptr && tail->data != data )
		{
			tail = tail->next;
		}
		
		if( tail->data == data )
		{
			std::cout << "데이터가 존재합니다" << std::endl;
			return data;
		}
		else
		{
			std::cout << "데이터가 존재하지 않습니다" << std::endl;
			return INF;
		}
	}
}

void Delete_Node( struct Node** phead, int data )
{
	if( *phead == nullptr )
	{
		std::cout << "해당하는 데이터가 없습니다" << std::endl;
	}
	else if( (*phead)->data == data )
	{
		struct Node* temp = *phead;
		*phead = (*phead)->next;
		delete temp;
	}
	else
	{
		struct Node* prev_tail = *phead;
		struct Node* tail = *phead;
		
		while( tail->next != nullptr && tail->data != data )
		{
			prev_tail = tail;
			tail = tail->next;
		}

		if( tail->data == data )
		{
			std::cout << "데이터를 삭제합니다" << std::endl;
			prev_tail->next = tail->next;
			delete tail;
			tail = nullptr;
		}
		else
		{
			std::cout << "데이터가 존재하지 않습니다" << std::endl;
		}
	}
}

void Print_List( struct Node** phead )
{
	if( *phead == nullptr )
	{
		std::cout << "list에 데이터가 없습니다" << std::endl;
	}
	else
	{
		struct Node* tail = *phead;
		while( tail->next != nullptr )
		{
			std::cout << tail->data << "  " << std::endl;
			tail = tail->next;
		}
		std::cout << tail->data << "  " << std::endl;
	}
}
void SingularList()
{
	struct Node* list = nullptr;

	Add_Node( &list, 1 );
	Add_Node( &list, 2 );
	Add_Node( &list, 3 );
	Add_Node( &list, 4 );
	Add_Node( &list, 5 );
	Add_Node( &list, 6 );
	
	Print_List( &list );
	Search_Node( &list, 7 );
	Delete_Node( &list , 1 );
	Print_List( &list );
}

int main( void )
{
	std::cout << INF << std::endl;
	SingularList();
	getchar();
	return 0;
}