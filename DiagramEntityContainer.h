#ifndef _DIAGRAMENTITYCONTAINER_H_
#define _DIAGRAMENTITYCONTAINER_H_
class CDiagramEntity;
#include "DiagramClipboardHandler.h"
#include "UndoItem.h"

 
//===========================================================================
// Summary:
//      To use a CDiagramEntityContainer object, just call the constructor.
//      Diagram Entity Container
//===========================================================================

class CDiagramEntityContainer {

public:

	// Construction/destruction/initialization
	
	//-----------------------------------------------------------------------
	// Summary:
	// Diagram Entity Container, Constructs a CDiagramEntityContainer object.
	//		Returns A  value.  
	// Parameters:
	//		clip---A pointer to the CDiagramClipboardHandler or NULL if the call failed.
	CDiagramEntityContainer( CDiagramClipboardHandler* clip = NULL );
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Diagram Entity Container, Destructor of class CDiagramEntityContainer
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CDiagramEntityContainer();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Remove the specify data from the list.

	void Clear();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get String, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CString type value.
	virtual CString	GetString() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// From String, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		str---Specifies A CString type value.
	virtual BOOL FromString( const CString& str );
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		stra---Specifies A CString type value.  
	//		format---Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	virtual void Export( CStringArray& stra, UINT format = 0 ) const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Clipboard Handler, Sets a specify value to current class CDiagramEntityContainer
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		clip---A pointer to the CDiagramClipboardHandler or NULL if the call failed.
	virtual void SetClipboardHandler( CDiagramClipboardHandler* clip );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Clipboard Handler, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CDiagramClipboardHandler,or NULL if the call failed
	virtual CDiagramClipboardHandler* GetClipboardHandler();

	// Data access
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get At, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CDiagramEntity,or NULL if the call failed  
	// Parameters:
	//		index---Specifies A integer value.
	virtual CDiagramEntity* GetAt( int index ) const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Data, Returns the specified value.
	//		Returns a pointer to the object CObArray,or NULL if the call failed
	CObArray*		GetData();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Size, Returns the specified value.
	//		Returns a int type value.
	int				GetSize() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Adds an object to the specify list.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		obj---A pointer to the CDiagramEntity or NULL if the call failed.
	virtual void	Add( CDiagramEntity* obj );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Remove At, Call this function to remove a specify value from the specify object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		index---Specifies A integer value.
	virtual void	RemoveAt( int index );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Remove All, Call this function to remove a specify value from the specify object.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void	RemoveAll();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Remove All Selected, Call this function to remove a specify value from the specify object.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void	RemoveAllSelected();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Call this function to remove a specify value from the specify object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		obj---A pointer to the CDiagramEntity or NULL if the call failed.
	virtual void	Remove( CDiagramEntity* obj );

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Virtual Size, Sets a specify value to current class CDiagramEntityContainer
	// Parameters:
	//		size---Specifies A CSize type value.
	void			SetVirtualSize( CSize size );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Virtual Size, Returns the specified value.
	//		Returns a CSize type value.
	CSize			GetVirtualSize() const;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Modified, Sets a specify value to current class CDiagramEntityContainer
	// Parameters:
	//		dirty---Specifies A Boolean value.
	void			SetModified( BOOL dirty );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Is Modified, Determines if the given value is correct or exist.
	//		Returns TRUE on success; FALSE otherwise.
	BOOL			IsModified() const;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Select All, Call this function to select the given item.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void	SelectAll();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Unselect All, None Description.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void	UnselectAll();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Select Count, Returns the specified value.
	//		Returns a int type value.
	int				GetSelectCount() const;

	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	// This member function is also a virtual function, you can Override it if you need,
	// Undo handling
	virtual void	Undo();
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void	Snapshot();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Is Undo Possible, Determines if the given value is correct or exist.
	//		Returns TRUE on success; FALSE otherwise.
	BOOL			IsUndoPossible();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Clear Undo, Remove the specify data from the list.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void	ClearUndo();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Undo Stack Size, Sets a specify value to current class CDiagramEntityContainer
	// Parameters:
	//		maxstacksize---Specifies A integer value.
	void			SetUndoStackSize( int maxstacksize );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Undo Stack Size, Returns the specified value.
	//		Returns a int type value.
	int				GetUndoStackSize() const;

	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	// This member function is also a virtual function, you can Override it if you need,
	// Group handling
	virtual void	Group();
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void	Ungroup();

