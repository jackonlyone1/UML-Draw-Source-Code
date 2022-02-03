

#include "stdafx.h"
#include "DiagramEntityContainer.h"
#include "DiagramEntity.h"
#include "Tokenizer.h"
#include "GroupFactory.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#pragma warning( disable : 4706 )

/////////////////////////////////////////////////////////////////////////////
// CDiagramEntityContainer construction/destruction/initialization

CDiagramEntityContainer::CDiagramEntityContainer( CDiagramClipboardHandler* clip )
{

	m_clip = clip;

	SetUndoStackSize( 0 );
	Clear();
	SetVirtualSize( CSize( 0, 0 ) );

}

CDiagramEntityContainer::~CDiagramEntityContainer()
{

	Clear();

}

void CDiagramEntityContainer::Clear()
{

	RemoveAll();
	ClearUndo();
	SetModified( FALSE );

}

CString CDiagramEntityContainer::GetString() const
{

	CString str;
	str.Format( _T( "paper:%i,%i;" ), GetVirtualSize().cx, GetVirtualSize().cy );
	return str;

}

BOOL CDiagramEntityContainer::FromString( const CString& str )
{

	BOOL result = FALSE;

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
		if( header == _T( "paper" ) )
		{
			CTokenizer tok( data.Left( data.GetLength() - 1 ) );
			int size = tok.GetSize();
			if( size == 2 )
			{
				int right;
				int bottom;

				tok.GetAt(0, right );
				tok.GetAt(1, bottom );

				SetVirtualSize( CSize( right, bottom ) );
				result = TRUE;
			}
		}
	}

	return result;

}

void CDiagramEntityContainer::Export( CStringArray& stra, UINT format ) const
{

	int max = GetSize();
	for( int t = 0 ; t < max ; t++ )
	{
		CDiagramEntity* obj = GetAt( t );
		stra.Add( obj->Export( format ) );
	}

}

/////////////////////////////////////////////////////////////////////////////
// CDiagramEntityContainer data access

int CDiagramEntityContainer::GetSize() const
{

	return m_objs.GetSize();

}

void CDiagramEntityContainer::Add( CDiagramEntity* obj )
{

	obj->SetParent( this );
	m_objs.Add( obj );
	SetModified( TRUE );

}

CDiagramEntity* CDiagramEntityContainer::GetAt( int index ) const
{

	CDiagramEntity* result = NULL;
	if( index < m_objs.GetSize() && index >= 0 )
		result = static_cast< CDiagramEntity* >( m_objs.GetAt( index ) );
	return result;

}

void CDiagramEntityContainer::SetAt( int index, CDiagramEntity* obj )
{

	m_objs.SetAt( index, obj );
	SetModified( TRUE );

}

void CDiagramEntityContainer::RemoveAt( int index )
{

	CDiagramEntity* obj = GetAt( index );
	if( obj )
	{
		delete obj;
		m_objs.RemoveAt( index );
		SetModified( TRUE );
	}

}

void CDiagramEntityContainer::RemoveAll()
{

	int max = m_objs.GetSize();
	if( max )
	{

		for( int t = 0 ; t < max ; t++ )
		{
			CDiagramEntity* obj = static_cast< CDiagramEntity* >( m_objs.GetAt( t ) );
			delete obj;
		}

		m_objs.RemoveAll();
		SetModified( TRUE );

	}

}

void CDiagramEntityContainer::RemoveAllSelected()
{

	int max = m_objs.GetSize() - 1;
	for( int t = max ; t >= 0 ; t-- )
		if( GetAt( t )->IsSelected() )
			RemoveAt( t );

}

/////////////////////////////////////////////////////////////////////////////
// CDiagramEntityContainer property access

void CDiagramEntityContainer::SetVirtualSize( CSize size )
{

	m_virtualSize = size;

}

CSize CDiagramEntityContainer::GetVirtualSize() const
{

	return m_virtualSize;

}

BOOL CDiagramEntityContainer::IsModified() const
{

	return m_dirty;

}

void CDiagramEntityContainer::SetModified( BOOL dirty )
{

	m_dirty = dirty;

}

/////////////////////////////////////////////////////////////////////////////
// CDiagramEntityContainer single object handlers

void CDiagramEntityContainer::Remove( CDiagramEntity* obj )
{

	int index = Find( obj );
	if( index != -1 )
		RemoveAt( index );

}

