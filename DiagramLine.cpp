

#include "stdafx.h"
#include "DiagramLine.h"
#include "Tokenizer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

VOID CALLBACK HitTest( int X, int Y, LPARAM data );
VOID CALLBACK HitTestRect( int X, int Y, LPARAM data );

/////////////////////////////////////////////////////////////////////////////
// CDiagramLine
//

CDiagramLine::CDiagramLine()
{

	SetMinimumSize( CSize( -1, -1 ) );
	SetType( _T( "line" ) );

}

CDiagramLine::~CDiagramLine()
{
}

CDiagramEntity* CDiagramLine::Clone() 
{

	CDiagramLine* obj = new CDiagramLine;
	obj->Copy( this );
	return obj;

}

void CDiagramLine::SetRect( CRect rect ) 
{

	SetLeft( rect.left );
	SetTop( rect.top );
	SetRight( rect.right );
	SetBottom( rect.bottom );

}

BOOL CDiagramLine::BodyInRect( CRect rect ) const 
{

	BOOL result = FALSE;
	hitParamsRect hit;
	hit.rect = rect;
	hit.hit = FALSE;

	LineDDA(	static_cast< int >( GetLeft() ), 
				static_cast< int >( GetTop() ), 
				static_cast< int >( GetRight() ), 
				static_cast< int >( GetBottom() ), 
				HitTestRect, 
				( LPARAM ) &hit );

	if( hit.hit )
		result = TRUE;

	return result;

}

int CDiagramLine::GetHitCode( CPoint point ) const 
{

	int result = DEHT_NONE;

	CRect rect = GetRect();

	hitParams hit;
	hit.hit = FALSE;
	hit.x = point.x;
	hit.y = point.y;

	LineDDA(	static_cast< int >( GetLeft() ), 
				static_cast< int >( GetTop() ), 
				static_cast< int >( GetRight() ), 
				static_cast< int >( GetBottom() ), 
				HitTest, 
				( LPARAM ) &hit );

	if( hit.hit )
		result = DEHT_BODY;

	CRect rectTest;

	rectTest = GetSelectionMarkerRect( DEHT_TOPLEFT, rect );
	if( rectTest.PtInRect( point ) )
		result = DEHT_TOPLEFT;

	rectTest = GetSelectionMarkerRect( DEHT_BOTTOMRIGHT, rect );
	if( rectTest.PtInRect( point ) )
		result = DEHT_BOTTOMRIGHT;

	return result;

}

void CDiagramLine::Draw( CDC* dc, CRect rect ) 
{

	dc->SelectStockObject( BLACK_PEN );

	dc->MoveTo( rect.TopLeft() );
	dc->LineTo( rect.BottomRight() );

}

HCURSOR CDiagramLine::GetCursor( int hit ) const 
{

	HCURSOR cursor = NULL;
	switch( hit )
	{
		case DEHT_BODY:
		cursor = LoadCursor( NULL, IDC_SIZEALL );
		break;
		case DEHT_TOPLEFT:
		cursor = LoadCursor( NULL, IDC_SIZEALL );
		break;
		case DEHT_BOTTOMRIGHT:
		cursor = LoadCursor( NULL, IDC_SIZEALL );
		break;
	}

	return cursor;

}

void CDiagramLine::DrawSelectionMarkers( CDC* dc, CRect rect ) const 
{

	// Draw selection markers
	CRect rectSelect;
	dc->SelectStockObject( BLACK_BRUSH );

	rectSelect = GetSelectionMarkerRect( DEHT_TOPLEFT, rect );
	dc->Rectangle( rectSelect );

	rectSelect = GetSelectionMarkerRect( DEHT_BOTTOMRIGHT, rect );
	dc->Rectangle( rectSelect );

}

CDiagramEntity* CDiagramLine::CreateFromString( const CString& str ) 
{

	CDiagramLine* obj = new CDiagramLine;
	if(!obj->FromString( str ) )
	{
		delete obj;
		obj = NULL;
	}

	return obj;

}

VOID CALLBACK HitTest( int X, int Y, LPARAM data )
{
 	hitParams* obj = ( hitParams* ) data;

	if( obj->x >= X - 1 && obj->x <= X + 1 && obj->y >= Y - 1 && obj->y <= Y + 1 )
		obj->hit = TRUE;

}

VOID CALLBACK HitTestRect( int X, int Y, LPARAM data )
{
 	hitParamsRect* obj = ( hitParamsRect* ) data;
	CPoint pt( X, Y );

	if( obj->rect.PtInRect( pt ) )
		obj->hit = TRUE;

}

