#pragma once
class CUIManager
{
private:
	CUIManager(void);

public:
	static CUIManager* GetInstance();
	static void Release();
		virtual ~CUIManager(void);
protected:
	static CUIManager* m_pInstance;
};

