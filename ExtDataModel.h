#if !defined(AFX_EXTDATAMODEL_H__FE361D29_EA1B_4DF8_88E6_89543360A300__INCLUDED_)
#define AFX_EXTDATAMODEL_H__FE361D29_EA1B_4DF8_88E6_89543360A300__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExtDataModel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExtDataModel window

 
//===========================================================================
// Summary:
//     The CExtDataModel class derived from CFODataModel
//      Extend Data Model
//===========================================================================

class CExtDataModel : public CFODataModel
{
protected:
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ S E R I A L, None Description.
	//		Returns A  value.  
	// Parameters:
	//		CExtDataModel---Extend Data Model, Specifies a CExtDataModel object.
	DECLARE_SERIAL(CExtDataModel);

public:
	// Constructor.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Extend Data Model, Constructs a CExtDataModel object.
	//		Returns A  value.
	CExtDataModel();

	// Copy constructor. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// Extend Data Model, Constructs a CExtDataModel object.
	//		Returns A  value.  
	// Parameters:
	//		source---Specifies a const CExtDataModel& source object.
	CExtDataModel(const CExtDataModel& source);

	// Deconstructor.
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Extend Data Model, Destructor of class CExtDataModel
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CExtDataModel();

	
	//-----------------------------------------------------------------------
	// Summary:
	// Create a duplicate copy of this object.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CFODataModel,or NULL if the call failed
	// Create a duplicate copy of this object. 
	virtual CFODataModel* Copy() const;

	// Assignment operator.
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	//		Returns A CExtDataModel& value.  
	// Parameters:
	//		source---Specifies a const CExtDataModel& source object.
	CExtDataModel& operator=(const CExtDataModel& source);

public:

	// Init model data.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Initial Data, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,
	virtual void DoInitData();

	// Call before create shape new shape.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Initial Create Shape, Call before create shape new shape,this method will be called after each new shape is created, You can override this method to do something before shape created.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pShape---Shape, A pointer to the CFODrawShape  or NULL if the call failed.
	virtual void DoInitCreateShape(CFODrawShape *pShape);

	// Set modified flag.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Modified Flag, Sets a specify value to current class CExtDataModel
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		bModified---Modified, Specifies A Boolean value.
	virtual void SetModifiedFlag(BOOL bModified = TRUE);

	// Is modified.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Is Modified, Determines if the given value is correct or exist.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
	virtual BOOL IsModified();

	// Notify observer wnd.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Notify Observer, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		lHint---Hint, Specifies A lparam value.  
	//		CObject*pHint---Object*p Hint, A pointer to the CObject or NULL if the call failed.
	virtual void NotifyObserver(LPARAM lHint, CObject*pHint = NULL);

	// Update Title
	
	//-----------------------------------------------------------------------
	// Summary:
	// Update Title, Call this member function to update the object.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void UpdateTitle();

	// Do action change.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Action Change, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pAction---Action, A pointer to the const CFOBaseAction or NULL if the call failed.
	virtual void DoActionChange(const CFOBaseAction* pAction);

	// Do create a new shape.
	// m_drawshape -- Shape Type id start from FO_COMP_CUSTOM
	// rcCreate -- init position of shape.
	// strFileName -- if being image shape,this is the image file name.
	// pCurItem -- if being drag and drop from toolbox,this is the pointer of current toolbox item.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Create Shape By Type, Do create a new shape,override this method to add your own custom shape creating.See sample UserDefine shows.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CFODrawShape ,or NULL if the call failed  
	// Parameters:
	//		m_drawshape---Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		&rcCreate---Create, Specifies A CRect type value.  
	//		strFileName---File Name, Specifies A CString type value.  
	//		*pCurItem---Cur Item, A pointer to the CFOToolBoxItem  or NULL if the call failed.
	virtual CFODrawShape *DoCreateShapeByType(UINT m_drawshape,CRect &rcCreate,CString strFileName = _T(""),CFOToolBoxItem *pCurItem = NULL);

