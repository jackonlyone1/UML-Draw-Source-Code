#if !defined(AFX_CLASSOPERATIONPROPERTYDIALOG_H__3497CFE6_762F_4167_91CC_D8A71E16379F__INCLUDED_)
#define AFX_CLASSOPERATIONPROPERTYDIALOG_H__3497CFE6_762F_4167_91CC_D8A71E16379F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClassOperationPropertyDialog.h : header file
//

#include "resource.h"
#include "StringHelpers.h"
#include "ExListBox.h"
#include "PropertyContainer.h"
#include "ParameterContainer.h"
#include "Operation.h"

/////////////////////////////////////////////////////////////////////////////
// CClassOperationPropertyDialog dialog

 
//===========================================================================
// Summary:
//     The CClassOperationPropertyDialog class derived from CDialog
//      Class Operation Property Dialog
//===========================================================================

class CClassOperationPropertyDialog : public CDialog
{
// Construction
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Operation, Returns the specified value.
	//		Returns a pointer to the object COperation,or NULL if the call failed
	COperation* GetOperation() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Operation, Sets a specify value to current class CClassOperationPropertyDialog
	// Parameters:
	//		operation---A pointer to the COperation or NULL if the call failed.
	void SetOperation( COperation* operation );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Class Operation Property Dialog, Constructs a CClassOperationPropertyDialog object.
	//		Returns A  value.  
	// Parameters:
	//		pParent---Parent, A pointer to the CWnd or NULL if the call failed.
	CClassOperationPropertyDialog(CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(CClassOperationPropertyDialog)
	enum { IDD = IDD_UML_PROP_CLASS_OPERATION };
 
	// m_type Ctrl, This member specify CEdit object.  
	CEdit	m_typeCtrl;
 
	// m_name Ctrl, This member specify CEdit object.  
	CEdit	m_nameCtrl;
 
	// This member sets TRUE if it is right.  
	BOOL	m_abstract;
 
	// This member sets TRUE if it is right.  
	BOOL	m_static;
 
	// This member sets TRUE if it is right.  
	BOOL	m_const;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_name;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_type;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString m_propertylist;
 
	// This variable specifies a 32-bit signed integer on 32-bit platforms.  
	int		m_access;
 
	// This member specify CExListBox object.  
	CExListBox	m_parameter;
	//}}AFX_DATA

// Overrides
	//{{AFX_VIRTUAL(CClassOperationPropertyDialog)
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
	//{{AFX_MSG(CClassOperationPropertyDialog)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Button Add, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnButtonAdd();
	
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
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Button Property List, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnButtonPropertyList();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Check Const, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnCheckConst();
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Listbox Double click Click, This member function is called by the framework to allow your application to handle a Windows message.
	//		Returns A 32-bit value returned from a window procedure or callback function.  
	// Parameters:
	//		id---Provides additional information used in processing the message. The parameter value depends on the message.  
	//		LPARAM---P A R A M, Specifies A lparam value.
	LRESULT OnListboxDblClick( WPARAM id, LPARAM );
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Listbox Delete, This member function is called by the framework to allow your application to handle a Windows message.
	//		Returns A 32-bit value returned from a window procedure or callback function.  
	// Parameters:
	//		id---Provides additional information used in processing the message. The parameter value depends on the message.  
	//		LPARAM---P A R A M, Specifies A lparam value.
	LRESULT OnListboxDelete( WPARAM id, LPARAM );

	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
private:
	// Private data
 
	// This member maintains a pointer to the object COperation.  
	COperation* m_operation;
 
	// This member specify CPropertyContainer object.  
	CPropertyContainer	m_properties;
 
	// This member specify CParameterContainer object.  
	CParameterContainer	m_parameters;

	// Private helpers
	
	//-----------------------------------------------------------------------
	// Summary:
	// Fill Parameter List, None Description.

	void	FillParameterList();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLASSOPERATIONPROPERTYDIALOG_H__3497CFE6_762F_4167_91CC_D8A71E16379F__INCLUDED_)
