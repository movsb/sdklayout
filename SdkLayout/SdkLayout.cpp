#include "StdAfx.h"
#include "SdkLayout.h"

namespace SdkLayout{

bool CSdkLayout::SetLayout(HWND hWnd, LPCTSTR xml, HINSTANCE hInst)
{
	DeleteLayout();
	
	assert(::IsWindow(hWnd));
	m_hWnd = hWnd;
	CDialogBuilder builder;
	CContainerUI* pRoot = static_cast<CContainerUI*>(builder.Create(xml, &m_Manager, hInst));
	assert(pRoot);
	if(pRoot){
		m_pRoot = pRoot;
		m_pRoot->SetHWND(hWnd, &m_Manager);
	}
	return !!m_pRoot;
}

void CSdkLayout::DeleteLayout()
{
	delete m_pRoot;
	m_pRoot    = NULL;
	m_hWnd     = NULL;
}

void CSdkLayout::ResizeLayout(const RECT& rc)
{
	if(!m_pRoot || !m_hWnd) return;
	m_pRoot->SetPos(rc);
	::InvalidateRect(m_hWnd, &rc, FALSE);
}

CControlUI* CSdkLayout::FindControl(LPCTSTR name)
{
	return m_pRoot ? m_pRoot->FindControl(name) : NULL;
}

bool CSdkLayout::VisibleControl(CControlUI* pControl, bool bVisible, bool bDisplayed)
{
	if(m_pRoot && pControl){
		pControl->SetVisible(bVisible, bDisplayed);
		return true;
	}
	return false;
}

bool CSdkLayout::VisibleControl(LPCTSTR name, bool bVisible, bool bDisplayed)
{
	CControlUI* pControl = NULL;
	if(m_pRoot && (pControl=FindControl(name))){
		return VisibleControl(pControl, bVisible, bDisplayed);
	}
	return NULL;
}

}
