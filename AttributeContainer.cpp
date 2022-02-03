
#include "stdafx.h"
#include "AttributeContainer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////////////////////////////////////////////////////////////////////
// Construction/destruction
//
CAttributeContainer::CAttributeContainer()
{
}

CAttributeContainer::~CAttributeContainer()
{

	RemoveAll();

}

void CAttributeContainer::Copy( CAttributeContainer & attributes )
{

	RemoveAll();
	int max = attributes.GetSize();
	m_attributes.SetSize( max );
	for( int t = 0 ; t < max ; t++ )
		m_attributes.SetAt( t, ( attributes.GetAt( t ) )->Clone() );

}

int CAttributeContainer::GetSize( ) const
{

	return m_attributes.GetSize();

}

CAttribute* CAttributeContainer::GetAt( int index ) const
{

	CAttribute* result = NULL;

	if( index > -1 && index < GetSize() )
		result = static_cast< CAttribute* >( m_attributes.GetAt( index ) );

	return result;

}

void CAttributeContainer::RemoveAt( int index )
{

	if( index > -1 && index < GetSize() )
	{
		delete GetAt( index );
		m_attributes.RemoveAt( index );
	}

}

void CAttributeContainer::RemoveAll( )
{

	while( GetSize() )
		RemoveAt( 0 );

}

void CAttributeContainer::Add( CAttribute * attribute )
{

	m_attributes.Add( attribute );

}

CString CAttributeContainer::GetString( int format ) const
{

	CString result;
	if( format == STRING_FORMAT_SAVE )
		for( int t = 0 ; t < GetSize() ; t++ )
			result += _T( "," ) + GetAt( t )->GetString();

	return result;

}

void CAttributeContainer::SetSize( int size )
{

	m_attributes.SetSize( size );

}

void CAttributeContainer::SetAt( int index, CAttribute* obj )
{

	if( index > -1 && index < GetSize() )
		m_attributes.SetAt( index, obj );

}

