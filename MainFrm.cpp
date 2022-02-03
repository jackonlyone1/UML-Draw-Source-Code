// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "UMLSample.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFOPMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFOPMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_COMMAND(ID_VIEW_DRAWBAR, OnViewDrawbar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DRAWBAR, OnUpdateViewDrawbar)
	ON_COMMAND(ID_VIEW_FORMATBAR, OnViewFormatbar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_FORMATBAR, OnUpdateViewFormatbar)
	ON_COMMAND(ID_VIEW_TOOLBOX, OnViewToolbox)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLBOX, OnUpdateViewToolbox)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_FULLSCREEN, OnViewFullscreen)
	ON_UPDATE_COMMAND_UI(ID_VIEW_FULLSCREEN, OnUpdateViewFullscreen)
	ON_WM_DROPFILES()
	//}}AFX_MSG_MAP
	ON_REGISTERED_MESSAGE(FOP_WM_VIEWVALID, OnViewValidMsg)
	ON_REGISTERED_MESSAGE(FOP_WM_VIEWINVALID, OnViewInValidMsg)
	ON_REGISTERED_MESSAGE(FOP_WM_SHAPECHANGED,   OnShapeChangedMsg)
	ON_REGISTERED_MESSAGE(FOP_WM_VIEW_UPDATE,   OnCanvasChangedMsg)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_FO_INDEX_MOUSEPOS,
	ID_FO_INDEX_WIDTH,
	ID_FO_INDEX_HEIGHT,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	ShowMenuImage();
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT LPCREATESTRUCT)
{
	if (CFOPMDIFrameWnd::OnCreate(LPCREATESTRUCT) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// Create draw toolbar.
	if (!m_wndDrawToolBar.CreateEx(this) ||
		!m_wndDrawToolBar.LoadToolBar(IDR_FO_256_DRAWBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	// Create format toolbar.
	if (!m_wndFormatToolBar.CreateEx(this) ||
		!m_wndFormatToolBar.LoadToolBar(IDR_FO_256_NEWFORMAT))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	// Create align toolbar.
	if (!m_wndAlignToolBar.CreateEx(this) ||
		!m_wndAlignToolBar.LoadToolBar(IDR_FO_256_FORMAT_ALIGN))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndLinkToolBar.CreateEx(this) ||
		!m_wndLinkToolBar.LoadToolBar(IDR_FO_LINK_TOOLBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndOptToolBar.CreateEx(this) ||
		!m_wndOptToolBar.LoadToolBar(IDR_FO_SHAPESBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndPanBar.Create(this, _T("Pan Window"), WS_CHILD|CBRS_LEFT|CBRS_TOOLTIPS|CBRS_SIZE_DYNAMIC|CBRS_FLOAT_MULTI, 
		CBRS_FOP_DEFAULT|CBRS_FOP_BDSP, 20002))
	{
		TRACE(_T("Failed to create List Bar\n"));
		return -1;
	}

	// Create toolbox
	if (!m_FileBar.Create(this, _T("ToolBox Bar"), WS_CHILD|WS_VISIBLE|CBRS_LEFT|CBRS_TOOLTIPS|CBRS_SIZE_DYNAMIC, 
		CBRS_FOP_DEFAULT|CBRS_FOP_BDSP, 1212))
	{
		TRACE(_T("Failed to create List Bar\n"));
		return -1;
	}
	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable

	SetMenuImageRes(IDR_MAINFRAME);
	SetMenuImageRes(IDR_FO_256_FORMAT_ALIGN);
	SetMenuImageRes(IDR_FO_256_NEWFORMAT);
	SetMenuImageRes(IDR_FO_SHAPESBAR);
	SetMenuImageRes(IDR_FO_256_DRAWBAR);
	SetMenuImageRes(IDR_FO_256_EDITBAR);

	// looks a little bit better...
	m_wndToolBar.SetWindowText(_T("Standard"));
	m_wndAlignToolBar.SetWindowText(_T("Align"));
	m_wndFormatToolBar.SetWindowText(_T("Format"));
	m_wndDrawToolBar.SetWindowText(_T("Draw"));
	m_wndLinkToolBar.SetWindowText(_T("Link"));
	m_wndOptToolBar.SetWindowText(_T("Operations"));

	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndDrawToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndFormatToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndAlignToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndLinkToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndOptToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_FileBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndPanBar.EnableDocking(CBRS_ALIGN_ANY);

	EnableDocking(CBRS_ALIGN_ANY);

	DockControlBar(&m_wndToolBar);
	DockControlBar(&m_wndDrawToolBar,AFX_IDW_DOCKBAR_RIGHT);
	DockControlBar(&m_wndAlignToolBar,AFX_IDW_DOCKBAR_BOTTOM);
	DockControlBar(&m_wndLinkToolBar,AFX_IDW_DOCKBAR_TOP);
	DockControlBarLeftOf(&m_wndFormatToolBar,&m_wndToolBar);
	DockControlBarLeftOf(&m_wndOptToolBar,&m_wndLinkToolBar);
	DockControlBarEx(&m_FileBar, AFX_IDW_DOCKBAR_LEFT, 50, 200);
	DockControlBarBottomOf(&m_wndPanBar, &m_FileBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	//E-XD++ Library add lines.
	int DesktopWidth  = GetSystemMetrics(SM_CXSCREEN);
	int DesktopHeight = GetSystemMetrics(SM_CYSCREEN);

	// Just Make It Small So We Will Not Feel a "Blink"
	CRect MainWindow_Rect(0,0, DesktopWidth, DesktopHeight); // First Opening Screen

	cs.x = (DesktopWidth - MainWindow_Rect.right)/2;
	cs.y = (DesktopHeight - MainWindow_Rect.bottom)/2;

    cs.cx = MainWindow_Rect.right;
	cs.cy = MainWindow_Rect.bottom;

	if( !CFOPMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREAFOAPPWIZARDRUCT cs
	//E-XD++ Library add lines.
	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		| WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFOPMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFOPMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

//E-XD++ Library add lines.
void CMainFrame::OnViewDrawbar() 
{
	// TODO: Add your command handler code here
	BOOL bVisible = m_wndDrawToolBar.IsWindowVisible();
	if(bVisible)
	{
		ShowControlBar(&m_wndDrawToolBar,FALSE,FALSE);
	}
	else
	{
		ShowControlBar(&m_wndDrawToolBar,TRUE,FALSE);
	}
}

void CMainFrame::OnUpdateViewDrawbar(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_wndDrawToolBar.IsWindowVisible());
}

//E-XD++ Library add lines.
void CMainFrame::OnViewFormatbar() 
{
	// TODO: Add your command handler code here
	BOOL bVisible = m_wndFormatToolBar.IsWindowVisible();
	if(bVisible)
	{
		ShowControlBar(&m_wndFormatToolBar,FALSE,FALSE);
	}
	else
	{
		ShowControlBar(&m_wndFormatToolBar,TRUE,FALSE);
	}
}

void CMainFrame::OnUpdateViewFormatbar(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_wndFormatToolBar.IsWindowVisible());
}


//E-XD++ Library add lines.
void CMainFrame::OnViewToolbox() 
{
	// TODO: Add your command handler code here
	BOOL bVisible = m_FileBar.IsWindowVisible();
	if(bVisible)
	{
		ShowControlBar(&m_FileBar,FALSE,FALSE);
	}
	else
	{
		ShowControlBar(&m_FileBar,TRUE,FALSE);
	}
}

void CMainFrame::OnUpdateViewToolbox(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_FileBar.IsWindowVisible());
}
	
LRESULT CMainFrame::OnViewValidMsg (WPARAM wparam, LPARAM lp)
{
	lp;
	CFODrawView* pView = (CFODrawView*) wparam;
	
	m_wndPanBar.SetActiveView(pView);

	return 1;
}

LRESULT CMainFrame::OnViewInValidMsg (WPARAM wparam, LPARAM lp)
{
	CFODrawView* ActiveView = (CFODrawView*) wparam;
	CFODrawView* DeactiveView = (CFODrawView*) lp;

	// VERY important change, handling the case when switch to othe app.
	if(ActiveView == DeactiveView) 
		return 1;

	if (m_wndPanBar.GetActiveView()==DeactiveView)
	  m_wndPanBar.SetActiveView(NULL);

	return 1;
}

LRESULT CMainFrame::OnShapeChangedMsg(WPARAM wP,LPARAM /*lP*/)
{
	m_wndPanBar.UpdateWnd(FALSE);
	return TRUE;
}

LRESULT CMainFrame::OnCanvasChangedMsg(WPARAM wP,LPARAM lP)
{
	int nLong = (int)lP;
	if(nLong == 100)
	{
		m_wndPanBar.UpdateWnd(TRUE);
		m_wndPanBar.RedrawWindow();
	}
	else if(nLong == 200)
	{
		m_wndPanBar.UpdateWnd(FALSE);
		m_wndPanBar.UpdateZoomScale();
	}
	else
	{
		m_wndPanBar.UpdateWnd(FALSE);
	}
	return TRUE;
}
void CMainFrame::OnViewFullscreen() 
{
	// TODO: Add your command handler code here
	ShowFullScreen();
}

void CMainFrame::OnUpdateViewFullscreen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(IsFullScreen());
}

void CMainFrame::OnDropFiles(HDROP hDropInfo) 
{
	// TODO: Add your message handler code here and/or call default
	
	int            NumOfFiles = 0 ; 
	TCHAR lpszFile [MAX_PATH];
    CString FileType;
	NumOfFiles = DragQueryFile (hDropInfo, 0xffffffff, NULL, 0) ; 
    if (NumOfFiles > 0) 
	{
		for(int i = 0; i < NumOfFiles; i++)
		{
			if(DragQueryFile (hDropInfo, i, lpszFile, sizeof (lpszFile)))
			{
				FileType = lpszFile;
				FileType = FileType.Right(4);
				FileType.MakeUpper();
				if( FileType == _T(".UML")
					)
					((CUMLSampleApp *)AfxGetApp())->OpenDocumentFile(lpszFile);
				
			} 
		}
	}
	DragFinish (hDropInfo);
}
