#include < iostream >
using namespace std;

//Max �Լ� ���ø������� �Լ��� ��ȯ���� �Լ��� a�� b�� Ÿ����
//int �� float�� T�� Getnericȭ�ߴ�.

template < typename T1, typename T2 > 
T2 Max( const T1&  a, const T2& b)
{
	return a > b ? a : b;
}

template <> double Max(const double& a, const double& b)
{
	return a > b ? a : b;
}

void Pro( int& a )
{
	cout << a << endl;
}
int main( void )
{
	int* b = new int;
	*b = 3;
	int c=  3;
	int& d = c;
	
	Pro( d );

	//cout << Max( 10, 20.5 );
	getchar();
	return 0;
}