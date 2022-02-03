#ifndef _ATTRIBUTECONTAINER_H_D3C33FC_673D_434A_A76E563AFDB
#define _ATTRIBUTECONTAINER_H_D3C33FC_673D_434A_A76E563AFDB

///////////////////////////////////////////////////////////
// File :		AttributeContainer.h
// Created :	06/08/04
//

#include "Attribute.h"

 
//===========================================================================
// Summary:
//      To use a CAttributeContainer object, just call the constructor.
//      Attribute Container
//===========================================================================

class CAttributeContainer
{
public:
	// Construction/destruction
	
	//-----------------------------------------------------------------------
	// Summary:
	// Attribute Container, Constructs a CAttributeContainer object.
	//		Returns A  value.
	CAttributeContainer();
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Attribute Container, Destructor of class CAttributeContainer
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CAttributeContainer();

// Operations
	
	//-----------------------------------------------------------------------
	// Summary:
	// Create a duplicate copy of this object.
	// Parameters:
	//		attributes---Specifies a CAttributeContainer & attributes object.
	void Copy( CAttributeContainer & attributes );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Size, Returns the specified value.
	//		Returns a int type value.  
	// Parameters:
	//		---Specifies a  object.
	int GetSize(  ) const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get At, Returns the specified value.
	//		Returns a pointer to the object CAttribute,or NULL if the call failed  
	// Parameters:
	//		index---Specifies A integer value.
	CAttribute* GetAt( int index ) const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Remove At, Call this function to remove a specify value from the specify object.
	// Parameters:
	//		index---Specifies A integer value.
	void RemoveAt( int index );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Remove All, Call this function to remove a specify value from the specify object.
	// Parameters:
	//		---Specifies a  object.
	void RemoveAll(  );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Adds an object to the specify list.
	// Parameters:
	//		attribute---A pointer to the CAttribute  or NULL if the call failed.
	void Add( CAttribute * attribute );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get String, Returns the specified value.
	//		Returns a CString type value.  
	// Parameters:
	//		format---Specifies A integer value.
	CString GetString( int format = STRING_FORMAT_SAVE ) const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Size, Sets a specify value to current class CAttributeContainer
	// Parameters:
	//		size---Specifies A integer value.
	void SetSize( int size );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set At, Sets a specify value to current class CAttributeContainer
	// Parameters:
	//		index---Specifies A integer value.  
	//		obj---A pointer to the CAttribute or NULL if the call failed.
	void SetAt( int index, CAttribute* obj );

// Attributes
private:
 
	// This member specify CObArray object.  
	CObArray m_attributes;


};
#endif //_ATTRIBUTECONTAINER_H_D3C33FC_673D_434A_A76E563AFDB
