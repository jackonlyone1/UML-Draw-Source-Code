#ifndef _OPERATIONCONTAINER_H_5DE26980_B9B9_4899_8993C9B614
#define _OPERATIONCONTAINER_H_5DE26980_B9B9_4899_8993C9B614


#include "Operation.h"

 
//===========================================================================
// Summary:
//      To use a COperationContainer object, just call the constructor.
//      Operation Container
//===========================================================================

class COperationContainer
{
public:
	// Construction/destruction
	
	//-----------------------------------------------------------------------
	// Summary:
	// Operation Container, Constructs a COperationContainer object.
	//		Returns A  value.
	COperationContainer();
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Operation Container, Destructor of class COperationContainer
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~COperationContainer();

// Operations
	
	//-----------------------------------------------------------------------
	// Summary:
	// Create a duplicate copy of this object.
	// Parameters:
	//		operations---Specifies a COperationContainer & operations object.
	void Copy( COperationContainer & operations );
	
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
	//		Returns a pointer to the object COperation,or NULL if the call failed  
	// Parameters:
	//		index---Specifies A integer value.
	COperation* GetAt( int index ) const;
	
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
	//		operation---A pointer to the COperation  or NULL if the call failed.
	void Add( COperation * operation );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get String, Returns the specified value.
	//		Returns a CString type value.  
	// Parameters:
	//		format---Specifies A integer value.
	CString GetString( int format = STRING_FORMAT_SAVE ) const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Size, Sets a specify value to current class COperationContainer
	// Parameters:
	//		size---Specifies A integer value.
	void SetSize( int size );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set At, Sets a specify value to current class COperationContainer
	// Parameters:
	//		index---Specifies A integer value.  
	//		obj---A pointer to the COperation or NULL if the call failed.
	void SetAt( int index, COperation* obj );

// Attributes

private:
 
	// This member specify CObArray object.  
	CObArray m_operations;


};
#endif //_OPERATIONCONTAINER_H_5DE26980_B9B9_4899_8993C9B614
