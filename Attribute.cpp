
#include "stdafx.h"
#include "Attribute.h"
#include "Tokenizer.h"
#include "StringHelpers.h"
#include "UMLEntity.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Construction/destruction
CAttribute::CAttribute() 
{

	maintype = 0;
	access = 0;

}

CAttribute::~CAttribute() 
{
}

// Implementation
CString CAttribute::ToString( BOOL nomarkers ) 
{

	CString output;
	if( stereotype.GetLength() )
 		output = _T( "« " ) + stereotype +  _T( " » " );

	if( !nomarkers )
	{
		if( access == ACCESS_TYPE_PRIVATE )
			output = _T( "-" );
		if( access == ACCESS_TYPE_PROTECTED )
			output = _T( "#" );
		if( access == ACCESS_TYPE_PUBLIC )
			output = _T( "+" );
	}
	output += name;
	output += _T( ":" );
	output += type;

	if( multiplicity.GetLength() )
		output += _T( "[ " ) + multiplicity + _T( " ]" );

	if( defaultvalue.GetLength() )
		output += _T( " = " ) + defaultvalue;

	output += properties.GetString( STRING_FORMAT_UML );

	return output;

}

CAttribute* CAttribute::Clone( ) 
{

	CAttribute* obj = new CAttribute;

	obj->maintype = maintype;
	obj->name = name;
	obj->access = access;
	obj->type = type;

	obj->multiplicity = multiplicity;
	obj->defaultvalue = defaultvalue;
	obj->properties.Copy( properties );

	obj->stereotype = stereotype;

	return obj;

}

CAttribute* CAttribute::FromString( const CString& str ) 
{
	CAttribute* at = NULL;

	CTokenizer tok( str, _T( "|" ) );
	if( tok.GetSize() >= 8 )
	{
		at = new CAttribute;
		CString	multi;
		CString	defaultvalue;
		CString	propertylist;
		CString stereotype;

		tok.GetAt(0, at->maintype );
		tok.GetAt(1, at->access );
		tok.GetAt(2, at->name );
		tok.GetAt(3, at->type );
		tok.GetAt(4, multi );
		tok.GetAt(5, defaultvalue );
		tok.GetAt(6, propertylist );
		tok.GetAt(7, stereotype );

		UnmakeSaveString( multi );
		UnmakeSaveString( defaultvalue );
		UnmakeSaveString( propertylist );
		UnmakeSaveString( stereotype );

		at->multiplicity = multi;
		at->defaultvalue = defaultvalue;
		at->properties.FromString( propertylist );
		at->stereotype = stereotype;

	}

	return at;

}

CString CAttribute::GetString( int format ) const 
{

	CString result;
	if( format == STRING_FORMAT_SAVE )
	{
		CString multi( multiplicity );
		CString defval( defaultvalue );
		CString propertylist( properties.GetString( STRING_FORMAT_SAVE ) );
		CString stereo( stereotype );

		MakeSaveString( multi );
		MakeSaveString( defval );
		MakeSaveString( propertylist );
		MakeSaveString( stereo );

		result.Format( _T( "%i|%i|%s|%s|%s|%s|%s|%s" ), 
			maintype,
			access,
			name,
			type,
			multi,
			defval,
			propertylist,
			stereo
		);
	}

	if( format == STRING_FORMAT_H )
	{
		if( maintype & ENTITY_TYPE_STATIC )
			result += _T( "static " );

		result += type + _T( " " );
		result += name;
		if( multiplicity.GetLength() )
		{
			CString multiplicity( multiplicity );
			int found = multiplicity.Find( _T( "." ) );
			while( found != -1 )
			{
				multiplicity = multiplicity.Right( multiplicity.GetLength() - ( found + 1 ) );
				found = multiplicity.Find( _T( "." ) );
			}

			result += _T( "[ " ) + multiplicity +  _T( " ]" );
		}
		result += _T( ";" );
	}

	return result;

}
