#if !defined(AFX_EXLISTBOX_H__1E0EF67C_EF0A_4763_A6B4_862F29BC26EE__INCLUDED_)
#define AFX_EXLISTBOX_H__1E0EF67C_EF0A_4763_A6B4_862F29BC26EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExListBox.h : header file
//

extern UINT rwm_EXLISTBOX_DBLCLICK;
extern UINT rwm_EXLISTBOX_DELETE;
extern UINT rwm_EXLISTBOX_SELCHANGE;

/////////////////////////////////////////////////////////////////////////////
// CExListBox window

 
//===========================================================================
// Summary:
//     The CExListBox class derived from CListBox
//      Ex List Box
//===========================================================================

class CExListBox : public CListBox
{
// Construction
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Ex List Box, Constructs a CExListBox object.
	//		Returns A  value.
	CExListBox();

// Attributes
public:

// Operations
public:

	
	//-----------------------------------------------------------------------
	// Summary:
	// Add String, Adds an object to the specify list.
	//		Returns a int type value.  
	// Parameters:
	//		str---Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.
	int AddString( LPCTSTR str );

// Overrides
	//{{AFX_VIRTUAL(CExListBox)
	protected:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Before Subclass Window, None Description.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Ex List Box, Destructor of class CExListBox
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CExListBox();

protected:
	//{{AFX_MSG(CExListBox)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Double click, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnDblclk();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On L Button Down, Called when the user presses the left mouse button.
	// Parameters:
	//		nFlags---Flags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		point---Specifies A CPoint type value.
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On L Button Up, Called when the user releases the left mouse button.
	// Parameters:
	//		nFlags---Flags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		point---Specifies A CPoint type value.
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Mouse Move, Called when the mouse cursor moves.
	// Parameters:
	//		nFlags---Flags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		point---Specifies A CPoint type value.
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Key Down, This member function is called by the framework to allow your application to handle a Windows message.
	// Parameters:
	//		nChar---Char, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		nRepCnt---Rep Cnt, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		nFlags---Flags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()

private:
 
	// Line, This variable specifies a 32-bit signed integer on 32-bit platforms.  
	int		m_draggedLine;

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXLISTBOX_H__1E0EF67C_EF0A_4763_A6B4_862F29BC26EE__INCLUDED_)
