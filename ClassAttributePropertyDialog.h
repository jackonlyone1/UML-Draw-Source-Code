#if !defined(AFX_CLASSATTRIBUTEPROPERTYDIALOG_H__EFB515DB_9276_4445_B25D_B6272411C3E5__INCLUDED_)
#define AFX_CLASSATTRIBUTEPROPERTYDIALOG_H__EFB515DB_9276_4445_B25D_B6272411C3E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClassAttributePropertyDialog.h : header file
//
#include "resource.h"
#include "Attribute.h"
#include "PropertyContainer.h"

/////////////////////////////////////////////////////////////////////////////
// CClassAttributePropertyDialog dialog

 
//===========================================================================
// Summary:
//     The CClassAttributePropertyDialog class derived from CDialog
//      Class Attribute Property Dialog
//===========================================================================

class CClassAttributePropertyDialog : public CDialog
{
// Construction
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Class Attribute Property Dialog, Constructs a CClassAttributePropertyDialog object.
	//		Returns A  value.  
	// Parameters:
	//		pParent---Parent, A pointer to the CWnd or NULL if the call failed.
	CClassAttributePropertyDialog(CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(CClassAttributePropertyDialog)
	enum { IDD = IDD_UML_PROP_CLASS_ATTRIBUTE };
 
	// m_type Ctrl, This member specify CEdit object.  
	CEdit	m_typeCtrl;
 
	// m_name Ctrl, This member specify CEdit object.  
	CEdit	m_nameCtrl;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_name;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_type;
 
	// This variable specifies a 32-bit signed integer on 32-bit platforms.  
	int		m_access;
 
	// This member sets TRUE if it is right.  
	BOOL	m_static;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString m_multiplicity;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString m_defaultvalue;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString m_propertylist;
	//}}AFX_DATA

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Attribute, Sets a specify value to current class CClassAttributePropertyDialog
	// Parameters:
	//		attribute---A pointer to the CAttribute or NULL if the call failed.
	void SetAttribute( CAttribute* attribute );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Attribute, Returns the specified value.
	//		Returns a pointer to the object CAttribute,or NULL if the call failed
	CAttribute* GetAttribute() const;

// Overrides
	//{{AFX_VIRTUAL(CClassAttributePropertyDialog)
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
	//{{AFX_MSG(CClassAttributePropertyDialog)
	
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
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()

private:
	// Private data
 
	// This member maintains a pointer to the object CAttribute.  
	CAttribute* m_attribute;
 
	// This member specify CPropertyContainer object.  
	CPropertyContainer	m_properties;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLASSATTRIBUTEPROPERTYDIALOG_H__EFB515DB_9276_4445_B25D_B6272411C3E5__INCLUDED_)
