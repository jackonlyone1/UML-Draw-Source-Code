

#include "stdafx.h"
#include "ExListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExListBox

CExListBox::CExListBox()
{

	m_draggedLine = -1;

}

CExListBox::~CExListBox()
{
}

BEGIN_MESSAGE_MAP(CExListBox, CListBox)
	//{{AFX_MSG_MAP(CExListBox)
	ON_CONTROL_REFLECT(LBN_DBLCLK, OnDblclk)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExListBox message handlers

void CExListBox::OnDblclk() 
{

	GetParent()->SendMessage( rwm_EXLISTBOX_DBLCLICK, GetDlgCtrlID() );

}

void CExListBox::OnLButtonDown(UINT nFlags, CPoint point) 
{

	int count = GetCount();
	if( count > 1 )
		SetCapture();

	CListBox::OnLButtonDown(nFlags, point);

	int index = GetCurSel();
	if( index != LB_ERR && count > 1 )
		m_draggedLine = index;
	else
		ReleaseCapture();

}

void CExListBox::OnLButtonUp(UINT nFlags, CPoint point) 
{

	if( m_draggedLine != -1 )
		ReleaseCapture();
	
	CListBox::OnLButtonUp(nFlags, point);

	// Move line under cursor
	if( m_draggedLine != -1 )
	{
		int index = GetCurSel();
		if( index != m_draggedLine )
		{
			CString draggedline;

			GetText( m_draggedLine, draggedline );
			DWORD data = GetItemData( m_draggedLine );
			DeleteString( m_draggedLine );
			index = InsertString( index, draggedline );
			SetItemData( index, data );
			SetCurSel( index );
		}

		m_draggedLine = -1;
	}

	GetParent()->SendMessage( rwm_EXLISTBOX_SELCHANGE, GetDlgCtrlID() );

}

void CExListBox::OnMouseMove(UINT nFlags, CPoint point) 
{

	CListBox::OnMouseMove(nFlags, point);

	if( m_draggedLine != -1 )
		::SetCursor( ::LoadCursor( NULL, IDC_SIZENS ) );

}


void CExListBox::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{

	if( nChar == VK_DELETE )
		GetParent()->SendMessage( rwm_EXLISTBOX_DELETE, GetDlgCtrlID() );
	else
		CListBox::OnKeyDown(nChar, nRepCnt, nFlags);

}


void CExListBox::PreSubclassWindow() 
{

	CListBox::PreSubclassWindow();

	CRect rect;
	GetClientRect( rect );
	int tabs = ( ( rect.Width() / 2 ) * 4) / LOWORD( GetDialogBaseUnits() );

	SetTabStops( tabs );

}

int CExListBox::AddString( LPCTSTR str )
{

	int result = LB_ERR;

	if( m_hWnd )
	{
		CClientDC	dc( this );
		CFont* font = GetFont();
		CFont* oldfont = dc.SelectObject( font);
		int width = dc.GetTextExtent( str ).cx + 16;
		if( width > GetHorizontalExtent() )
			SetHorizontalExtent( width );
		dc.SelectObject( oldfont );

		result = CListBox::AddString( str );

	}

	return result;

}


UINT rwm_EXLISTBOX_DBLCLICK = ::RegisterWindowMessage( _T( "{CF94DC6E-CE14-4d93-A06C-C67C7A5CBE0B}" ) );
UINT rwm_EXLISTBOX_DELETE = ::RegisterWindowMessage( _T( "{C6B4CD5B-0DB9-4133-BD67-4AA3440C9011}" ) );
UINT rwm_EXLISTBOX_SELCHANGE = ::RegisterWindowMessage( _T( "{CF94DC6E-CE14-4d93-A06C-C67C7A5CBE0C}" ) );