void CDiagramEntityContainer::Duplicate( CDiagramEntity* obj )
{

	int index = Find( obj );
	if( index != -1 )
	{
		CDiagramEntity* newobj = obj->Clone();
		newobj->SetRect( newobj->GetLeft() + 10, newobj->GetTop() + 10, newobj->GetRight() + 10, newobj->GetBottom() + 10 );
		Add( newobj );
	}

}

void CDiagramEntityContainer::Cut( CDiagramEntity* obj )
{

	Copy( obj );
	Remove( obj );

}

void CDiagramEntityContainer::Copy( CDiagramEntity* obj )
{

	ASSERT( obj );

	if( m_clip == NULL )
		m_clip = &m_internalClip;

	if( obj )
		m_clip->Copy( obj );

}

void CDiagramEntityContainer::Up( CDiagramEntity* obj )
{

	int index = Find( obj );
	Swap( index, index + 1);

}

void CDiagramEntityContainer::Down( CDiagramEntity* obj )
{

	int index = Find( obj );
	Swap( index, index - 1);

}

void CDiagramEntityContainer::Front( CDiagramEntity* obj )
{
	int index = Find( obj );
	m_objs.RemoveAt( index );
	m_objs.Add( obj );
	SetModified( TRUE );

}

void CDiagramEntityContainer::Bottom( CDiagramEntity* obj )

{

	int index = Find( obj );
	m_objs.RemoveAt( index );
	m_objs.InsertAt( 0, obj );
	SetModified( TRUE );

}

/////////////////////////////////////////////////////////////////////////////
// CDiagramEntityContainer copy/paste is implemented as separate class.

void CDiagramEntityContainer::SetClipboardHandler( CDiagramClipboardHandler* clip )
{

	m_clip = clip;

}

CDiagramClipboardHandler* CDiagramEntityContainer::GetClipboardHandler()
{

	return m_clip;

}

void CDiagramEntityContainer::CopyAllSelected()
{

	if( m_clip == NULL )
		m_clip = &m_internalClip;

	m_clip->CopyAllSelected( this );

}

int CDiagramEntityContainer::ObjectsInPaste()
{

	if( m_clip == NULL )
		m_clip = &m_internalClip;

	return m_clip->ObjectsInPaste();

}

void CDiagramEntityContainer::ClearPaste()
{

	if( m_clip == NULL )
		m_clip = &m_internalClip;

	m_clip->ClearPaste();

}

void CDiagramEntityContainer::Paste()
{

	if( m_clip == NULL )
		m_clip = &m_internalClip;

	m_clip->Paste( this );

}

/////////////////////////////////////////////////////////////////////////////
// CDiagramEntityContainer message handling

void CDiagramEntityContainer::SendMessageToObjects( int command, BOOL selected, CDiagramEntity* sender, CWnd* from )
{

	BOOL stop = FALSE;
	int max = m_objs.GetSize();
	for( int t = 0 ; t < max ; t++ )
	{
		CDiagramEntity* obj = GetAt( t );
		if( !stop && ( !selected || obj->IsSelected() ) )
		{
			stop = obj->DoMessage( command, sender, from );
			SetModified( TRUE );
		}
	}

}

/////////////////////////////////////////////////////////////////////////////
// CDiagramEntityContainer private helpers

int CDiagramEntityContainer::Find( CDiagramEntity* testobj )
{

	int index = -1;
	CDiagramEntity* obj;
	int count = 0;
	while( ( obj = GetAt( count ) ) )
	{
		if( obj == testobj )
			index = count;
		count++;
	}

	return index;

}

void CDiagramEntityContainer::Swap( int index1, int index2 )
{

	int max = m_objs.GetSize();
	if( index1 >= 0 && index1 < max && index2 >= 0 && index2 < max )
	{
		CDiagramEntity* obj1 = GetAt( index1 );
		CDiagramEntity* obj2 = GetAt( index2 );
		SetAt( index1, obj2 );
		SetAt( index2, obj1 );
	}

}

void CDiagramEntityContainer::Undo()
{

	if( m_undo.GetSize() )
	{
		// We remove all current data
		RemoveAll();

		// We get the last entry from the undo-stack
		// and clone it into the container data
		CUndoItem* undo = static_cast< CUndoItem* >( m_undo.GetAt( m_undo.GetUpperBound() ) );
		int count = ( undo->arr ).GetSize();
		for( int t = 0 ; t < count ; t++ )
		{

			CDiagramEntity* obj = static_cast< CDiagramEntity* >( ( undo->arr ).GetAt( t ) );
			Add( obj->Clone() );

		}

		// Set the saved virtual size as well
		SetVirtualSize( undo->pt );

		// We remove the entry from the undo-stack
		delete undo;

		m_undo.RemoveAt( m_undo.GetUpperBound() );

	}

}

