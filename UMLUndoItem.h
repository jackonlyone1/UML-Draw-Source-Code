#ifndef _CUMLUNDOITEM_H_68A37D5B_34FC_40A6_8D1D2B9DEAFA

#define _CUMLUNDOITEM_H_68A37D5B_34FC_40A6_8D1D2B9DEAFA


#include "UndoItem.h"

 
//===========================================================================
// Summary:
//     The CUMLUndoItem class derived from CUndoItem
//      U M L Undo Item
//===========================================================================

class CUMLUndoItem : public CUndoItem
{
public:
	// Construction/destruction
	
	//-----------------------------------------------------------------------
	// Summary:
	// U M L Undo Item, Constructs a CUMLUndoItem object.
	//		Returns A  value.
	CUMLUndoItem();
	
	//-----------------------------------------------------------------------
	// Summary:
	// C U M L Undo Item, Destructor of class CUMLUndoItem
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CUMLUndoItem();

// Attributes
 
	// This member sets A 32-bit value used as a color value.  
	COLORREF col;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString package;

};

#endif //_CUMLUNDOITEM_H_68A37D5B_34FC_40A6_8D1D2B9DEAFA
