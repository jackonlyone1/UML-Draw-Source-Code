

#include "stdafx.h"
#include "Operation.h"
#include "Tokenizer.h"
#include "StringHelpers.h"
#include "UMLEntity.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Construction/destruction
COperation::COperation() 
{

	maintype = 0;
	access = 0;

	setter = FALSE;
	getter = FALSE;

}

COperation::~COperation() 
{
}

// Implementation
CString COperation::ToString( BOOL nomarkers, BOOL nooperationattributenames ) 
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
	output += _T( "( " );
	output += parameters.ToString( nooperationattributenames );

	output += _T( " )" );
	if( type.GetLength() )
	{
		output += _T( ":" );
		output += type;
	}

	output += properties.GetString( STRING_FORMAT_UML );

	return output;

}

COperation* COperation::Clone( ) 
{

	COperation* obj = new COperation;
	obj->maintype = maintype;
	obj->name = name;
	obj->access = access;
	obj->type = type;

	obj->parameters.Copy( parameters );
	obj->properties.Copy( properties );

	obj->stereotype = stereotype;

	obj->setter = setter;
	obj->getter = getter;
	obj->getsetvariable = getsetvariable;

	obj->parameters.Copy( parameters );

	return obj;

}

COperation* COperation::FromString( const CString& str ) 
{

	COperation* op = NULL;
	CTokenizer tok( str, _T( "|" ) );
	if( tok.GetSize() == 10 )
	{
		op = new COperation;
		CString params;
		CString propertylist;
		CString stereotype;
		BOOL	getter;
		BOOL	setter;
		CString getsetvariable;

		int count = 0;
		tok.GetAt( count++, op->maintype );
		tok.GetAt( count++, op->access );
		tok.GetAt( count++, op->name );
		tok.GetAt( count++, op->type );
		tok.GetAt( count++, propertylist );
		tok.GetAt( count++, stereotype );
		tok.GetAt( count++, getter );
		tok.GetAt( count++, setter );
		tok.GetAt( count++, getsetvariable );
		tok.GetAt( count++, params );

		UnmakeSaveString( propertylist );
		UnmakeSaveString( params );
		UnmakeSaveString( stereotype );
		UnmakeSaveString( getsetvariable );

		op->properties.FromString( propertylist );
		op->parameters.FromString( params );

		op->stereotype = stereotype;
		op->getter = getter;
		op->setter = setter;
		op->getsetvariable = getsetvariable;

	}

	return op;

}

CString COperation::GetString( int format ) const 
{

	CString result;
	switch( format )
	{
		case STRING_FORMAT_SAVE:
			{
				CString propertylist( properties.GetString() );
				CString stereo( stereotype );
				CString getset( getsetvariable );
				CString params( parameters.GetString() );

				MakeSaveString( propertylist );
				MakeSaveString( stereo );
				MakeSaveString( getset );
				MakeSaveString( params );

				result.Format( _T( "%i|%i|%s|%s|%s|%s|%i|%i|%s|%s" ),
					maintype,
					access,
					name,
					type,
					propertylist,
					stereo,
					getter,
					setter,
					getset,
					params );
			}
			break;

		case STRING_FORMAT_H:
			{

				// main type
				if( maintype & ENTITY_TYPE_ABSTRACT || properties.GetPropertyValue( _T( "virtual" ) ) == _T( "true" ) )
					result += _T( "\tvirtual " );

				else if( maintype & ENTITY_TYPE_STATIC )
					result += _T( "\tstatic " );
				else
					result += _T( "\t" );

				// return value
				if( type.GetLength() )
					result += type + _T( " " );
				else
					result += _T( "void " );

				// function name and parameters
				result += name + _T( "( " );
				result += parameters.GetString( STRING_FORMAT_H );

				// const
				result += _T( " )" );
				if( properties.GetPropertyValue( _T( "query" ) ) == _T( "true" ) )
					result += _T( " const" );

				// pure virtual
				if( maintype & ENTITY_TYPE_ABSTRACT )
					result += _T( " = 0" );

				result += _T( ";" );
			}
			break;

		case STRING_FORMAT_H_TEMPLATE:
			{

				// main type
				if( maintype & ENTITY_TYPE_ABSTRACT || properties.GetPropertyValue( _T( "virtual" ) ) == _T( "true" ) )
					result += _T( "\tvirtual " );

				else if( maintype & ENTITY_TYPE_STATIC )
					result += _T( "\tstatic " );
				else
					result += _T( "\t" );

				// return value
				if( type.GetLength() )
					result += type + _T( " " );
				else
					result += _T( "void " );

				// function name and parameters
				result += name + _T( "( " );
				result += parameters.GetString( STRING_FORMAT_H );

				// const
				result += _T( " )" );
				if( properties.GetPropertyValue( _T( "query" ) ) == _T( "true" ) )
					result += _T( " const" );

				// pure virtual
				if( maintype & ENTITY_TYPE_ABSTRACT )
					result += _T( " = 0" );

				result += _T( " {\r\n\t\t// TODO: Implement\r\n\t};" );

			}
			break;

		case STRING_FORMAT_H_CTOR:
			{
				// This is a constructor/destructor, and
				// we don't want any return value

				result += _T( "\t" );

				if( maintype & ENTITY_TYPE_ABSTRACT || properties.GetPropertyValue( _T( "virtual" ) ) == _T( "true" ) )
					result += _T( "virtual " );

				// function name and parameters
				result += name + _T( "( " );
				result += parameters.GetString( STRING_FORMAT_H );
				result += _T( " );" );

			}
			break;

		case STRING_FORMAT_H_CTOR_TEMPLATE:
			{
				// This is a constructor/destructor, and
				// we don't want any return value

				result += _T( "\t" );

				if( maintype & ENTITY_TYPE_ABSTRACT || properties.GetPropertyValue( _T( "virtual" ) ) == _T( "true" ) )
					result += _T( "virtual " );

				// function name and parameters
				result += name + _T( "( " );
				result += parameters.GetString( STRING_FORMAT_H );
				result += _T( " ) {\r\n\t\t//TODO: Implement\r\n\t};" );

			}
			break;
	}

	return result;

}

BOOL COperation::operator==( const COperation& operation ) 
{

	BOOL result = FALSE;

	if( name == operation.name &&
		type == operation.type &&
		parameters == operation.parameters )
		result = TRUE;

	return result;

}
