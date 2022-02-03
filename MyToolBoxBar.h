#if !defined(FO_MYTOOLBOXBAR_H__7D3B24C2_F425_11D5_A4D1_525400EA266C__INCLUDED_)
#define AFC_MYTOOLBOXBAR_H__7D3B24C2_F425_11D5_A4D1_525400EA266C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CMyToolBoxBar dialog

 
//===========================================================================
// Summary:
//     The CMyToolBoxBar class derived from CFOPControlBar
//      My Tool Box Bar
//===========================================================================

class CMyToolBoxBar : public CFOPControlBar
{
// Construction
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// My Tool Box Bar, Constructs a CMyToolBoxBar object.
	//		Returns A  value.
	CMyToolBoxBar();

// Attributes
public:
	// Attributes
 
	// Shapes, This member specify E-XD++ CFOListItemObjList object.  
	CFOListItemObjList m_Shapes;

	// Load resource file.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Load From File, Call this function to read a specified number of bytes from the archive.

	void LoadFromFile();

	// Find item with id.
	// nIndex -- the id of item.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Find Object By I D, Searches the list sequentially to find the first CObject pointer matching the specified CObject pointer. 
	//		Returns a pointer to the object CFOListItemObj ,or NULL if the call failed  
	// Parameters:
	//		nIndex---Index, Specifies A integer value.
	CFOListItemObj *FindObjByID(int nIndex);

public:

 
	// Tool, This member specify E-XD++ CFOMultiToolBoxWnd object.  
	CFOMultiToolBoxWnd m_wndTool;

public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyToolBoxBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// C My Tool Box Bar, Destructor of class CMyToolBoxBar
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CMyToolBoxBar();
	// Generated message map functions
protected:
	//{{AFX_MSG(CMyToolBoxBar)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Create, Called as a part of window creation.
	//		Returns a int type value.  
	// Parameters:
	//		lpCreateStruct---Create Struct, Specifies a LPCREATESTRUCT lpCreateStruct object.
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Size, Called after the size of CWnd has changed.
	// Parameters:
	//		nType---Type, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		cx---Specifies A integer value.  
	//		cy---Specifies A integer value.
	afx_msg void OnSize(UINT nType, int cx, int cy);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Erase Background, Called when the window background needs erasing.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.
	afx_msg BOOL OnEraseBkgnd( CDC* pDC );
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFC_MYTOOLBOXBAR_H__7D3B24C2_F425_11D5_A4D1_525400EA266C__INCLUDED_)