	// Single object handlers
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		obj---A pointer to the CDiagramEntity or NULL if the call failed.
	virtual void			Duplicate( CDiagramEntity* obj );
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		obj---A pointer to the CDiagramEntity or NULL if the call failed.
	virtual void			Cut( CDiagramEntity* obj );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Create a duplicate copy of this object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		obj---A pointer to the CDiagramEntity or NULL if the call failed.
	virtual void			Copy( CDiagramEntity* obj );
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		obj---A pointer to the CDiagramEntity or NULL if the call failed.
	virtual void			Up( CDiagramEntity* obj );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		obj---A pointer to the CDiagramEntity or NULL if the call failed.
	virtual void			Down( CDiagramEntity* obj );
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		obj---A pointer to the CDiagramEntity or NULL if the call failed.
	virtual void			Front( CDiagramEntity* obj );
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		obj---A pointer to the CDiagramEntity or NULL if the call failed.
	virtual void			Bottom( CDiagramEntity* obj );
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void			Paste();

	// Copy/paste
	
	//-----------------------------------------------------------------------
	// Summary:
	// Copy All Selected, Create a duplicate copy of this object.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void			CopyAllSelected();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Objects In Paste, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a int type value.
	virtual int				ObjectsInPaste();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Clear Paste, Remove the specify data from the list.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void			ClearPaste();

	// Message handling
	
	//-----------------------------------------------------------------------
	// Summary:
	// Send Message To Objects, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		command---Specifies A integer value.  
	//		selected---Specifies A Boolean value.  
	//		sender---A pointer to the CDiagramEntity or NULL if the call failed.  
	//		from---A pointer to the CWnd or NULL if the call failed.
	virtual void			SendMessageToObjects( int command, BOOL selected = TRUE, CDiagramEntity* sender = NULL, CWnd* from = NULL );

	// Positional information
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Total Size, Returns the specified value.
	//		Returns a CSize type value.
	CSize					GetTotalSize();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Start Point, Returns the specified value.
	//		Returns a CPoint type value.
	CPoint					GetStartPoint();

protected:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Paste, Returns the specified value.
	//		Returns a pointer to the object CObArray,or NULL if the call failed
	CObArray*				GetPaste();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Undo, Returns the specified value.
	//		Returns a pointer to the object CObArray,or NULL if the call failed
	CObArray*				GetUndo();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Searches the list sequentially to find the first CObject pointer matching the specified CObject pointer. 
	//		Returns a int type value.  
	// Parameters:
	//		obj---A pointer to the CDiagramEntity or NULL if the call failed.
	int						Find( CDiagramEntity* obj );

private:

	// Data
 
	// This member specify CObArray object.  
	CObArray		m_objs;
 
	// This member specify CObArray object.  
	CObArray		m_undo;
 
	// This variable specifies a 32-bit signed integer on 32-bit platforms.  
	int				m_maxstacksize;
 
	// Size, This member sets a CSize value.  
	CSize			m_virtualSize;

 
	// This member maintains a pointer to the object CDiagramClipboardHandler.  
	CDiagramClipboardHandler*	m_clip;
 
	// Clip, This member specify CDiagramClipboardHandler object.  
	CDiagramClipboardHandler	m_internalClip;

	// State
 
	// This member sets TRUE if it is right.  
	BOOL			m_dirty;

	// Helpers
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	// Parameters:
	//		index1---Specifies A integer value.  
	//		index2---Specifies A integer value.
	void			Swap( int index1, int index2 );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set At, Sets a specify value to current class CDiagramEntityContainer
	// Parameters:
	//		index---Specifies A integer value.  
	//		obj---A pointer to the CDiagramEntity or NULL if the call failed.
	void			SetAt( int index, CDiagramEntity* obj );

};

#endif // _DIAGRAMENTITYCONTAINER_H_
