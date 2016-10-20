#include <iostream>

class Singleton
{
public:
	static Singleton* Getinstance();
	static void ReleaseInstance();
	void Print() { std::cout << "hi" << std:: endl; }
	
private:
	Singleton( void ){};
	~Singleton( void ){};
private:
	static Singleton*	m_pInstance;
};

Singleton* Singleton::Getinstance()
{
	if( m_pInstance == nullptr )
	{
		m_pInstance = new Singleton;
	}
	return m_pInstance;
}

void Singleton::ReleaseInstance()
{
	if( m_pInstance )
	{
		delete	m_pInstance;
		m_pInstance = nullptr;
	}
}

Singleton* Singleton::m_pInstance = nullptr;

int main( void )
{
	Singleton::Getinstance()->Print();
	getchar();
	return 0;
}