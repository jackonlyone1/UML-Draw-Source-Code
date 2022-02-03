

#include "stdafx.h"
#include "DiagramEntity.h"
#include "DiagramEntityContainer.h"
#include "Tokenizer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDiagramEntity

CDiagramEntity::CDiagramEntity()
{
	SetParent( NULL );
	SetPropertyDialog( NULL, 0 );
	Clear();
	SetType( _T( "basic" ) );

	SetGroup( 0 );
}

CDiagramEntity::~CDiagramEntity()
{
}

void CDiagramEntity::Clear()
{

	SetRect( 0.0, 0.0, 0.0, 0.0 );
	SetMarkerSize( CSize( 8, 8 ) );
	SetConstraints( CSize( 1, 1 ), CSize( -1, -1 ) );
	Select( FALSE );
	SetParent( NULL );
	SetName( _T( "" ) );

}

CDiagramEntity* CDiagramEntity::Clone()
{
	CDiagramEntity* obj = new CDiagramEntity;
	obj->Copy( this );
	return obj;
}

void CDiagramEntity::Copy( CDiagramEntity* obj )
{

	Clear();

	SetMarkerSize( obj->GetMarkerSize() );
	SetConstraints( obj->GetMinimumSize(), obj->GetMaximumSize() );

	Select( obj->IsSelected() );
	SetParent( obj->GetParent() );
	SetType( obj->GetType() );
	SetTitle( obj->GetTitle() );
	SetName( obj->GetName() );
	SetRect( obj->GetLeft(), obj->GetTop(), obj->GetRight(), obj->GetBottom() );

}

BOOL CDiagramEntity::FromString( const CString& str )
{

	BOOL result = FALSE;
	CString data( str );
	CString header = GetHeaderFromString( data );
	if( header == GetType() )
		if( GetDefaultFromString( data ) )
			result = TRUE;

	return result;

}

CString CDiagramEntity::GetHeaderFromString( CString& str )
{

	CTokenizer main( str, _T( ":" ) );
	CString header;
	CString data;
	if( main.GetSize() == 2 )
	{

		main.GetAt( 0, header );
		main.GetAt( 1, data );
		header.TrimLeft();
		header.TrimRight();
		data.TrimLeft();
		data.TrimRight();

		str = data;
	}

	return header;

}

BOOL CDiagramEntity::GetDefaultFromString( CString& str )
{
	BOOL result = FALSE;
	CString data( str );
	if( data[ data.GetLength() -1 ] == _TCHAR( ';' ) )
		data = data.Left( data.GetLength() - 1 ); // Strip the ';'

	CTokenizer tok( data ); 
	int size = tok.GetSize();
	if( size >= 7 )
	{
		double left;
		double top;
		double right;
		double bottom;
		CString title;
		CString name;
		int group;
		int count = 0;

		tok.GetAt( count++, left );
		tok.GetAt( count++, top );
		tok.GetAt( count++, right );
		tok.GetAt( count++, bottom );
		tok.GetAt( count++, title );
		tok.GetAt( count++, name );
		tok.GetAt( count++, group );

		SetRect( left, top, right, bottom );

		title.Replace( _T( "\\colon" ), _T( ":" ) );
		title.Replace( _T( "\\semicolon" ), _T( ";" ) );
		title.Replace( _T( "\\comma" ), _T( "," ) );
		title.Replace( _T( "\\newline" ), _T( "\r\n" ) );

		name.Replace( _T( "\\colon" ), _T( ":" ) );
		name.Replace( _T( "\\semicolon" ), _T( ";" ) );
		name.Replace( _T( "\\comma" ), _T( "," ) );
		name.Replace( _T( "\\newline" ), _T( "\r\n" ) );

		SetTitle( title );
		SetName( name );
		SetGroup( group );

		// Rebuild rest of string
		str = _T( "" );
		for( int t = count ; t < size ; t++ )
		{
			tok.GetAt( t, data );

			str += data;
			if( t < size - 1 )
				str += _T( "," );
		}

		result = TRUE;
	}

	return result;

}

BOOL CDiagramEntity::LoadFromString( CString& data )
{

	BOOL result = FALSE;
	CString header = GetHeaderFromString( data );
	if( header == GetType() )
		if( GetDefaultFromString( data ) )
			result = TRUE;

	return result;

}

CDiagramEntity* CDiagramEntity::CreateFromString( const CString& str )
{

	CDiagramEntity* obj = new CDiagramEntity;
	if(!obj->FromString( str ) )
	{
		delete obj;
		obj = NULL;
	}

	return obj;

}

