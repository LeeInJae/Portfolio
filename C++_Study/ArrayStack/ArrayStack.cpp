#include <iostream>

using namespace std;

class Arr_Stack
{

public:
	Arr_Stack(int t_capacity )
	{
		m_top = 0;
		m_arr = new int[ t_capacity ];
		m_capacity = t_capacity;
	}
	~Arr_Stack()
	{
		delete[] m_arr;
	}
	void Push( int t_data );
	int	 Pop();
	bool IsEmpty();
	bool IsFull();
	void Print(){ 
		for(int i = 0; i < m_top; ++i )
		{
			cout << m_arr[i] << "  ";
		}
		cout << endl;
	}
private:
	int m_top;
	int* m_arr;
	int m_capacity;
};

void Arr_Stack::Push( int t_data )
{
	if( IsFull() )
	{
		cout << "스택이 꽉 차서 넣을 수 없습니다." << endl;
	}
	else
	{
		m_arr[ m_top++ ] = t_data;
	}
}

int Arr_Stack::Pop()
{
	return m_arr[ --m_top ];
}

bool Arr_Stack::IsEmpty()
{
	if( m_top == 0 )
	{
		cout << "스택이 비었습니다" << endl;
		return false;
	}
	return true;
}

bool Arr_Stack::IsFull()
{
	if( m_top == m_capacity )
	{
		cout << "스택이 꽉 찼습니다" << endl;
		return true;
	}
	return false;
}

int main( void )
{
	Arr_Stack* stack = new Arr_Stack( 3 );
	
	stack->Push( 1 );
	stack->Push( 2 );
	stack->Push( 3 );
	stack->Push( 4 );
	stack->Print();
	cout << stack->Pop() << endl;
	stack->Print();
	delete stack;
	getchar();
	return 0;
}