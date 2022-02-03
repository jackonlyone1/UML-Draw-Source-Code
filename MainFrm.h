// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__793A38E4_20B0_4580_8C52_2E1FEB5A539D__INCLUDED_)
#define AFX_MAINFRM_H__793A38E4_20B0_4580_8C52_2E1FEB5A539D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MyToolBoxBar.h"

 
//===========================================================================
// Summary:
//     The CMainFrame class derived from CFOPMDIFrameWnd
//      Main Frame
//===========================================================================

class CMainFrame : public CFOPMDIFrameWnd
{
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ D Y N A M I C, None Description.
	//		Returns A  value.  
	// Parameters:
	//		CMainFrame---Main Frame, Specifies a CMainFrame object.
	DECLARE_DYNAMIC(CMainFrame)
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Main Frame, Constructs a CMainFrame object.
	//		Returns A  value.
	CMainFrame();

// Attributes

// Operations
public:

 
	// Pan Bar, This member specify E-XD++ CFOPNewPanBar object.  
	CFOPNewPanBar  m_wndPanBar;
 
	// File Bar, This member specify CMyToolBoxBar object.  
	CMyToolBoxBar m_FileBar;
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Before Create Window, Called before the creation of the Windows window attached to this CWnd object.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		cs---Specifies a CREATESTRUCT& cs object.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Main Frame, Destructor of class CMainFrame
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CMainFrame();
#ifdef _DEBUG
	
	//-----------------------------------------------------------------------
	// Summary:
	// Assert Valid, Assert performs a validity check on this object by checking its internal state.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void AssertValid() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Dumps the contents of your object to a CDumpContext object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		dc---Specifies a CDumpContext& dc object.
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
 
	// Status Bar, This member specify E-XD++ CFOPStatusBar object.  
	CFOPStatusBar		m_wndStatusBar;
 
	// Tool Bar, This member specify E-XD++ CFOPToolBar object.  
	CFOPToolBar		m_wndToolBar;
 
	// Draw Tool Bar, This member specify E-XD++ CFOPToolBar object.  
	CFOPToolBar		m_wndDrawToolBar;
 
	// Format Tool Bar, This member specify E-XD++ CFOPToolBar object.  
	CFOPToolBar		m_wndFormatToolBar;
 
	// Align Tool Bar, This member specify E-XD++ CFOPToolBar object.  
	CFOPToolBar		m_wndAlignToolBar;
 
	// Link Tool Bar, This member specify E-XD++ CFOPToolBar object.  
	CFOPToolBar		m_wndLinkToolBar;
 
	// Opt Tool Bar, This member specify E-XD++ CFOPToolBar object.  
	CFOPToolBar		m_wndOptToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On View Drawbar, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnViewDrawbar();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update View Drawbar, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateViewDrawbar(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On View Formatbar, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnViewFormatbar();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update View Formatbar, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateViewFormatbar(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On View Toolbox, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnViewToolbox();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update View Toolbox, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateViewToolbox(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Create, Called as a part of window creation.
	//		Returns a int type value.  
	// Parameters:
	//		LPCREATESTRUCT---P C R E A T E S T R U C T, Specifies a LPCREATESTRUCT LPCREATESTRUCT object.
	afx_msg int OnCreate(LPCREATESTRUCT LPCREATESTRUCT);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On View Fullscreen, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnViewFullscreen();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Update View Fullscreen, Called to notify a view that its document has been modified.
	// Parameters:
	//		pCmdUI---Cmd U I, A pointer to the CCmdUI or NULL if the call failed.
	afx_msg void OnUpdateViewFullscreen(CCmdUI* pCmdUI);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Drop Files, This member function is called by the framework to allow your application to handle a Windows message.
	// Parameters:
	//		hDropInfo---Drop Information, Specifies a HDROP hDropInfo object.
	afx_msg void OnDropFiles(HDROP hDropInfo);
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// On View Valid Message, This member function is called by the framework to allow your application to handle a Windows message.
	//		Returns A 32-bit value returned from a window procedure or callback function.  
	// Parameters:
	//		WPARAM---P A R A M, Provides additional information used in processing the message. The parameter value depends on the message.  
	//		LPARAM---P A R A M, Specifies A lparam value.
	afx_msg LRESULT OnViewValidMsg(WPARAM, LPARAM);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On View In Valid Message, This member function is called by the framework to allow your application to handle a Windows message.
	//		Returns A 32-bit value returned from a window procedure or callback function.  
	// Parameters:
	//		WPARAM---P A R A M, Provides additional information used in processing the message. The parameter value depends on the message.  
	//		LPARAM---P A R A M, Specifies A lparam value.
	afx_msg LRESULT OnViewInValidMsg(WPARAM, LPARAM);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Shape Changed Message, This member function is called by the framework to allow your application to handle a Windows message.
	//		Returns A 32-bit value returned from a window procedure or callback function.  
	// Parameters:
	//		WPARAM---P A R A M, Provides additional information used in processing the message. The parameter value depends on the message.  
	//		LPARAM---P A R A M, Specifies A lparam value.
	afx_msg LRESULT OnShapeChangedMsg(WPARAM,LPARAM);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Canvas Changed Message, This member function is called by the framework to allow your application to handle a Windows message.
	//		Returns A 32-bit value returned from a window procedure or callback function.  
	// Parameters:
	//		WPARAM---P A R A M, Provides additional information used in processing the message. The parameter value depends on the message.  
	//		LPARAM---P A R A M, Specifies A lparam value.
	afx_msg LRESULT OnCanvasChangedMsg(WPARAM,LPARAM);
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__793A38E4_20B0_4580_8C52_2E1FEB5A539D__INCLUDED_)
