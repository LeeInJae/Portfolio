#include "stdafx.h"
#include "UIManager.h"
#include "PrintUI.h"
#include "PrintGUI.h"

CUIManager* CUIManager::m_pInstance = NULL;

CUIManager::CUIManager(void)
{

}


CUIManager::~CUIManager(void)
{
	if( m_pInstance )
	{
		delete m_pInstance;
		m_pInstance = NULL;
	}
}

CUIManager* CUIManager::GetInstance()
{
	if( m_pInstance == NULL )
	{
		m_pInstance = new CUIManager();
	}
	return m_pInstance;
}