CString CDiagramEntity::GetString() const
{

	CString str = GetDefaultGetString();

	str += _T( ";" );

	return str;

}

CString CDiagramEntity::GetDefaultGetString() const
{
	CString str;

	CString title = GetTitle();
	title.Replace( _T( ":" ), _T( "\\colon" ) );
	title.Replace( _T( ";" ), _T( "\\semicolon" ) );
	title.Replace( _T( "," ), _T( "\\comma" ) );
	title.Replace( _T( "\r\n" ), _T( "\\newline" ) );

	CString name = GetName();
	name.Replace( _T( ":" ), _T( "\\colon" ) );
	name.Replace( _T( ";" ), _T( "\\semicolon" ) );
	name.Replace( _T( "," ), _T( "\\comma" ) );
	name.Replace( _T( "\r\n" ), _T( "\\newline" ) );

	str.Format( _T( "%s:%f,%f,%f,%f,%s,%s,%i" ), GetType(), GetLeft(), GetTop(), GetRight(), GetBottom(), title, name, GetGroup() );

	return str;
}

CRect CDiagramEntity::GetRect() const
{

	CRect rect( static_cast< int >( GetLeft() ), 
				static_cast< int >( GetTop() ), 
				static_cast< int >( GetRight() ), 
				static_cast< int >( GetBottom() ) );
	return rect;

}

void CDiagramEntity::SetRect( CRect rect )
{

	rect.NormalizeRect();
	SetRect( static_cast< double >( rect.left ), 
				static_cast< double >( rect.top ), 
				static_cast< double >( rect.right ), 
				static_cast< double >( rect.bottom ) );

}

void CDiagramEntity::SetRect( double left, double top, double right, double bottom )
{

	SetLeft( left );
	SetTop( top );
	SetRight( right );
	SetBottom( bottom );

	if( GetMinimumSize().cx != -1 )
		if( GetRect().Width() < GetMinimumSize().cx )
			SetRight( GetLeft() + GetMinimumSize().cx );

	if( GetMinimumSize().cy != -1 )
		if( GetRect().Height() < GetMinimumSize().cy )
			SetBottom( GetTop() + GetMinimumSize().cy );

	if( GetMaximumSize().cx != -1 )
		if( GetRect().Width() > GetMaximumSize().cx )
			SetRight( GetLeft() + GetMaximumSize().cx );

	if( GetMaximumSize().cy != -1 )
		if( GetRect().Height() > GetMaximumSize().cy )
			SetBottom( GetTop() + GetMaximumSize().cy );

  if( GetPropertyDialog() )
		GetPropertyDialog()->SetValues();

}

void CDiagramEntity::MoveRect( double x, double y )
{

	SetRect( GetLeft() + x, GetTop() + y, GetRight() + x, GetBottom() + y );

}

void CDiagramEntity::Select( BOOL selected )
{

	m_selected = selected;

	if( selected && GetGroup() )
	{
		CDiagramEntityContainer* parent = GetParent();
		if( parent )
			parent->SendMessageToObjects( CMD_SELECT_GROUP, FALSE, this );
	}

}

BOOL CDiagramEntity::IsSelected() const
{

	return m_selected;

}

BOOL CDiagramEntity::BodyInRect( CRect rect ) const
{

	BOOL result = FALSE;
	CRect rectEntity = GetRect();
	CRect rectIntersect;

	rect.NormalizeRect();
	rectEntity.NormalizeRect();

	rectIntersect.IntersectRect( rect, rectEntity );
	if( !rectIntersect.IsRectEmpty() )
		result = TRUE;

	return result;

}

int CDiagramEntity::GetHitCode( CPoint point ) const
{

	CRect rect = GetRect();
	return GetHitCode( point, rect );

}

