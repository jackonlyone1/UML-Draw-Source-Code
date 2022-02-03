#ifndef _DIAGRAMENTITY_H_
#define _DIAGRAMENTITY_H_

#include "DiagramPropertyDlg.h"

#define CMD_START			100
#define CMD_CUT				100
#define CMD_COPY			101
#define CMD_DUPLICATE		102
#define CMD_PROPERTIES		103
#define CMD_UP				104
#define CMD_DOWN			105
#define CMD_FRONT			106
#define CMD_BOTTOM			107
#define CMD_SELECT_GROUP	108
#define CMD_END				200

#define DEHT_NONE				0
#define DEHT_BODY				1
#define DEHT_TOPLEFT			2
#define DEHT_TOPMIDDLE			3
#define DEHT_TOPRIGHT			4
#define DEHT_BOTTOMLEFT			5
#define DEHT_BOTTOMMIDDLE		6
#define DEHT_BOTTOMRIGHT		7
#define DEHT_LEFTMIDDLE			8
#define DEHT_RIGHTMIDDLE		9

#define round(a) ( int ) ( a + .5 )

class CDiagramEntityContainer;
class CDiagramPropertyDlg;

 
//===========================================================================
// Summary:
//     The CDiagramEntity class derived from CObject
//      Diagram Entity
//===========================================================================

class CDiagramEntity : public CObject
{

 
	// Diagram Entity Container, This member specify friend class object.  
friend class CDiagramEntityContainer;

public:

	// Creation/initialization
	
	//-----------------------------------------------------------------------
	// Summary:
	// Diagram Entity, Constructs a CDiagramEntity object.
	//		Returns A  value.
	CDiagramEntity();
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Diagram Entity, Destructor of class CDiagramEntity
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CDiagramEntity();

protected:

	
	//-----------------------------------------------------------------------
	// Summary:
	// Remove the specify data from the list.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void	Clear();

public:

	
	//-----------------------------------------------------------------------
	// Summary:
	// Clone this object.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CDiagramEntity,or NULL if the call failed
	virtual	CDiagramEntity* Clone();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Create a duplicate copy of this object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		obj---A pointer to the CDiagramEntity or NULL if the call failed.
	virtual void	Copy( CDiagramEntity* obj );

	
	//-----------------------------------------------------------------------
	// Summary:
	// From String, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		str---Specifies A CString type value.
	virtual BOOL	FromString( const CString& str );
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CString type value.  
	// Parameters:
	//		format---Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	virtual CString	Export( UINT format = 0 ) const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get String, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CString type value.
	virtual CString	GetString() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Create From String, You construct a CDiagramEntity object in two steps. First call the constructor, then call Create, which creates the object.
	// This member function is a static function.
	//		Returns a pointer to the object CDiagramEntity,or NULL if the call failed  
	// Parameters:
	//		str---Specifies A CString type value.
	static	CDiagramEntity* CreateFromString( const CString& str );

	// Object rectangle handling
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Rectangle, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CRect type value.
	virtual CRect	GetRect() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Rectangle, Sets a specify value to current class CDiagramEntity
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		rect---Specifies A CRect type value.
	virtual void	SetRect( CRect rect );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Rectangle, Sets a specify value to current class CDiagramEntity
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		left---Specifies a double left object.  
	//		top---Specifies a double top object.  
	//		right---Specifies a double right object.  
	//		bottom---Specifies a double bottom object.
	virtual void	SetRect( double left, double top, double right, double bottom );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Move Rectangle, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		x---Specifies a double x object.  
	//		y---Specifies a double y object.
	virtual void	MoveRect( double x, double y );

	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Left, Returns the specified value.
	//		Returns A double value.
	double			GetLeft() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Right, Returns the specified value.
	//		Returns A double value.
	double			GetRight() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Top, Returns the specified value.
	//		Returns A double value.
	double			GetTop() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Bottom, Returns the specified value.
	//		Returns A double value.
	double			GetBottom() const;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Left, Sets a specify value to current class CDiagramEntity
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		left---Specifies a double left object.
	virtual void	SetLeft( double left );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Right, Sets a specify value to current class CDiagramEntity
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		right---Specifies a double right object.
	virtual void	SetRight( double right );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Top, Sets a specify value to current class CDiagramEntity
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		top---Specifies a double top object.
	virtual void	SetTop( double top );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Bottom, Sets a specify value to current class CDiagramEntity
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		bottom---Specifies a double bottom object.
	virtual void	SetBottom( double bottom );

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Minimum Size, Sets a specify value to current class CDiagramEntity
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		minimumSize---Size, Specifies A CSize type value.
	virtual void	SetMinimumSize( CSize minimumSize );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Minimum Size, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CSize type value.
	virtual CSize	GetMinimumSize() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Maximum Size, Sets a specify value to current class CDiagramEntity
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		minimumSize---Size, Specifies A CSize type value.
	virtual void	SetMaximumSize( CSize minimumSize );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Maximum Size, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CSize type value.
	virtual CSize	GetMaximumSize() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Constraints, Sets a specify value to current class CDiagramEntity
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		min---Specifies A CSize type value.  
	//		max---Specifies A CSize type value.
	virtual void	SetConstraints( CSize min, CSize max );

	
	//-----------------------------------------------------------------------
	// Summary:
	// Call this function to select the given item.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		selected---Specifies A Boolean value.
	// Selection handling
	virtual void	Select( BOOL selected );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Is Selected, Determines if the given value is correct or exist.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
	virtual BOOL	IsSelected() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Body In Rectangle, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		rect---Specifies A CRect type value.
	virtual BOOL	BodyInRect( CRect rect ) const;

