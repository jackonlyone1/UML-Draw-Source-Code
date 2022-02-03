// MyToolBoxBar.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MyToolBoxBar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyToolBoxBar

CMyToolBoxBar::CMyToolBoxBar()
{
}

CMyToolBoxBar::~CMyToolBoxBar()
{
	POSITION pos = m_Shapes.GetHeadPosition();
	while(pos != NULL)
	{
		delete m_Shapes.GetNext(pos);
	}

	m_Shapes.RemoveAll();
}


BEGIN_MESSAGE_MAP(CMyToolBoxBar, CFOPControlBar)
	//{{AFX_MSG_MAP(CMyToolBoxBar)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMyToolBoxBar message handlers

int CMyToolBoxBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFOPControlBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	LoadFromFile();	

	m_wndTool.Create(WS_CHILD|WS_VISIBLE|WS_TABSTOP|WS_EX_CLIENTEDGE,CRect(0,0,100,100),this,1232);
	if(m_Shapes.GetCount() <= 0)
	{
		m_wndTool.AddPage(_T("New"));
		m_wndTool.ActivatePage(0);
	}
	else
	{
		POSITION pos = m_Shapes.GetHeadPosition();
		while(pos != NULL)
		{
			CFOListItemObj *pObj = (CFOListItemObj *)m_Shapes.GetNext(pos);
			CString strPathX = AfxGetApp()->m_pszHelpFilePath;
			strPathX = strPathX.Left(strPathX.ReverseFind('\\'));
			CString strOtherFile;
			strOtherFile = strPathX+_T("\\Shapes\\");
			strOtherFile += pObj->strFileName;
			CString strTemp = pObj->strFileName;
			strTemp = strTemp.Left(strTemp.GetLength() -4);
			m_wndTool.AddPage(strTemp);
			m_wndTool.GetToolBoxWnd()->LoadResFile(strOtherFile);

		}
		m_wndTool.ActivatePage(0);
	}
	return 0;
}

void CMyToolBoxBar::OnSize(UINT nType, int cx, int cy) 
{
	CFOPControlBar::OnSize(nType, cx, cy);
	
	if( m_wndTool.GetSafeHwnd() != NULL )
	{
		CRect r;
		GetFullRect(r);
		m_wndTool.SetWindowPos( NULL, r.left, r.top, r.Width(), r.Height(), SWP_NOZORDER|SWP_NOACTIVATE );
	}
}

BOOL CMyToolBoxBar::OnEraseBkgnd( CDC* pDC )
{
	CFOPControlBar::OnEraseBkgnd(pDC);
	return TRUE;
}

CFOListItemObj *CMyToolBoxBar::FindObjByID(int nIndex)
{
	POSITION pos = m_Shapes.GetHeadPosition();
	while(pos != NULL)
	{
		CFOListItemObj *pObj = (CFOListItemObj *)m_Shapes.GetNext(pos);
		if(pObj->nID == nIndex)
		{
			return pObj;
		}
	}
	return NULL;
}

void CMyToolBoxBar::LoadFromFile()
{
	CString strPathX = AfxGetApp()->m_pszHelpFilePath;
	strPathX = strPathX.Left(strPathX.ReverseFind('\\'));
	CString strOtherFile;
	strOtherFile = strPathX+_T("\\Shapes\\uml.dat");
	CStdioFile m_File;
	if(m_File.Open(strOtherFile,CFile::modeRead | CFile::typeText))
	{
		CString strTemp;
		int nNumber = 100;
		while (m_File.ReadString(strTemp))
		{
			
			strTemp.TrimLeft();
			strTemp.TrimRight();
			if(!strTemp.IsEmpty())
			{
				CString strTitle;
				CString strFile;
				strTitle = strTemp.Left(strTemp.ReverseFind('#'));
				strFile = strTemp.Right(strTemp.GetLength() - strTitle.GetLength() -1);
				if((!strTitle.IsEmpty()) && (!strFile.IsEmpty()))
				{
					CFOListItemObj *pObj = new CFOListItemObj;
					pObj->strTitle = strTitle;
					pObj->strFileName = strFile;
					pObj->nID = nNumber;
					m_Shapes.AddTail(pObj);
					nNumber ++;
				}
			}	
		}
		m_File.Close();
	}
}

