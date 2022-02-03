#if !defined(AFX_UMLTEMPLATEPROPERTYDIALOG_H__BE264CA5_9335_48B3_8807_4100EAD87453__INCLUDED_)
#define AFX_UMLTEMPLATEPROPERTYDIALOG_H__BE264CA5_9335_48B3_8807_4100EAD87453__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UMLTemplatePropertyDialog.h : header file
//
#include "DiagramPropertyDlg.h"
#include "resource.h"
#include "ExListbox.h"
#include "PropertyContainer.h"

/////////////////////////////////////////////////////////////////////////////
// CUMLTemplatePropertyDialog dialog

 
//===========================================================================
// Summary:
//     The CUMLTemplatePropertyDialog class derived from CDiagramPropertyDlg
//      U M L Template Property Dialog
//===========================================================================

class CUMLTemplatePropertyDialog : public CDiagramPropertyDlg
{
// Construction
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// U M L Template Property Dialog, Constructs a CUMLTemplatePropertyDialog object.
	//		Returns A  value.  
	// Parameters:
	//		pParent---Parent, A pointer to the CWnd or NULL if the call failed.
	CUMLTemplatePropertyDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUMLTemplatePropertyDialog)
	enum { IDD = IDD_UML_PROP_TEMPLATE };
 
	// This member specify CExListBox object.  
	CExListBox	m_operation;
 
	// This member specify CExListBox object.  
	CExListBox	m_attribute;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_name;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_parameter;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString	m_propertylist;
 
	// m_name Ctrl, This member specify CEdit object.  
	CEdit	m_nameCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUMLTemplatePropertyDialog)
	protected:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Data Exchange, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDX---D X, A pointer to the CDataExchange or NULL if the call failed.
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Values, Sets a specify value to current class CUMLTemplatePropertyDialog
	// This member function is also a virtual function, you can Override it if you need,
	virtual void SetValues();

protected:

	// Generated message map functions
	
	//-----------------------------------------------------------------------
	// Summary:
	// On O K, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void OnOK();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Cancel, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void OnCancel();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Button Add Attribute, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnButtonAddAttribute();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Button Add Operation, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnButtonAddOperation();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Button Font, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnButtonFont();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Button Color, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnButtonColor();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Button Property List, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnButtonPropertyList();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Button Auto Generate, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnButtonAutoGenerate();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Button Visibility, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnButtonVisibility();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Button Auto Generate2, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnButtonAutoGenerate2();
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

 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString		m_font;
 
	// This member sets A 32-bit value used as a color value.  
	COLORREF	m_color;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Fill Listboxes, None Description.

	void FillListboxes();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Clear Listboxes, Remove the specify data from the list.

	void ClearListboxes();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Refresh Listboxes, None Description.

	void RefreshListboxes();

	
	//-----------------------------------------------------------------------
	// Summary:
	// Delete Attribute, Deletes the given object.

	void DeleteAttribute();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Delete Operation, Deletes the given object.

	void DeleteOperation();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Edit Attribute, None Description.

	void EditAttribute();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Edit Operation, None Description.

	void EditOperation();

	
	//-----------------------------------------------------------------------
	// Summary:
	// Create Attributes, You construct a CUMLTemplatePropertyDialog object in two steps. First call the constructor, then call Create, which creates the object.

	void CreateAttributes();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Create Operations, You construct a CUMLTemplatePropertyDialog object in two steps. First call the constructor, then call Create, which creates the object.

	void CreateOperations();

 
	// This member specify CPropertyContainer object.  
	CPropertyContainer	m_properties;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UMLTEMPLATEPROPERTYDIALOG_H__BE264CA5_9335_48B3_8807_4100EAD87453__INCLUDED_)
