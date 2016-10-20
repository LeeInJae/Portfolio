#pragma once
#include <string>

//hit�� ���
enum HitResult
{
	MISS, //���������� 0
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
	AIRCRAFT,  //AIRCRAFT = 99 �εθ� BATTLESHIP �� 100�� ��
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
	char x; //x��ǥ
	char y; //y��ǥ
	bool shipHit; //position �̶�� ��ü�� ������ ������ ���� ����.(��ü�� ������ �Ϻ��Ѱ� ����)
};

class CShip
{
public:
			 CShip(void);
	virtual ~CShip(void);
	
	void				AddPosition( Position pos );
	virtual HitResult	HitCheck(Position hitPos);
	std::string			GetName() {return m_Name;} //������ �Լ�
	int					GetHp() {return m_Hp;}
	Shiptype			GetType() {return m_Type;}
	virtual void		Initial();
protected:
	std::string m_Name; 
	int			m_Hp; //��������� ���������� m_�� ����
	Shiptype	m_Type;
	Position	m_Pos[5];

protected:
	int			m_PosCount;
//	bool		m_hitCheck[5];  �̷��� hit üũ�� �ص� ������, ��ü �����ΰ� �Ϻ��ϰ� �ϴ� ���� ����.
};