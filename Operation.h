#ifndef _COPERATION_H_BC44C7A7_DC64_452A_877F13EC3D7E
#define _COPERATION_H_BC44C7A7_DC64_452A_877F13EC3D7E

///////////////////////////////////////////////////////////
// Operation.h
// Created: 06/02/04
//

#include "StringHelpers.h"
#include "PropertyContainer.h"
#include "ParameterContainer.h"

 
//===========================================================================
// Summary:
//     The COperation class derived from CObject
//      Operation
//===========================================================================

class COperation : public CObject
{
public:
	// Construction/destruction
	
	//-----------------------------------------------------------------------
	// Summary:
	// Operation, Constructs a COperation object.
	//		Returns A  value.
	COperation();
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Operation, Destructor of class COperation
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~COperation();

	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		operation---Specifies a const COperation& operation object.
	BOOL operator==( const COperation& operation );

// Operations
	
	//-----------------------------------------------------------------------
	// Summary:
	// To String, None Description.
	//		Returns a CString type value.  
	// Parameters:
	//		nomarkers---Specifies A Boolean value.  
	//		nooperationattributenames---Specifies A Boolean value.
	CString ToString( BOOL nomarkers, BOOL nooperationattributenames );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Clone this object.
	//		Returns a pointer to the object COperation,or NULL if the call failed  
	// Parameters:
	//		---Specifies a  object.
	COperation* Clone( );
	
	//-----------------------------------------------------------------------
	// Summary:
	// From String, None Description.
	// This member function is a static function.
	//		Returns a pointer to the object COperation,or NULL if the call failed  
	// Parameters:
	//		str---Specifies A CString type value.
	static COperation* FromString( const CString& str );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get String, Returns the specified value.
	//		Returns a CString type value.  
	// Parameters:
	//		format---Specifies A integer value.
	CString GetString( int format = STRING_FORMAT_SAVE ) const;

// Attributes
 
	// This variable specifies a 32-bit signed integer on 32-bit platforms.  
	int maintype;					// Static or virtual
 
	// This variable specifies a 32-bit signed integer on 32-bit platforms.  
	int access;						// public, private, protected
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString name;					// variable name
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString type;					// variable type
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString stereotype;				// stereotype, if any.

 
	// This member sets TRUE if it is right.  
	BOOL	setter;					// TRUE if a setter
 
	// This member sets TRUE if it is right.  
	BOOL	getter;					// TRUE if a getter
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString getsetvariable;			// getter/setter variable

 
	// This member specify CParameterContainer object.  
	CParameterContainer	parameters;	// Parameters
 
	// This member specify CPropertyContainer object.  
	CPropertyContainer	properties;	// Properties

};

#endif //_COPERATION_H_BC44C7A7_DC64_452A_877F13EC3D7E
