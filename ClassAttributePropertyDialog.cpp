
#include "stdafx.h"
#include "ClassAttributePropertyDialog.h"
#include "PropertyListEditorDialog.h"
#include "UMLEntity.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClassAttributePropertyDialog dialog

CClassAttributePropertyDialog::CClassAttributePropertyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CClassAttributePropertyDialog::IDD, pParent) 
{
	//{{AFX_DATA_INIT(CClassAttributePropertyDialog)
	m_name = _T("");
	m_type = _T("");
	m_multiplicity = _T("");
	m_defaultvalue = _T("");
	m_propertylist = _T("");
	m_access = 0;
	m_static = FALSE;
	//}}AFX_DATA_INIT

	m_attribute = NULL;

}


void CClassAttributePropertyDialog::DoDataExchange(CDataExchange* pDX) 
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClassAttributePropertyDialog)
	DDX_Control(pDX, IDC_EDIT_TYPE, m_typeCtrl);
	DDX_Control(pDX, IDC_EDIT_NAME, m_nameCtrl);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_TYPE, m_type);
	DDX_Radio(pDX, IDC_RADIO_ACCESS, m_access);
	DDX_Check(pDX, IDC_CHECK_STATIC, m_static);
	DDX_Text(pDX, IDC_EDIT_MULTIPLICITY, m_multiplicity);
	DDX_Text(pDX, IDC_EDIT_INITIAL_VALUE, m_defaultvalue);
	DDX_Text(pDX, IDC_EDIT_PROPERTY_LIST, m_propertylist);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClassAttributePropertyDialog, CDialog)
	//{{AFX_MSG_MAP(CClassAttributePropertyDialog)
	ON_BN_CLICKED(IDC_BUTTON_PROPERTY_LIST, OnButtonPropertyList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClassAttributePropertyDialog message handlers

void CClassAttributePropertyDialog::OnOK()  
{

	UpdateData();

	if( m_name.IsEmpty() )
	{
		AfxMessageBox( IDS_UML_ATTRIBUTE_MUST_HAVE_A_NAME );
		m_nameCtrl.SetFocus();
		return;
	}

	if( m_type.IsEmpty() )
	{
		AfxMessageBox( IDS_UML_ATTRIBUTE_MUST_HAVE_A_TYPE );
		m_typeCtrl.SetFocus();
		return;
	}

	m_attribute->name = m_name;
	m_attribute->type = m_type;

	m_attribute->maintype = ENTITY_TYPE_NONE;
	if( m_static )
		m_attribute->maintype |= ENTITY_TYPE_STATIC;

	if( m_access == 0 )
		m_attribute->access = ACCESS_TYPE_PRIVATE;
	if( m_access == 1 )
		m_attribute->access = ACCESS_TYPE_PROTECTED;
	if( m_access == 2 )
		m_attribute->access = ACCESS_TYPE_PUBLIC;

	m_multiplicity.TrimLeft();
	m_multiplicity.TrimRight();

	m_attribute->multiplicity = m_multiplicity;

	m_defaultvalue.Remove( _TCHAR( '=' ) );
	m_defaultvalue.TrimLeft();
	m_defaultvalue.TrimRight();

	m_attribute->defaultvalue = m_defaultvalue;
	m_attribute->properties.Copy( m_properties );

	CDialog::OnOK();

}

BOOL CClassAttributePropertyDialog::OnInitDialog()  
{

	if( m_attribute )
	{

		m_name = m_attribute->name;
		m_type = m_attribute->type;

		if( m_attribute->maintype & ENTITY_TYPE_STATIC )
			m_static = TRUE;

		if( m_attribute->access == ACCESS_TYPE_PRIVATE )
			m_access = 0;
		if( m_attribute->access == ACCESS_TYPE_PROTECTED )
			m_access = 1;
		if( m_attribute->access == ACCESS_TYPE_PUBLIC )
			m_access = 2;

		m_multiplicity = m_attribute->multiplicity;
		m_defaultvalue = m_attribute->defaultvalue;
		m_properties.Copy( m_attribute->properties );

		m_propertylist = m_properties.GetString( STRING_FORMAT_UML );

	}
	else
		m_attribute = new CAttribute;

	CDialog::OnInitDialog();
	
	return TRUE;

}

void CClassAttributePropertyDialog::OnButtonPropertyList()  
{

	UpdateData();
	CPropertyListEditorDialog	dlg;

	dlg.SetProperties( m_properties );
	if( dlg.DoModal() == IDOK )
	{
		m_properties.Copy( *( dlg.GetProperties() ) );
		m_propertylist = m_properties.GetString( STRING_FORMAT_UML );
		UpdateData( FALSE );
	}
	
}

void CClassAttributePropertyDialog::SetAttribute( CAttribute* attribute )  
{ 
	
	m_attribute = attribute; 
}

CAttribute* CClassAttributePropertyDialog::GetAttribute() const  
{ 
	
	return m_attribute; 

}
