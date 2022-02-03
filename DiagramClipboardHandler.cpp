
#include "stdafx.h"
#include "DiagramClipboardHandler.h"
#include "DiagramEntityContainer.h"
#include "GroupFactory.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// 

CDiagramClipboardHandler::CDiagramClipboardHandler() 
{
}

CDiagramClipboardHandler::~CDiagramClipboardHandler() 
{

	ClearPaste();

}

void CDiagramClipboardHandler::Copy( CDiagramEntity* obj ) 
{

	ClearPaste();
	CDiagramEntity* newobj = obj->Clone();
	newobj->Select( TRUE );
	newobj->MoveRect( 10, 10 );
	m_paste.Add( newobj );

}

void CDiagramClipboardHandler::CopyAllSelected( CDiagramEntityContainer* container ) 
{

	ClearPaste();
	CObArray* arr = container->GetData();

	int	max = arr->GetSize();
	for( int t = 0 ; t < max ; t++ )
	{
		CDiagramEntity* obj = static_cast< CDiagramEntity* >( arr->GetAt( t ) );
		if( obj->IsSelected() )
		{
			CDiagramEntity* newobj = obj->Clone();
			newobj->Select( TRUE );
			newobj->MoveRect( 10, 10 );
			newobj->SetGroup( obj->GetGroup() );
			m_paste.Add( newobj );
		}
	}

}

int CDiagramClipboardHandler::ObjectsInPaste() 
{

	return m_paste.GetSize();

}

void CDiagramClipboardHandler::ClearPaste() 
{

	int count = m_paste.GetSize() - 1;
	for( int t = count ; t >= 0 ; t-- )
		delete static_cast< CDiagramEntity* >( m_paste.GetAt( t ) );
	m_paste.RemoveAll();

}

void CDiagramClipboardHandler::Paste( CDiagramEntityContainer* container ) 
{
	CDWordArray	oldgroup;
	CDWordArray	newgroup;

	int max = m_paste.GetSize();
	int t = 0;
	for( t = 0 ; t < max ; t++ )
	{
		CDiagramEntity* obj = static_cast< CDiagramEntity* >( m_paste.GetAt( t ) );
		if( obj->GetGroup() )
		{
			int size = oldgroup.GetSize();
			BOOL found = FALSE;
			for( int i = 0 ; i < size ; i++ )
				if( obj->GetGroup() == static_cast< int > ( oldgroup[ i ] ) )
					found = TRUE;

			if( !found )
			{
				oldgroup.Add( obj->GetGroup() );
				newgroup.Add( CGroupFactory::GetNewGroup() );
			}
		}
	}

	for( t = 0 ; t < max ; t++ )
	{
		CDiagramEntity* obj = static_cast< CDiagramEntity* >( m_paste.GetAt( t ) );
		CDiagramEntity* clone = obj->Clone();

		int group = 0;
		if( obj->GetGroup() )
		{
			int size = oldgroup.GetSize();
			for( int i = 0 ; i < size ; i++ )
				if( obj->GetGroup() == static_cast< int >( oldgroup[ i ] ) )
					group = newgroup[ i ];
		}

		clone->SetGroup( group );
		container->Add( clone );
	}

}

CObArray* CDiagramClipboardHandler::GetData()  
{ 
	
	return &m_paste; 

}
