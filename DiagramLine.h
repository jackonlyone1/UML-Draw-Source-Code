#ifndef _DIAGRAMLINE_H_
#define _DIAGRAMLINE_H_

#include "DiagramEntity.h"

typedef struct {

	int x;
	int y;
	BOOL hit;

} hitParams;

typedef struct {

	CRect rect;
	BOOL hit;

} hitParamsRect;

 
//===========================================================================
// Summary:
//     The CDiagramLine class derived from CDiagramEntity
//      Diagram Line
//===========================================================================

class CDiagramLine : public CDiagramEntity
{
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Diagram Line, Constructs a CDiagramLine object.
	//		Returns A  value.
	CDiagramLine();
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Diagram Line, Destructor of class CDiagramLine
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CDiagramLine();

	
	//-----------------------------------------------------------------------
	// Summary:
	// Clone this object.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CDiagramEntity,or NULL if the call failed
	virtual CDiagramEntity* Clone();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Create From String, You construct a CDiagramLine object in two steps. First call the constructor, then call Create, which creates the object.
	// This member function is a static function.
	//		Returns a pointer to the object CDiagramEntity,or NULL if the call failed  
	// Parameters:
	//		str---Specifies A CString type value.
	static	CDiagramEntity* CreateFromString( const CString& str );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Draws current object to the specify device.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		dc---A pointer to the CDC or NULL if the call failed.  
	//		rect---Specifies A CRect type value.
	virtual void			Draw( CDC* dc, CRect rect );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Hit Code, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a int type value.  
	// Parameters:
	//		point---Specifies A CPoint type value.
	virtual int				GetHitCode( CPoint point ) const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Cursor, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A HCURSOR value.  
	// Parameters:
	//		hit---Specifies A integer value.
	virtual HCURSOR			GetCursor( int hit ) const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Rectangle, Sets a specify value to current class CDiagramLine
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		rect---Specifies A CRect type value.
	virtual void			SetRect( CRect rect );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Body In Rectangle, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		rect---Specifies A CRect type value.
	virtual BOOL			BodyInRect( CRect rect ) const;

protected:

	
	//-----------------------------------------------------------------------
	// Summary:
	// Draw Selection Markers, Draws current object to the specify device.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		dc---A pointer to the CDC or NULL if the call failed.  
	//		rect---Specifies A CRect type value.
	virtual void	DrawSelectionMarkers( CDC* dc, CRect rect ) const;
	
};

#endif // _DIAGRAMLINE_H_