BOOL CDiagramEntity::DoMessage( UINT msg, CDiagramEntity* sender, CWnd* from )
{

	BOOL stop = FALSE;
	switch( msg )
	{
		case CMD_CUT:
			if( m_parent && IsSelected() )
			{
				stop = TRUE;
				m_parent->Cut( this );
			}
		break;

		case CMD_COPY:
			if( m_parent && IsSelected() )
			{
				stop = TRUE;
				m_parent->Copy( this );
			}
		break;

		case CMD_UP:
			if( m_parent && IsSelected() )
			{
				stop = TRUE;
				m_parent->Up( this );
			}
		break;

		case CMD_DOWN:
			if( m_parent && IsSelected() )
			{
				stop = TRUE;
				m_parent->Down( this );
			}
		break;

		case CMD_FRONT:
			if( m_parent && IsSelected() )
			{
				stop = TRUE;
				m_parent->Front( this );
			}
		break;

		case CMD_BOTTOM:
			if( m_parent && IsSelected() )
			{
				stop = TRUE;
				m_parent->Bottom( this );
			}
		break;

		case CMD_DUPLICATE:
			if( m_parent && IsSelected() )
			{
				stop = TRUE;
				m_parent->Duplicate( this );
				Select( FALSE );
			}
		break;

		case CMD_PROPERTIES:
			if( IsSelected() )
			{
				ShowProperties( from );
				stop = TRUE;
			}
		break;

		case CMD_SELECT_GROUP:
			if( sender != this )
				if( sender->GetGroup() == GetGroup() )
					m_selected = TRUE;
		break;

	}

	return stop;

}

void CDiagramEntity::ShowPopup( CPoint point, CWnd* parent )
{

	CMenu menu;
	if( menu.CreatePopupMenu() )
	{

		menu.AppendMenu( MF_STRING, CMD_CUT, _T( "Cut" ) );
		menu.AppendMenu( MF_STRING, CMD_COPY, _T( "Copy" ) );
		menu.AppendMenu( MF_STRING, CMD_DUPLICATE, _T( "Duplicate" ) );
		menu.AppendMenu( MF_SEPARATOR );
		menu.AppendMenu( MF_STRING, CMD_UP, _T( "Up" ) );
		menu.AppendMenu( MF_STRING, CMD_DOWN, _T( "Down" ) );
		menu.AppendMenu( MF_STRING, CMD_FRONT, _T( "To front" ) );
		menu.AppendMenu( MF_STRING, CMD_BOTTOM, _T( "To back" ) );
		menu.AppendMenu( MF_SEPARATOR );
		menu.AppendMenu( MF_STRING, CMD_PROPERTIES, _T( "Properties" ) );
		menu.TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, parent );

	}

}

void CDiagramEntity::ShowProperties( CWnd* parent, BOOL show )
{

	if( m_propertydlg )
	{
		if( show )
		{
			if( !m_propertydlg->m_hWnd )
				m_propertydlg->Create( ( UINT ) m_propertydlgresid, parent );

			m_propertydlg->ShowWindow( SW_SHOW );
			m_propertydlg->SetValues();
			m_propertydlg->SetFocus();
		}
		else
			if( m_propertydlg->m_hWnd )
				m_propertydlg->ShowWindow( SW_HIDE );
	}

}

void CDiagramEntity::DrawObject( CDC* dc, double zoom )
{
	CRect rect( round( GetLeft() * zoom ), 
				round( GetTop() * zoom ), 
				round( GetRight() * zoom ), 
				round( GetBottom() * zoom ) );

	Draw( dc, rect );

	if( IsSelected() )
		DrawSelectionMarkers( dc, rect );
}

void CDiagramEntity::Draw( CDC* dc, CRect rect )
{

	dc->SelectStockObject( BLACK_PEN );
	dc->SelectStockObject( WHITE_BRUSH );

	dc->Rectangle( rect );


}

HCURSOR CDiagramEntity::GetCursor( int hit ) const
{
	HCURSOR cursor = NULL;
	switch( hit )
	{
		case DEHT_BODY:
			cursor = LoadCursor( NULL, IDC_SIZEALL );
		break;
		case DEHT_TOPLEFT:
			cursor = LoadCursor( NULL, IDC_SIZENWSE );
		break;
		case DEHT_TOPMIDDLE:
			cursor = LoadCursor( NULL, IDC_SIZENS );
		break;
		case DEHT_TOPRIGHT:
			cursor = LoadCursor( NULL, IDC_SIZENESW );
		break;
		case DEHT_BOTTOMLEFT:
			cursor = LoadCursor( NULL, IDC_SIZENESW );
		break;
		case DEHT_BOTTOMMIDDLE:
			cursor = LoadCursor( NULL, IDC_SIZENS );
		break;
		case DEHT_BOTTOMRIGHT:
			cursor = LoadCursor( NULL, IDC_SIZENWSE );
		break;
		case DEHT_LEFTMIDDLE:
			cursor = LoadCursor( NULL, IDC_SIZEWE );
		break;
		case DEHT_RIGHTMIDDLE:
			cursor = LoadCursor( NULL, IDC_SIZEWE );
		break;
	}
	return cursor;
}

