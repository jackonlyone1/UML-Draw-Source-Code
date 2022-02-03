

#include "stdafx.h"
#include "OperationContainer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////////////////////////////////////////////////////////////////////
// Construction/destruction
//

COperationContainer::COperationContainer()
{
}

COperationContainer::~COperationContainer()
{

	RemoveAll();

}

////////////////////////////////////////////////////////////////////
// Public functions
//
void COperationContainer::Copy( COperationContainer & operations )
{

	RemoveAll();
	int max = operations.GetSize();
	m_operations.SetSize( max );
	for( int t = 0 ; t < max ; t++ )
		m_operations.SetAt( t, ( operations.GetAt( t ) )->Clone() );

}

int COperationContainer::GetSize( ) const
{

	return m_operations.GetSize();

}

COperation* COperationContainer::GetAt( int index) const
{

	COperation* result = NULL;

	if( index > -1 && index < GetSize() )
		result = static_cast< COperation* >( m_operations.GetAt( index ) );

	return result;

}

void COperationContainer::RemoveAt( int index)
{

	if( index > -1 && index < GetSize() )
	{
		delete GetAt( index );
		m_operations.RemoveAt( index );
	}

}

void COperationContainer::RemoveAll( )
{

	while( GetSize() )
		RemoveAt( 0 );

}

void COperationContainer::Add( COperation * operation )
{

	m_operations.Add( operation );

}

CString COperationContainer::GetString( int format ) const
{

	CString result;
	if( format == STRING_FORMAT_SAVE )
		for( int t = 0 ; t < GetSize() ; t++ )
			result += _T( "," ) + GetAt( t )->GetString();

	return result;

}

void COperationContainer::SetSize( int size )
{

	m_operations.SetSize( size );

}

void COperationContainer::SetAt( int index, COperation* obj )
{

	if( index > -1 && index < GetSize() )
		m_operations.SetAt( index, obj );

}
