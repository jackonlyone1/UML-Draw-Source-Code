#ifndef _CATTRIBUTE_H_7261F2E3_1899_4934_B253082664F
#define _CATTRIBUTE_H_7261F2E3_1899_4934_B253082664F

///////////////////////////////////////////////////////////
// Attribute.h
// Created: 06/02/04
//

#include "StringHelpers.h"
#include "PropertyContainer.h"

 
//===========================================================================
// Summary:
//     The CAttribute class derived from CObject
//      Attribute
//===========================================================================

class CAttribute : public CObject
{
public:
	// Construction/destruction
	
	//-----------------------------------------------------------------------
	// Summary:
	// Attribute, Constructs a CAttribute object.
	//		Returns A  value.
	CAttribute();
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Attribute, Destructor of class CAttribute
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CAttribute();

// Operations
	
	//-----------------------------------------------------------------------
	// Summary:
	// To String, None Description.
	//		Returns a CString type value.  
	// Parameters:
	//		nomarkers---Specifies A Boolean value.
	CString ToString( BOOL nomarkers );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Clone this object.
	//		Returns a pointer to the object CAttribute,or NULL if the call failed  
	// Parameters:
	//		---Specifies a  object.
	CAttribute* Clone( );
	
	//-----------------------------------------------------------------------
	// Summary:
	// From String, None Description.
	// This member function is a static function.
	//		Returns a pointer to the object CAttribute,or NULL if the call failed  
	// Parameters:
	//		str---Specifies A CString type value.
	static CAttribute* FromString( const CString& str );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get String, Returns the specified value.
	//		Returns a CString type value.  
	// Parameters:
	//		format---Specifies A integer value.
	CString GetString( int format = STRING_FORMAT_SAVE ) const;


// Attributes
 
	// This variable specifies a 32-bit signed integer on 32-bit platforms.  
	int maintype;
 
	// This variable specifies a 32-bit signed integer on 32-bit platforms.  
	int access;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString name;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString type;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString multiplicity;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString defaultvalue;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString stereotype;

 
	// This member specify CPropertyContainer object.  
	CPropertyContainer	properties;

};

#endif //_CATTRIBUTE_H_7261F2E3_1899_4934_B253082664F