void CDiagramEntity::DrawSelectionMarkers( CDC* dc, CRect rect ) const
{

	// Draw selection markers
	CRect rectSelect;

	dc->SelectStockObject( BLACK_BRUSH );
	rectSelect = GetSelectionMarkerRect( DEHT_TOPLEFT, rect );
	dc->Rectangle( rectSelect );

	rectSelect = GetSelectionMarkerRect( DEHT_TOPMIDDLE, rect );
	dc->Rectangle( rectSelect );

	rectSelect = GetSelectionMarkerRect( DEHT_TOPRIGHT, rect );
	dc->Rectangle( rectSelect );

	rectSelect = GetSelectionMarkerRect( DEHT_BOTTOMLEFT, rect );
	dc->Rectangle( rectSelect );

	rectSelect = GetSelectionMarkerRect( DEHT_BOTTOMMIDDLE, rect );
	dc->Rectangle( rectSelect );

	rectSelect = GetSelectionMarkerRect( DEHT_BOTTOMRIGHT, rect );
	dc->Rectangle( rectSelect );

	rectSelect = GetSelectionMarkerRect( DEHT_RIGHTMIDDLE, rect );
	dc->Rectangle( rectSelect );

	rectSelect = GetSelectionMarkerRect( DEHT_LEFTMIDDLE, rect );
	dc->Rectangle( rectSelect );

}

CRect CDiagramEntity::GetSelectionMarkerRect( UINT marker, CRect rect ) const
{

	CRect rectMarker;
	int horz = m_markerSize.cx / 2;
	int vert = m_markerSize.cy / 2;

	switch( marker )
	{
		case DEHT_TOPLEFT:
			rectMarker.SetRect( rect.left - horz,
								rect.top - vert,
								rect.left + horz,
								rect.top + vert );
		break;

		case DEHT_TOPMIDDLE:
			rectMarker.SetRect( rect.left + ( rect.Width() / 2 ) - horz,
								rect.top - vert,
								rect.left + ( rect.Width() / 2 ) + horz,
								rect.top + vert );
		break;

		case DEHT_TOPRIGHT:
			rectMarker.SetRect( rect.right - horz,
								rect.top - vert,
								rect.right + horz,
								rect.top + vert );
		break;

		case DEHT_BOTTOMLEFT:
			rectMarker.SetRect( rect.left - horz,
								rect.bottom - vert,
								rect.left + horz,
								rect.bottom + vert );
		break;

		case DEHT_BOTTOMMIDDLE:
			rectMarker.SetRect( rect.left + ( rect.Width() / 2 ) - horz,
								rect.bottom - vert,
								rect.left + ( rect.Width() / 2 ) + horz,
								rect.bottom + vert );
		break;

		case DEHT_BOTTOMRIGHT:
			rectMarker.SetRect( rect.right - horz,
								rect.bottom - vert,
								rect.right + horz,
								rect.bottom + vert );
		break;

		case DEHT_LEFTMIDDLE:
			rectMarker.SetRect( rect.left - horz,
								rect.top + ( rect.Height() / 2 ) - vert,
								rect.left + horz,
								rect.top + ( rect.Height() / 2 ) + vert );
		break;

		case DEHT_RIGHTMIDDLE:
			rectMarker.SetRect( rect.right - horz,
								rect.top + ( rect.Height() / 2 ) - vert,
								rect.right + horz,
								rect.top + ( rect.Height() / 2 ) + vert );
		break;
	}

	return rectMarker;

}

void CDiagramEntity::SetParent( CDiagramEntityContainer * parent )
{

	m_parent = parent;

}

void CDiagramEntity::GetFont( LOGFONT& lf ) const
{

	HFONT hfont = ( HFONT ) ::GetStockObject( DEFAULT_GUI_FONT );
	CFont* font = CFont::FromHandle( hfont );
	font->GetLogFont( &lf );
	lf.lfHeight = round( static_cast< double >( lf.lfHeight ) * m_zoom );

}

CString CDiagramEntity::GetType() const
{
	return m_type;
}

void CDiagramEntity::SetType( CString type )
{
	m_type = type;
}

CString CDiagramEntity::GetTitle() const
{

	return m_title;

}

void CDiagramEntity::SetTitle( CString title )
{

	m_title = title;

}

CString CDiagramEntity::GetName() const
{
	return m_name;

}

