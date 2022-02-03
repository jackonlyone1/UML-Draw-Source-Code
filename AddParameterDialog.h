#if !defined(AFX_ADDPARAMETERDIALOG_H__AC07C8A9_94E8_4A75_9845_82FA872C6815__INCLUDED_)
#define AFX_ADDPARAMETERDIALOG_H__AC07C8A9_94E8_4A75_9845_82FA872C6815__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddParameterDialog.h : header file
//
#include "resource.h"
#include "Parameter.h"

/////////////////////////////////////////////////////////////////////////////
// CAddParameterDialog dialog

 
//===========================================================================
// Summary:
//     The CAddParameterDialog class derived from CDialog
//      Add Parameter Dialog
//===========================================================================

class CAddParameterDialog : public CDialog
{
// Construction
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Add Parameter Dialog, Constructs a CAddParameterDialog object.
	//		Returns A  value.  
	// Parameters:
	//		pParent---Parent, A pointer to the CWnd or NULL if the call failed.
	CAddParameterDialog(CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(CAddParameterDialog)
	enum { IDD = IDD_UML_PROP_CLASS_OPERATION_PARAMETER };
 
	// m_type Ctrl, This member specify CEdit object.  
	CEdit	m_typeCtrl;
 
	// m_name Ctrl, This member specify CEdit object.  
	CEdit	m_nameCtrl;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_name;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_type;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_defaultvalue;
 
	// This member sets TRUE if it is right.  
	BOOL	m_in;
 
	// This member sets TRUE if it is right.  
	BOOL	m_out;
 
	// This member sets TRUE if it is right.  
	BOOL	m_reference;
	//}}AFX_DATA

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Parameter, Sets a specify value to current class CAddParameterDialog
	// Parameters:
	//		parameter---A pointer to the CParameter or NULL if the call failed.
	void			SetParameter( CParameter* parameter );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Parameter, Returns the specified value.
	//		Returns a pointer to the object CParameter,or NULL if the call failed
	CParameter*		GetParameter();

// Overrides
	//{{AFX_VIRTUAL(CAddParameterDialog)
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

	//{{AFX_MSG(CAddParameterDialog)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On O K, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void OnOK();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Initial Dialog, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()

private:
 
	// This member maintains a pointer to the object CParameter.  
	CParameter*	m_parameter;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDPARAMETERDIALOG_H__AC07C8A9_94E8_4A75_9845_82FA872C6815__INCLUDED_)
