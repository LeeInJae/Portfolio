#pragma once
#include "GameManager.h"
#include "PrintUI.h"
class CGameManager
{
private:
	CGameManager(void);
public:
	static CGameManager* GetInstance();
	static void			 Release();
public:
	virtual ~CGameManager(void);
	int			GetDestroyNumber() {return m_destroyNumber; }
	void		AddDestroyNumber();
	void		InitialDestroyNumber();
public:
	void Run();
protected:
	static CGameManager* m_pInstance;
	int			 m_destroyNumber;
};