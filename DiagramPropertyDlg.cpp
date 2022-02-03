
#include "stdafx.h"
#include "DiagramPropertyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDiagramPropertyDlg
//

CDiagramPropertyDlg::CDiagramPropertyDlg( UINT res, CWnd* parent ) : CDialog( res, parent ) 
{

	m_entity = NULL;
	m_redrawWnd = NULL;

}

void CDiagramPropertyDlg::SetEntity( CDiagramEntity* entity ) 
{

	m_entity = entity;

}

CDiagramEntity* CDiagramPropertyDlg::GetEntity() const 
{

	return m_entity;

}

BOOL CDiagramPropertyDlg::Create( UINT nIDTemplate, CWnd* pParentWnd ) 
{

	BOOL result;

	result = CDialog::Create( nIDTemplate, pParentWnd );
	SetRedrawWnd( pParentWnd );

	return result;

}

CWnd* CDiagramPropertyDlg::GetRedrawWnd()  
{ 

	return m_redrawWnd; 

}

void CDiagramPropertyDlg::SetRedrawWnd( CWnd* redrawWnd )  
{ 

	m_redrawWnd = redrawWnd; 

}

void CDiagramPropertyDlg::Redraw()  
{ 

	CWnd* wnd = GetRedrawWnd();
	if( wnd )
		wnd->RedrawWindow();

}
