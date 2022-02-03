
#include "stdafx.h"
#include "ClassDisplayPropertyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClassDisplayPropertyDialog dialog

CClassDisplayPropertyDialog::CClassDisplayPropertyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CClassDisplayPropertyDialog::IDD, pParent) 
{
	//{{AFX_DATA_INIT(CClassDisplayPropertyDialog)
	m_noattributenames = FALSE;
	m_noattributes = FALSE;
	m_nomarkers = FALSE;
	m_nooperations = FALSE;
	m_onlypublic = FALSE;
	//}}AFX_DATA_INIT
}


void CClassDisplayPropertyDialog::DoDataExchange(CDataExchange* pDX) 
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClassDisplayPropertyDialog)
	DDX_Check(pDX, IDC_CHECK_NO_ATTRIBUTE_NAMES, m_noattributenames);
	DDX_Check(pDX, IDC_CHECK_NO_ATTRIBUTES, m_noattributes);
	DDX_Check(pDX, IDC_CHECK_NO_MARKERS, m_nomarkers);
	DDX_Check(pDX, IDC_CHECK_NO_OPERATIONS, m_nooperations);
	DDX_Check(pDX, IDC_CHECK_ONLY_PUBLIC, m_onlypublic);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClassDisplayPropertyDialog, CDialog)
	//{{AFX_MSG_MAP(CClassDisplayPropertyDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

