// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "UMLSample.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CFOPMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CFOPMDIChildWnd)
	//{{AFX_MSG_MAP(CChildFrame)
	// NOTE - the ClassWizard will add and remove mapping macros here.
	//    DO NOT EDIT what you see in these blocks of generated code !
	//E-XD++ Library add lines.
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
	
}

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREAFOAPPWIZARDRUCT cs

	if( !CFOPMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;
	//E-XD++ Library add lines.
	cs.style = WS_CHILD | WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU
		| FWS_ADDTOTITLE | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CFOPMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CFOPMDIChildWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers
//E-XD++ add lines.

int CChildFrame::OnCreate(LPCREATESTRUCT LPCREATESTRUCT) 
{
	if (CFOPMDIChildWnd::OnCreate(LPCREATESTRUCT) == -1)
		return -1;

	// TODO: Add your specialized creation code here
	
	return 0;
}

