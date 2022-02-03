#if !defined(AFX_CLASSDISPLAYPROPERTYDIALOG_H__94871CF8_C790_4030_9EC1_DE85F2119CA1__INCLUDED_)
#define AFX_CLASSDISPLAYPROPERTYDIALOG_H__94871CF8_C790_4030_9EC1_DE85F2119CA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClassDisplayPropertyDialog.h : header file
//

#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// CClassDisplayPropertyDialog dialog

 
//===========================================================================
// Summary:
//     The CClassDisplayPropertyDialog class derived from CDialog
//      Class Display Property Dialog
//===========================================================================

class CClassDisplayPropertyDialog : public CDialog
{
// Construction
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Class Display Property Dialog, Constructs a CClassDisplayPropertyDialog object.
	//		Returns A  value.  
	// Parameters:
	//		pParent---Parent, A pointer to the CWnd or NULL if the call failed.
	CClassDisplayPropertyDialog(CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(CClassDisplayPropertyDialog)
	enum { IDD = IDD_UML_PROP_CLASS_DISPLAY };
 
	// This member sets TRUE if it is right.  
	BOOL	m_noattributenames;
 
	// This member sets TRUE if it is right.  
	BOOL	m_noattributes;
 
	// This member sets TRUE if it is right.  
	BOOL	m_nomarkers;
 
	// This member sets TRUE if it is right.  
	BOOL	m_nooperations;
 
	// This member sets TRUE if it is right.  
	BOOL	m_onlypublic;
	//}}AFX_DATA


// Overrides
	//{{AFX_VIRTUAL(CClassDisplayPropertyDialog)
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
	//{{AFX_MSG(CClassDisplayPropertyDialog)
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLASSDISPLAYPROPERTYDIALOG_H__94871CF8_C790_4030_9EC1_DE85F2119CA1__INCLUDED_)
