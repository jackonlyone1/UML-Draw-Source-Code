#if !defined(AFX_GETTERSETTERDIALOG_H__096C8819_CC5A_4A28_9DFC_DED7E85D4323__INCLUDED_)
#define AFX_GETTERSETTERDIALOG_H__096C8819_CC5A_4A28_9DFC_DED7E85D4323__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GetterSetterDialog.h : header file
//

#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// CGetterSetterDialog dialog

 
//===========================================================================
// Summary:
//     The CGetterSetterDialog class derived from CDialog
//      Getter Setter Dialog
//===========================================================================

class CGetterSetterDialog : public CDialog
{
// Construction
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Getter Setter Dialog, Constructs a CGetterSetterDialog object.
	//		Returns A  value.  
	// Parameters:
	//		pParent---Parent, A pointer to the CWnd or NULL if the call failed.
	CGetterSetterDialog(CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(CGetterSetterDialog)
	enum { IDD = IDD_UML_DIALOG_GETTER_SETTER };
 
	// m_setter Ctrl, This member specify CEdit object.  
	CEdit	m_setterCtrl;
 
	// m_getter Ctrl, This member specify CEdit object.  
	CEdit	m_getterCtrl;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_getter;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_setter;
	//}}AFX_DATA

 
	// This member sets TRUE if it is right.  
	BOOL m_noset;
 
	// This member sets TRUE if it is right.  
	BOOL m_noget;

// Overrides
	//{{AFX_VIRTUAL(CGetterSetterDialog)
	protected:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Data Exchange, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDX---D X, A pointer to the CDataExchange or NULL if the call failed.
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CGetterSetterDialog)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Initial Dialog, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
	virtual BOOL OnInitDialog();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On O K, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void OnOK();
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETTERSETTERDIALOG_H__096C8819_CC5A_4A28_9DFC_DED7E85D4323__INCLUDED_)
