
#include "stdafx.h"
#include "AddParameterDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddParameterDialog dialog

CAddParameterDialog::CAddParameterDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CAddParameterDialog::IDD, pParent) 
{
	//{{AFX_DATA_INIT(CAddParameterDialog)
	m_name = _T("");
	m_type = _T("");
	m_defaultvalue = _T("");
	m_in = FALSE;
	m_out = FALSE;
	m_reference = FALSE;
	//}}AFX_DATA_INIT

	m_parameter = NULL;

}


void CAddParameterDialog::DoDataExchange(CDataExchange* pDX) 
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddParameterDialog)
	DDX_Control(pDX, IDC_EDIT_TYPE, m_typeCtrl);
	DDX_Control(pDX, IDC_EDIT_NAME, m_nameCtrl);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_TYPE, m_type);
	DDX_Text(pDX, IDC_EDIT_INITIAL_VALUE, m_defaultvalue);
	DDX_Check(pDX, IDC_CHECK_IN, m_in);
	DDX_Check(pDX, IDC_CHECK_OUT, m_out);
	DDX_Check(pDX, IDC_CHECK_REFERENCE, m_reference);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAddParameterDialog, CDialog)
	//{{AFX_MSG_MAP(CAddParameterDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddParameterDialog message handlers

void CAddParameterDialog::OnOK()  
{

	UpdateData();

	if( m_name.IsEmpty() )
	{
		AfxMessageBox( IDS_UML_PARAMETER_MUST_HAVE_A_NAME );
		m_nameCtrl.SetFocus();
		return;
	}

	if( m_type.IsEmpty() )
	{
		AfxMessageBox( IDS_UML_PARAMETER_MUST_HAVE_A_TYPE );
		m_typeCtrl.SetFocus();
		return;
	}

	m_parameter->name = m_name;
	m_parameter->type = m_type;
	m_parameter->defaultvalue = m_defaultvalue;
	m_parameter->in = m_in;
	m_parameter->out = m_out;
	m_parameter->reference = m_reference;

	CDialog::OnOK();

}

BOOL CAddParameterDialog::OnInitDialog()  
{

	if( m_parameter )
	{
		m_name = m_parameter->name;
		m_type = m_parameter->type;
		m_defaultvalue = m_parameter->defaultvalue;
		m_in = m_parameter->in;
		m_out = m_parameter->out;
		m_reference = m_parameter->reference;

	}
	else
		m_parameter = new CParameter;

	CDialog::OnInitDialog();
	
	
	return TRUE; 
}

void CAddParameterDialog::SetParameter( CParameter* parameter ) 
{

	m_parameter = parameter;

}

CParameter* CAddParameterDialog::GetParameter() 
{

	return m_parameter;

}
