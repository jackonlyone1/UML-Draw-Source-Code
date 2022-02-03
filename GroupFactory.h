#ifndef _CGROUPFACTORY_H_8FD49C2_3274_4E7A_99A14A1CC60
#define _CGROUPFACTORY_H_8FD49C2_3274_4E7A_99A14A1CC60

 
//===========================================================================
// Summary:
//      To use a CGroupFactory object, just call the constructor.
//      Group Factory
//===========================================================================

class CGroupFactory
{
public:

public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get New Group, Returns the specified value.
	// This member function is a static function.
	//		Returns a int type value.
	static int GetNewGroup();

private:
 
	// Current Group, This variable specifies a 32-bit signed integer on 32-bit platforms.  
	static int m_sCurrentGroup;


};
#endif //_CGROUPFACTORY_H_8FD49C2_3274_4E7A_99A14A1CC60
