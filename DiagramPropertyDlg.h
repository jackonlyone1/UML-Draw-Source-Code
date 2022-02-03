#ifndef _DIAGRAMPROPERTYDLG_H_
#define _DIAGRAMPROPERTYDLG_H_

#include "DiagramEntity.h"

class CDiagramEntity;
 
//===========================================================================
// Summary:
//     The CDiagramPropertyDlg class derived from CDialog
//      Diagram Property Dialog
//===========================================================================

class CDiagramPropertyDlg : public CDialog
{

public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// Diagram Property Dialog, Constructs a CDiagramPropertyDlg object.
	//		Returns A  value.  
	// Parameters:
	//		res---Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		parent---A pointer to the CWnd or NULL if the call failed.
	CDiagramPropertyDlg( UINT res, CWnd* parent );
	
	//-----------------------------------------------------------------------
	// Summary:
	// You construct a CDiagramPropertyDlg object in two steps. First call the constructor, then call Create, which creates the object.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		nIDTemplate---I D Template, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		pParentWnd---Parent Window, A pointer to the CWnd or NULL if the call failed.
	BOOL Create( UINT nIDTemplate, CWnd* pParentWnd );

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Entity, Sets a specify value to current class CDiagramPropertyDlg
	// Parameters:
	//		entity---A pointer to the CDiagramEntity or NULL if the call failed.
	void			SetEntity( CDiagramEntity* entity );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Entity, Returns the specified value.
	//		Returns a pointer to the object CDiagramEntity,or NULL if the call failed
	CDiagramEntity*	GetEntity() const;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Redraw Window, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CWnd,or NULL if the call failed
	virtual CWnd*	GetRedrawWnd();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Redraw Window, Sets a specify value to current class CDiagramPropertyDlg
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		redrawWnd---Window, A pointer to the CWnd or NULL if the call failed.
	virtual void	SetRedrawWnd( CWnd* redrawWnd );
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void	Redraw();

	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Values, Sets a specify value to current class CDiagramPropertyDlg
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		)---Specifies a ) = 0 object.
	virtual void	SetValues() = 0;

private:
 
	// This member maintains a pointer to the object CDiagramEntity.  
	CDiagramEntity*	m_entity;
 
	// Window, The CWnd class provides the base functionality of all window classes in the Microsoft Foundation Class Library.  
	CWnd*			m_redrawWnd;

};

#endif // _DIAGRAMPROPERTYDLG_H_
