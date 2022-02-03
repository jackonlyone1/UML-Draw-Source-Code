#ifndef _CUNDOITEM_H_D0245507_FE15_4E26_9C3FCD56AE91
#define _CUNDOITEM_H_D0245507_FE15_4E26_9C3FCD56AE91

 
//===========================================================================
// Summary:
//     The CUndoItem class derived from CObject
//      Undo Item
//===========================================================================

class CUndoItem : public CObject 
{

public:
	// Construction/destruction
	
	//-----------------------------------------------------------------------
	// Summary:
	// Undo Item, Constructs a CUndoItem object.
	//		Returns A  value.
	CUndoItem();
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Undo Item, Destructor of class CUndoItem
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CUndoItem();

	// Public data
 
	// This member specify CObArray object.  
	CObArray	arr;	// Object array
 
	// This variable specifies a 32-bit signed integer on 32-bit platforms.  
	CPoint		pt;		// Virtual editor size

};

#endif //_CUNDOITEM_H_D0245507_FE15_4E26_9C3FCD56AE91