void CDiagramEntityContainer::Snapshot()
{

	if( m_maxstacksize > 0 && m_undo.GetSize() == m_maxstacksize )
	{
		delete m_undo.GetAt( 0 );
		m_undo.RemoveAt( 0 );
	}

	CUndoItem* undo = new CUndoItem;

	while( !undo && m_undo.GetSize() )
	{

		// We seem - however unlikely -
		// to be out of memory.
		// Remove first element in
		// undo-stack and try again
		delete m_undo.GetAt( 0 );
		m_undo.RemoveAt( 0 );
		undo = new CUndoItem;

	}

	if( undo )
	{

		// Save current virtual size
		undo->pt = GetVirtualSize();

		// Save all objects
		int count = m_objs.GetSize();
		for( int t = 0 ; t < count ; t++ )
			( undo->arr ).Add( GetAt( t )->Clone() );

		// Add to undo stack
		m_undo.Add( undo );

	}

}

void CDiagramEntityContainer::ClearUndo()
{

	int count = m_undo.GetSize() - 1;
	for( int t = count ; t >= 0 ; t-- )
	{
		CUndoItem* undo = static_cast< CUndoItem* >( m_undo.GetAt( t ) );
		// Remove the stack entry itself.
		delete undo;
	}

	m_undo.RemoveAll();

}

BOOL CDiagramEntityContainer::IsUndoPossible()
{

	return m_undo.GetSize();

}


void CDiagramEntityContainer::SetUndoStackSize( int maxstacksize )
{

	m_maxstacksize = maxstacksize;

}

int CDiagramEntityContainer::GetUndoStackSize() const
{

	return m_maxstacksize;

}

CObArray* CDiagramEntityContainer::GetData() 
{ 

	return &m_objs; 

}

CObArray* CDiagramEntityContainer::GetPaste()	
{ 

	CObArray* arr = NULL;
	if( m_clip )
		arr = m_clip->GetData();

	return arr;

}

CObArray* CDiagramEntityContainer::GetUndo()
{ 

	return &m_undo;

}

void CDiagramEntityContainer::Group()
{

	CDiagramEntity* obj;
	int count = 0;
	int group = CGroupFactory::GetNewGroup();
	while( ( obj = GetAt( count ) ) )
	{
		if( obj->IsSelected() )
			obj->SetGroup( group );
		count++;
	}

}

void CDiagramEntityContainer::Ungroup()
{

	CDiagramEntity* obj;
	int count = 0;
	while( ( obj = GetAt( count ) ) )
	{
		if( obj->IsSelected() )
			obj->SetGroup( 0 );
		count++;
	}

}

CSize CDiagramEntityContainer::GetTotalSize()
{
	CPoint start = GetStartPoint();
	double width = 0;
	double height = 0;

	CDiagramEntity* obj;
	int count = 0;
	while( ( obj = GetAt( count ) ) )
	{

		width = max( width, obj->GetLeft() );
		width = max( width, obj->GetRight() );
		height = max( height, obj->GetTop() );
		height = max( height, obj->GetBottom() );

		count++;

	}

	return CSize( round( width - start.x ), round( height - start.y ) );

}

CPoint CDiagramEntityContainer::GetStartPoint()
{

	double startx = 2000.0;
	double starty = 2000.0;

	CDiagramEntity* obj;
	int count = 0;

	while( ( obj = GetAt( count ) ) )
	{

		startx = min( startx, obj->GetLeft() );
		startx = min( startx, obj->GetRight() );
		starty = min( starty, obj->GetTop() );
		starty = min( starty, obj->GetBottom() );

		count++;

	}

	return CPoint( round( startx ), round( starty ) );

}

int	CDiagramEntityContainer::GetSelectCount() const
{

	int max = GetSize();
	int count = 0;
	for( int t = 0 ; t < max ; t++ )
		if( GetAt( t )->IsSelected() )
			count++;

	return count;

}

void CDiagramEntityContainer::SelectAll()
{
	int max = GetSize();
	for( int t = 0 ; t < max ; t++ )
		GetAt( t )->Select( TRUE );
}

void CDiagramEntityContainer::UnselectAll()
{
	int max = GetSize();
	for( int t = 0 ; t < max ; t++ )
		GetAt( t )->Select( FALSE );
}

#pragma warning( default : 4706 )