void CDiagramEntity::SetName( CString name )
{

	m_name = name;

}

double CDiagramEntity::GetLeft() const
{

	return m_left;

}

double CDiagramEntity::GetRight() const
{

	return m_right;

}

double CDiagramEntity::GetTop() const
{

	return m_top;

}

double CDiagramEntity::GetBottom() const
{

	return m_bottom;

}

void CDiagramEntity::SetLeft( double left )
{

	m_left = left;

}

void CDiagramEntity::SetRight( double right )
{

	m_right = right;

}

void CDiagramEntity::SetTop( double top )
{
if( top == m_bottom )
	top = top;
	m_top = top;

}

void CDiagramEntity::SetBottom( double bottom )
{

	m_bottom = bottom;

}

void CDiagramEntity::SetMarkerSize( CSize markerSize )
{

	m_markerSize = markerSize;

}

CSize CDiagramEntity::GetMarkerSize() const
{

	return m_markerSize;

}

void CDiagramEntity::SetMinimumSize( CSize minimumSize )
{

	m_minimumSize = minimumSize;

}

CSize CDiagramEntity::GetMinimumSize() const
{

	return m_minimumSize;

}

void CDiagramEntity::SetMaximumSize( CSize maximumSize )
{

	m_maximumSize = maximumSize;

}

CSize CDiagramEntity::GetMaximumSize() const
{

	return m_maximumSize;

}

void CDiagramEntity::SetConstraints( CSize min, CSize max )
{

	m_minimumSize = min;
	m_maximumSize = max;

}

CDiagramEntityContainer* CDiagramEntity::GetParent() const
{

	return m_parent;

}

void CDiagramEntity::SetPropertyDialog( CDiagramPropertyDlg* dlg, UINT dlgresid )
{

	m_propertydlg = dlg;
	m_propertydlgresid = dlgresid;

	if( dlg )
		m_propertydlg->SetEntity( this );

}

CDiagramPropertyDlg* CDiagramEntity::GetPropertyDialog() const
{

	return m_propertydlg;

}

int CDiagramEntity::GetGroup() const
{

	return m_group;

}

void CDiagramEntity::SetGroup( int group )
{

	m_group = group;

}

CString CDiagramEntity::Export( UINT /*format*/ ) const
{

	return _T( "" );

}

CString CDiagramEntity::GetFont() const
{
	return m_fontName;
}

void CDiagramEntity::SetFont( const CString& fontName )
{
	m_fontName = fontName;
}

int CDiagramEntity::GetFontSize() const
{
	return m_nFontSize;
}

void CDiagramEntity::SetFontSize( const int& nFontSize )
{
	m_nFontSize = nFontSize;
}

int CDiagramEntity::GetHitCode( const CPoint& point, const CRect& rect ) const
{

	int result = DEHT_NONE;

	if( rect.PtInRect( point ) )
		result = DEHT_BODY;

	CRect rectTest;

	rectTest = GetSelectionMarkerRect( DEHT_TOPLEFT, rect );
	if( rectTest.PtInRect( point ) )
		result = DEHT_TOPLEFT;

	rectTest = GetSelectionMarkerRect( DEHT_TOPMIDDLE, rect );
	if( rectTest.PtInRect( point ) )
		result = DEHT_TOPMIDDLE;

	rectTest = GetSelectionMarkerRect( DEHT_TOPRIGHT, rect );
	if( rectTest.PtInRect( point ) )
		result = DEHT_TOPRIGHT;

	rectTest = GetSelectionMarkerRect( DEHT_BOTTOMLEFT, rect );
	if( rectTest.PtInRect( point ) )
		result = DEHT_BOTTOMLEFT;

	rectTest = GetSelectionMarkerRect( DEHT_BOTTOMMIDDLE, rect );
	if( rectTest.PtInRect( point ) )
		result = DEHT_BOTTOMMIDDLE;

	rectTest = GetSelectionMarkerRect( DEHT_BOTTOMRIGHT, rect );
	if( rectTest.PtInRect( point ) )
		result = DEHT_BOTTOMRIGHT;

	rectTest = GetSelectionMarkerRect( DEHT_LEFTMIDDLE, rect );
	if( rectTest.PtInRect( point ) )
		result = DEHT_LEFTMIDDLE;

	rectTest = GetSelectionMarkerRect( DEHT_RIGHTMIDDLE, rect );
	if( rectTest.PtInRect( point ) )
		result = DEHT_RIGHTMIDDLE;

	return result;

}

