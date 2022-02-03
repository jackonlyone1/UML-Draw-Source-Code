// UMLSampleView.h : interface of the CUMLSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UMLSAMPLEVIEW_H__4A70BD8D_4040_40B3_AAE1_AF397770489F__INCLUDED_)
#define AFX_UMLSAMPLEVIEW_H__4A70BD8D_4040_40B3_AAE1_AF397770489F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FoUMLEntityClass.h"

 
//===========================================================================
// Summary:
//     The CUMLSampleView class derived from CFODrawView
//      U M L Sample View
//===========================================================================

class CUMLSampleView : public CFODrawView
{
protected: // create from serialization only
	
	//-----------------------------------------------------------------------
	// Summary:
	// U M L Sample View, Constructs a CUMLSampleView object.
	//		Returns A  value.
	CUMLSampleView();
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ D Y N C R E A T E, None Description.
	//		Returns A  value.  
	// Parameters:
	//		CUMLSampleView---U M L Sample View, Specifies a CUMLSampleView object.
	DECLARE_DYNCREATE(CUMLSampleView)

private:
 
	// Start, This variable specifies a 32-bit signed integer on 32-bit platforms.  
	CPoint m_ptStart;

	CFoUMLEntityClass *CreateUmlEntity(const CFoUMLEntityClass::FOP_UML_ENTITY &entityType);

// Attributes
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Document, Returns the specified value.
	//		Returns a pointer to the object CUMLSampleDoc,or NULL if the call failed
	CUMLSampleDoc* GetDocument();

public:

	// Do model change.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Change Model, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pModel---Model, A pointer to the CFODataModel  or NULL if the call failed.
	virtual void	DoChangeModel(
		// Pointer of model.
		CFODataModel *pModel);

	// Init link shape.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Initial Link Shape, Call InitLinkShape after creating a new object.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void InitLinkShape();

	// Do generate the init additional items.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Generate Initial Items, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pShape---Shape, A pointer to the CFODrawShape  or NULL if the call failed.
	virtual void DoGenInitItems(CFODrawShape *pShape);
	
	// Do something when click on the items.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do When Click Additional, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,
	virtual void DoWhenClickAddi();

// Operations
public:

	// End print preview mode.
	
	//-----------------------------------------------------------------------
	// Summary:
	// On End Print Preview, Called when a print job ends; override to deallocate GDI resources.
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.  
	//		pInfo---Information, A pointer to the CPrintInfo or NULL if the call failed.  
	//		pt---Specifies a POINT pt object.  
	//		pView---View, A pointer to the CPreviewView or NULL if the call failed.
	void OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo,POINT pt, CPreviewView* pView);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUMLSampleView)
	public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Draw, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Before Create Window, Called before the creation of the Windows window attached to this CWnd object.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		cs---Specifies a CREATESTRUCT& cs object.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Initial Update, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void OnInitialUpdate(); // called first time after construct
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Prepare Printing, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		pInfo---Information, A pointer to the CPrintInfo or NULL if the call failed.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Begin Printing, Called when a print job begins; override to allocate graphics device interface (GDI) resources.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.  
	//		pInfo---Information, A pointer to the CPrintInfo or NULL if the call failed.
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On End Printing, Called when a print job ends; override to deallocate GDI resources.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.  
	//		pInfo---Information, A pointer to the CPrintInfo or NULL if the call failed.
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//E-XD++ Library add lines.
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Print, Called to print or preview a page of the document.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.  
	//		pInfo---Information, A pointer to the CPrintInfo or NULL if the call failed.
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// C U M L Sample View, Destructor of class CUMLSampleView
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CUMLSampleView();
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

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUMLSampleView)
	
	//-----------------------------------------------------------------------
	// Summary:
	// On File Print Preview, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnFilePrintPreview();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Add Uml Class, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnAddUmlClass();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Add Uml Template, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnAddUmlTemplate();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Add Uml Interface, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnAddUmlInterface();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Add Uml Label, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnAddUmlLabel();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Add Uml Note, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnAddUmlNote();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Add Uml Package, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnAddUmlPackage();
	
	//-----------------------------------------------------------------------
	// Summary:
	// On L Button Double click Clk, Called when the user double-clicks the left mouse button.
	// Parameters:
	//		nFlags---Flags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		point---Specifies A CPoint type value.
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Add Uml Open, This member function is called by the framework to allow your application to handle a Windows message.

	afx_msg void OnAddUmlOpen();
	//}}AFX_MSG
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ M E S S A G E_ M A P, None Description.
	//		Returns A  value.
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in UMLSampleView.cpp
inline CUMLSampleDoc* CUMLSampleView::GetDocument()
   { return (CUMLSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UMLSAMPLEVIEW_H__4A70BD8D_4040_40B3_AAE1_AF397770489F__INCLUDED_)
