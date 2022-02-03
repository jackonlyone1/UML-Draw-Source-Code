#if !defined(AFX_LINKFACTORY_H__8BBDE424_2729_426C_89EC_B3E3E1021F92__INCLUDED_)
#define AFX_LINKFACTORY_H__8BBDE424_2729_426C_89EC_B3E3E1021F92__INCLUDED_

 
//===========================================================================
// Summary:
//      To use a CLinkFactory object, just call the constructor.
//      Link Factory
//===========================================================================

class CLinkFactory
{

public:
// Implementation
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get I D, Returns the specified value.
	// This member function is a static function.
	//		Returns a CString type value.
	static CString GetID();

private:
// Private data
 
	// I D, This variable specifies a 32-bit signed integer on 32-bit platforms.  
	static int s_currentID;

};


#endif // !defined(AFX_LINKFACTORY_H__8BBDE424_2729_426C_89EC_B3E3E1021F92__INCLUDED_)
