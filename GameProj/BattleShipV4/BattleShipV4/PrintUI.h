#pragma once

class CPrintUI
{
private:
	CPrintUI(void);

public:
	static CPrintUI* GetInstance();
	static void		 Release();

public:
	virtual ~CPrintUI(void);
	//void PrintMessage( std::string msg, bool newLine = true );
	void PrintMessage( std::string msg );
protected:
	static CPrintUI* m_pInstance; //ΩÃ±€≈Ê ∞¥√º
	
};

//static CPrintUI g_gameview;
//extern CPrintUI g_gameview;