	// Interaction
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Hit Code, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a int type value.  
	// Parameters:
	//		point---Specifies A CPoint type value.
	virtual int		GetHitCode( CPoint point ) const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Hit Code, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a int type value.  
	// Parameters:
	//		point---Specifies A CPoint type value.  
	//		rect---Specifies A CRect type value.
	virtual int		GetHitCode( const CPoint& point, const CRect& rect ) const;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Message, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		msg---Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		sender---A pointer to the CDiagramEntity or NULL if the call failed.  
	//		from---A pointer to the CWnd or NULL if the call failed.
	virtual BOOL	DoMessage( UINT msg, CDiagramEntity* sender, CWnd* from = NULL );

	// Auxilliary
	
	//-----------------------------------------------------------------------
	// Summary:
	// Show Properties, Call this function to show the specify object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		parent---A pointer to the CWnd or NULL if the call failed.  
	//		show---Specifies A Boolean value.
	virtual void	ShowProperties( CWnd* parent, BOOL show = TRUE );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Show Popup, Call this function to show the specify object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		point---Specifies A CPoint type value.  
	//		parent---A pointer to the CWnd or NULL if the call failed.
	virtual void	ShowPopup( CPoint point, CWnd* parent );

	// Visuals
	
	//-----------------------------------------------------------------------
	// Summary:
	// Draws current object to the specify device.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		dc---A pointer to the CDC or NULL if the call failed.  
	//		rect---Specifies A CRect type value.
	virtual void	Draw( CDC* dc, CRect rect );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Cursor, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A HCURSOR value.  
	// Parameters:
	//		hit---Specifies A integer value.
	virtual HCURSOR GetCursor( int hit ) const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Draw Object, Draws current object to the specify device.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		dc---A pointer to the CDC or NULL if the call failed.  
	//		zoom---Specifies a double zoom object.
	virtual void	DrawObject( CDC* dc, double zoom );

	// Properties
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Title, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CString type value.
	virtual CString	GetTitle() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Title, Sets a specify value to current class CDiagramEntity
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		title---Specifies A CString type value.
	virtual void	SetTitle( CString title );

	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Name, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CString type value.
	virtual CString	GetName() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Name, Sets a specify value to current class CDiagramEntity
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		name---Specifies A CString type value.
	virtual void	SetName( CString name );

	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Type, Returns the specified value.
	//		Returns a CString type value.
	CString			GetType() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Type, Sets a specify value to current class CDiagramEntity
	// Parameters:
	//		type---Specifies A CString type value.
	void			SetType( CString type );

	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Group, Returns the specified value.
	//		Returns a int type value.
	int				GetGroup() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Group, Sets a specify value to current class CDiagramEntity
	// Parameters:
	//		group---Specifies A integer value.
	void			SetGroup( int group );

	
	//-----------------------------------------------------------------------
	// Summary:
	// Load From String, Call this function to read a specified number of bytes from the archive.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		data---Specifies A CString type value.
	BOOL			LoadFromString( CString& data );

	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Font, Returns the specified value.
	//		Returns a CString type value.
	CString			GetFont() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Font, Sets a specify value to current class CDiagramEntity
	// Parameters:
	//		fontName---Name, Specifies A CString type value.
	void			SetFont( const CString& fontName );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Font Size, Returns the specified value.
	//		Returns a int type value.
	int				GetFontSize() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Font Size, Sets a specify value to current class CDiagramEntity
	// Parameters:
	//		nFontSize---Font Size, Specifies A integer value.
	void			SetFontSize( const int& nFontSize );

protected:

	// Selection
	
	//-----------------------------------------------------------------------
	// Summary:
	// Draw Selection Markers, Draws current object to the specify device.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		dc---A pointer to the CDC or NULL if the call failed.  
	//		rect---Specifies A CRect type value.
	virtual void	DrawSelectionMarkers( CDC* dc, CRect rect ) const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Selection Marker Rectangle, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CRect type value.  
	// Parameters:
	//		marker---Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		rect---Specifies A CRect type value.
	virtual CRect	GetSelectionMarkerRect( UINT marker, CRect rect ) const;

	// Visuals
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Font, Returns the specified value.
	// Parameters:
	//		lf---Specifies a LOGFONT& lf object.
	void			GetFont( LOGFONT& lf ) const;

	// Properties
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Marker Size, Sets a specify value to current class CDiagramEntity
	// Parameters:
	//		markerSize---Size, Specifies A CSize type value.
	void			SetMarkerSize( CSize markerSize );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Marker Size, Returns the specified value.
	//		Returns a CSize type value.
	CSize			GetMarkerSize() const;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Parent, Sets a specify value to current class CDiagramEntity
	// Parameters:
	//		parent---A pointer to the CDiagramEntityContainer or NULL if the call failed.
	void						SetParent( CDiagramEntityContainer* parent );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Parent, Returns the specified value.
	//		Returns a pointer to the object CDiagramEntityContainer,or NULL if the call failed
	CDiagramEntityContainer*	GetParent() const;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Property Dialog, Sets a specify value to current class CDiagramEntity
	// Parameters:
	//		dlg---A pointer to the CDiagramPropertyDlg or NULL if the call failed.  
	//		resid---Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	void						SetPropertyDialog( CDiagramPropertyDlg* dlg, UINT resid );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Property Dialog, Returns the specified property value.
	//		Returns a pointer to the object CDiagramPropertyDlg,or NULL if the call failed
	CDiagramPropertyDlg*		GetPropertyDialog() const;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Default Get String, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CString type value.
	virtual CString				GetDefaultGetString() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Header From String, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CString type value.  
	// Parameters:
	//		str---Specifies A CString type value.
	virtual CString				GetHeaderFromString( CString& str );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Default From String, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		str---Specifies A CString type value.
	virtual BOOL				GetDefaultFromString( CString& str );

private:

	// Position
 
	// This member specify double object.  
	double	m_left;
 
	// This member specify double object.  
	double	m_right;
 
	// This member specify double object.  
	double	m_top;
 
	// This member specify double object.  
	double	m_bottom;

	// Sizes
 
	// Size, This member sets a CSize value.  
	CSize	m_markerSize;
 
	// Size, This member sets a CSize value.  
	CSize	m_minimumSize;
 
	// Size, This member sets a CSize value.  
	CSize	m_maximumSize;

	// States
 
	// This member specify double object.  
	double	m_zoom;
 
	// This member sets TRUE if it is right.  
	BOOL	m_selected;

	// Data
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString m_type;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString m_title;
 
	// You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString m_name;

 
	// This variable specifies a 32-bit signed integer on 32-bit platforms.  
	int		m_group;

 
	// This member maintains a pointer to the object CDiagramPropertyDlg.  
	CDiagramPropertyDlg*		m_propertydlg;
 
	// This member can be sets with A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	UINT						m_propertydlgresid;

 
	// This member maintains a pointer to the object CDiagramEntityContainer.  
	CDiagramEntityContainer*	m_parent;

 
	// Name, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString			m_fontName;
 
	// Font Size, This variable specifies a 32-bit signed integer on 32-bit platforms.  
	int				m_nFontSize;
};

#endif // _DIAGRAMENTITY_H_
