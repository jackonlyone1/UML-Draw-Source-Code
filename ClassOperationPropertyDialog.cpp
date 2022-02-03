

#include "stdafx.h"
#include "ClassOperationPropertyDialog.h"
#include "AddParameterDialog.h"
#include "PropertyListEditorDialog.h"
#include "UMLEntity.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClassOperationPropertyDialog dialog

CClassOperationPropertyDialog::CClassOperationPropertyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CClassOperationPropertyDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClassOperationPropertyDialog)
	m_abstract = FALSE;
	m_static = FALSE;
	m_const = FALSE;
	m_name = _T("");
	m_type = _T("");
	m_propertylist = _T("");
	m_access = 0;
	//}}AFX_DATA_INIT

	m_operation = NULL;

}


void CClassOperationPropertyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClassOperationPropertyDialog)
	DDX_Control(pDX, IDC_EDIT_TYPE, m_typeCtrl);
	DDX_Control(pDX, IDC_EDIT_NAME, m_nameCtrl);
	DDX_Control(pDX, IDC_LIST_PARAMETERS, m_parameter);
	DDX_Check(pDX, IDC_CHECK_ABSTRACT, m_abstract);
	DDX_Check(pDX, IDC_CHECK_STATIC, m_static);
	DDX_Check(pDX, IDC_CHECK_CONST, m_const);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_TYPE, m_type);
	DDX_Text(pDX, IDC_EDIT_PROPERTY_LIST, m_propertylist);
	DDX_Radio(pDX, IDC_RADIO_ACCESS, m_access);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClassOperationPropertyDialog, CDialog)
	//{{AFX_MSG_MAP(CClassOperationPropertyDialog)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_PROPERTY_LIST, OnButtonPropertyList)
	ON_BN_CLICKED(IDC_CHECK_CONST, OnCheckConst)
	//}}AFX_MSG_MAP
	ON_REGISTERED_MESSAGE(rwm_EXLISTBOX_DBLCLICK, OnListboxDblClick)
	ON_REGISTERED_MESSAGE(rwm_EXLISTBOX_DELETE, OnListboxDelete)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClassOperationPropertyDialog message handlers

void CClassOperationPropertyDialog::OnButtonAdd() 
{

	CAddParameterDialog	dlg;
	if( dlg.DoModal() == IDOK )
	{

		CParameter* param = dlg.GetParameter();;
		param->reference = dlg.m_reference;

		CString out = param->GetString( STRING_FORMAT_UML );
		int index = m_parameter.AddString( out );
		m_parameter.SetItemData( index, reinterpret_cast< DWORD >( param ) );
		m_parameters.Add( param );

	}
	
}

void CClassOperationPropertyDialog::OnOK() 
{

	UpdateData();

	if( m_name.IsEmpty() )
	{
		AfxMessageBox( IDS_UML_OPERATION_MUST_HAVE_A_NAME );
		m_nameCtrl.SetFocus();
		return;
	}

	m_operation->name = m_name;
	m_operation->type = m_type;

	m_operation->maintype = ENTITY_TYPE_NONE;
	if( m_static )
		m_operation->maintype |= ENTITY_TYPE_STATIC;
	if( m_abstract )
		m_operation->maintype |= ENTITY_TYPE_ABSTRACT;

	if( m_access == 0 )
		m_operation->access = ACCESS_TYPE_PRIVATE;
	if( m_access == 1 )
		m_operation->access = ACCESS_TYPE_PROTECTED;
	if( m_access == 2 )
		m_operation->access = ACCESS_TYPE_PUBLIC;

	m_operation->properties.Copy( m_properties );
	m_operation->parameters.Copy( m_parameters );

	if( m_const )
		m_operation->properties.Add( _T( "query" ) );
	else
		m_operation->properties.RemoveProperty( _T( "query" ) );

	CDialog::OnOK();

}

BOOL CClassOperationPropertyDialog::OnInitDialog() 
{

	if( m_operation )
	{

		m_name = m_operation->name;
		m_type = m_operation->type;

		if( m_operation->maintype & ENTITY_TYPE_STATIC )
			m_static = TRUE;
		if( m_operation->maintype & ENTITY_TYPE_ABSTRACT )
			m_abstract = TRUE;

		if( m_operation->access == ACCESS_TYPE_PRIVATE )
			m_access = 0;
		if( m_operation->access == ACCESS_TYPE_PROTECTED )
			m_access = 1;
		if( m_operation->access == ACCESS_TYPE_PUBLIC )
			m_access = 2;

		m_const = FALSE;
		if( m_operation->properties.GetPropertyValue( _T( "query" ) ) == _T( "true" ) )
			m_const = TRUE;

		m_properties.Copy( m_operation->properties );
		m_propertylist = m_properties.GetString( STRING_FORMAT_UML );

	}
	else
		m_operation = new COperation;

	CDialog::OnInitDialog();

	m_parameters.Copy( m_operation->parameters );
	FillParameterList();

	return TRUE;

}

void CClassOperationPropertyDialog::OnButtonPropertyList() 
{

	UpdateData();
	CPropertyListEditorDialog	dlg;

	dlg.SetProperties( m_properties );
	if( dlg.DoModal() == IDOK )
	{
		m_properties.Copy( *( dlg.GetProperties() ) );
		m_propertylist = m_properties.GetString( STRING_FORMAT_UML );
		if( m_properties.GetPropertyValue( _T( "query" ) ) == _T( "true" ) )
			m_const = TRUE;
		else
			m_const = FALSE;

		UpdateData( FALSE );
	}

}

void CClassOperationPropertyDialog::OnCheckConst() 
{

	UpdateData();
	if( m_const )
		m_properties.Add( _T( "query" ) );
	else
		m_properties.RemoveProperty( _T( "query" ) );

	m_propertylist = m_properties.GetString( STRING_FORMAT_UML );

	UpdateData( FALSE );

}

LRESULT CClassOperationPropertyDialog::OnListboxDblClick( WPARAM, LPARAM )
{

	int index = m_parameter.GetCurSel();
	if( index != LB_ERR )
	{

		CParameter* parameter = reinterpret_cast< CParameter* >( m_parameter.GetItemData( index ) );
		CAddParameterDialog	dlg;
		dlg.SetParameter( parameter );
		dlg.DoModal();

		FillParameterList();

	}

	return 0;

}

LRESULT CClassOperationPropertyDialog::OnListboxDelete( WPARAM, LPARAM )
{

	int index = m_parameter.GetCurSel();
	if( index != LB_ERR )
	{

		CParameter* parameter = reinterpret_cast< CParameter* >( m_parameter.GetItemData( index ) );
		m_parameters.Remove( parameter );
		m_parameter.DeleteString( index );
		m_parameter.SetCurSel( index );
		m_parameter.SetFocus();

	}

	return 0;

}

void CClassOperationPropertyDialog::FillParameterList()
{

	m_parameter.ResetContent();

	int max = m_parameters.GetSize();
	int index;
	for( int t = 0 ; t < max ; t++ )
	{

		CParameter* parameter = m_parameters.GetAt( t );
		CString out = parameter->GetString( STRING_FORMAT_UML );
		index = m_parameter.AddString( out );
		m_parameter.SetItemData( index, reinterpret_cast< DWORD >( parameter ) );

	}

}

void CClassOperationPropertyDialog::SetOperation( COperation* operation )
{

	m_operation = operation;

}

COperation* CClassOperationPropertyDialog::GetOperation() const
{

	return m_operation;

}

