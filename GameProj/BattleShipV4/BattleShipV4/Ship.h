#pragma once
#include <string>

//hit의 결과
enum HitResult
{
	MISS, //내부적으로 0
	HIT,  // 1
	DESTROY,//2
	DESTROY_AIRCRAFT,
	DESTROY_BATTLESHIP,
	DESTROY_CRUISER,
	DESTROY_DESTROYER,
	DESTROY_SUBMARINE,
};
 
enum Shiptype
{
	EMPTY,
	AIRCRAFT,  //AIRCRAFT = 99 로두면 BATTLESHIP 은 100이 됨
	BATTLESHIP,
	CRUISER,
	DESTROYER,
	SUBMARINE,
	NONE,
};
enum DecideHorizonOrVertical
{
	HORIZON,
	VERTICAL,
};
struct Position
{
	char x; //x좌표
	char y; //y좌표
	bool shipHit; //position 이라는 객체가 정보를 가지는 것이 좋다.(객체는 스스로 완벽한게 좋다)
};

class CShip
{
public:
			 CShip(void);
	virtual ~CShip(void);
	
	void				AddPosition( Position pos );
	virtual HitResult	HitCheck(Position hitPos);
	std::string			GetName() {return m_Name;} //접근자 함수
	int					GetHp() {return m_Hp;}
	Shiptype			GetType() {return m_Type;}
	virtual void		Initial();
protected:
	std::string m_Name; 
	int			m_Hp; //멤버변수는 관례적으로 m_을 붙임
	Shiptype	m_Type;
	Position	m_Pos[5];

protected:
	int			m_PosCount;
//	bool		m_hitCheck[5];  이렇게 hit 체크를 해도 되지만, 객체 스스로가 완벽하게 하는 것이 낫다.
};