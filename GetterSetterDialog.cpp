
#include "stdafx.h"
#include "GetterSetterDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGetterSetterDialog dialog

CGetterSetterDialog::CGetterSetterDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CGetterSetterDialog::IDD, pParent) 
{

	//{{AFX_DATA_INIT(CGetterSetterDialog)
	m_getter = _T("");
	m_setter = _T("");
	//}}AFX_DATA_INIT

	m_noset = FALSE;
	m_noget = FALSE;

}


void CGetterSetterDialog::DoDataExchange(CDataExchange* pDX) 
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGetterSetterDialog)
	DDX_Control(pDX, IDC_EDIT_SETTER, m_setterCtrl);
	DDX_Control(pDX, IDC_EDIT_GETTER, m_getterCtrl);
	DDX_Text(pDX, IDC_EDIT_GETTER, m_getter);
	DDX_Text(pDX, IDC_EDIT_SETTER, m_setter);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGetterSetterDialog, CDialog)
	//{{AFX_MSG_MAP(CGetterSetterDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetterSetterDialog message handlers

BOOL CGetterSetterDialog::OnInitDialog()  
{

	CDialog::OnInitDialog();
	
	if( m_noset )
		m_setterCtrl.SetReadOnly( TRUE );
	
	if( m_noget )
		m_getterCtrl.SetReadOnly( TRUE );

	return TRUE;  

}

void CGetterSetterDialog::OnOK()  
{

	if( !m_noset && m_setter.IsEmpty() )
	{
		AfxMessageBox( IDS_UML_SETTER_MUST_HAVE_A_NAME );
		m_setterCtrl.SetFocus();
	}
	
	if( !m_noget && m_getter.IsEmpty() )
	{
		AfxMessageBox( IDS_UML_GETTER_MUST_HAVE_A_NAME );
		m_getterCtrl.SetFocus();
	}
	
	CDialog::OnOK();

}