	// Do create a new shape shape.
	// m_drawshape -- Shape Type id start from FO_COMP_CUSTOM
	// rcCreate -- init position of shape.
	// strFileName -- if being image shape,this is the image file name.
	// pCurItem -- if being drag and drop from toolbox,this is the pointer of current toolbox item.
	virtual CFOCompositeShape *DoCreateCompositeShapeByType(UINT m_drawshape,CRect &rcCreate,
		CArray<FOPORTVALUE,FOPORTVALUE> *arInitPorts,
		CString strFileName = _T(""),
		UINT nResID = 0,
		CFOToolBoxItem *pCurItem = NULL);

	// Draw shape.
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Draw Shape, Draw all the shapes on the canvas to device.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pDC---D C, A pointer to the CDC  or NULL if the call failed.  
	//		&rcView---View, Specifies A CRect type value.
	virtual void OnDrawShape(CDC *pDC,const CRect &rcView);

	// Draw Back ground.
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Draw Back, Draw the background of this canvas.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pDC---D C, A pointer to the CDC  or NULL if the call failed.  
	//		&rcClip---Clip, Specifies A CRect type value.
	virtual void OnDrawBack(CDC *pDC,const CRect &rcClip);

	// Get Unique Name
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Unique Name, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CString type value.  
	// Parameters:
	//		nType---Type, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	virtual CString GetUniqueName(UINT nType);

	// Get Unique Caption
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Unique Caption, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CString type value.  
	// Parameters:
	//		nType---Type, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	virtual CString GetUniqueCaption(UINT nType);

	// Get base shape name.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Create Base Name, You construct a CExtDataModel object in two steps. First call the constructor, then call Create, which creates the object.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CString type value.  
	// Parameters:
	//		nType---Type, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	virtual CString CreateBaseName(UINT nType);

	// Get base shape caption.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Create Base Caption, You construct a CExtDataModel object in two steps. First call the constructor, then call Create, which creates the object.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CString type value.  
	// Parameters:
	//		nType---Type, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	virtual CString CreateBaseCaption(UINT nType);

public:

	
	//-----------------------------------------------------------------------
	// Summary:
	// Reads or writes this object from or to an archive.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		&ar---Specifies a CArchive &ar object.
	// Serialize data to file.
	virtual void Serialize(CArchive &ar);

	// Save Document to a specify file.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Save Document, Call this function to save the specify data to a file.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		lpszPathName---Path Name, Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.
	virtual BOOL SaveDocument(LPCTSTR lpszPathName);

	// Open Document from a specify file.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Open Document, Open document from specify file.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		lpszPathName---Path Name, Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.
	virtual BOOL OpenDocument(LPCTSTR lpszPathName);

	// Get the pointer of File.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get File, Returns the specified value.
	//		Returns a pointer to the object CFile ,or NULL if the call failed  
	// Parameters:
	//		lpszFileName---File Name, Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.  
	//		nOpenFlags---Open Flags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		pError---Error, A pointer to the CFileException or NULL if the call failed.
	CFile *		 GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,CFileException* pError);

	// Release File from memory.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Release File, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pFile---File, A pointer to the CFile or NULL if the call failed.  
	//		bAbort---Abort, Specifies A Boolean value.
	virtual void ReleaseFile(CFile* pFile, BOOL bAbort);

// Implementation
public:

#ifdef _DEBUG
	
	//-----------------------------------------------------------------------
	// Summary:
	// Assert Valid, Assert performs a validity check on this object by checking its internal state.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void AssertValid() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Dumps the contents of your object to a CDumpContext object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		dc---Specifies a CDumpContext& dc object.
	virtual void Dump(CDumpContext& dc) const;
#endif

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXTDATAMODEL_H__FE361D29_EA1B_4DF8_88E6_89543360A300__INCLUDED_)
