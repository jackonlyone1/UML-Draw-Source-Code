#ifndef _DIAGRAMCLIPBOARDHANDLER_H_
#define _DIAGRAMCLIPBOARDHANDLER_H_

#include "DiagramEntity.h"

 
//===========================================================================
// Summary:
//      To use a CDiagramClipboardHandler object, just call the constructor.
//      Diagram Clipboard Handler
//===========================================================================

class CDiagramClipboardHandler {

public:
// Construction/initialization/destruction
	
	//-----------------------------------------------------------------------
	// Summary:
	// Diagram Clipboard Handler, Constructs a CDiagramClipboardHandler object.
	//		Returns A  value.
	CDiagramClipboardHandler();
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Diagram Clipboard Handler, Destructor of class CDiagramClipboardHandler
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CDiagramClipboardHandler();

// Implementation
	
	//-----------------------------------------------------------------------
	// Summary:
	// Create a duplicate copy of this object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		obj---A pointer to the CDiagramEntity or NULL if the call failed.
	virtual void	Copy( CDiagramEntity* obj );
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		container---A pointer to the CDiagramEntityContainer or NULL if the call failed.
	virtual void	Paste( CDiagramEntityContainer* container );

	
	//-----------------------------------------------------------------------
	// Summary:
	// Copy All Selected, Create a duplicate copy of this object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		container---A pointer to the CDiagramEntityContainer or NULL if the call failed.
	virtual void	CopyAllSelected( CDiagramEntityContainer* container );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Objects In Paste, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a int type value.
	virtual int		ObjectsInPaste();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Clear Paste, Remove the specify data from the list.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void	ClearPaste();

	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Data, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CObArray,or NULL if the call failed
	virtual CObArray* GetData();

private:
// Private data
 
	// This member specify CObArray object.  
	CObArray		m_paste;

};

#endif // _DIAGRAMCLIPBOARDHANDLER_H_
