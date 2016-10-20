#include <iostream>
#include <list>
#include <string>

using namespace std;

class Character
{
public:
	void SetName( string name )
	{
		m_Name = name;
	}
	void SetMoney( int money )
	{
		m_Money = money;
	}
	string GetName() { return m_Name; }
	int GetMoney() { return m_Money; }
private:
	string	m_Name;
	int		m_Money;
};

//sort by name
void Sort()
{
	Character lee, kim, jung;
	lee.SetName( "lee" );
	lee.SetMoney( 300 );

	kim.SetName( "kim" );
	kim.SetMoney( 200 );

	jung.SetName( "jung" );
	jung.SetMoney( 100 );

	list<Character> student_list;	
	student_list.push_back( lee );
	student_list.push_back( kim );
	student_list.push_back( jung );

	student_list.sort( 
		[](Character& a, Character& b)
	->bool{ 
		return a.GetName() < b.GetName(); 
	} 
	);

	for( auto iter = student_list.begin(); iter != student_list.end(); ++iter )
	{
		cout << iter->GetName() << "  " << iter->GetMoney() << endl;
	}
}

void Lambda_Test()
{
	int mmm = 20;
	int bbb = 20;

	auto func = [&](int n )
	{
		if( bbb == 20)
			cout << n + mmm << "   hihi" << endl;
	};

	func( 100 ); 
}
int main( void )
{
	//Sort();
	Lambda_Test();
	getchar();
	return 0;
}