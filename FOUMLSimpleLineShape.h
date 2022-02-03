#if !defined(FO_FOUMLSIMPLELINESHAPE_H__EDB97901_A11C_4626_8106_9A5991187250__INCLUDED_)
#define FO_FOUMLSIMPLELINESHAPE_H__EDB97901_A11C_4626_8106_9A5991187250__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//------------------------------------------------------
// Description
// Author: Author Name.
//------------------------------------------------------

#define ID_FOP_SAMPLE_SIMPLE_LINE		FO_COMP_CUSTOM+18

 
//===========================================================================
// Summary:
//     The CFOUMLSimpleLineShape class derived from CFOTurnCornerLinkShape
//      F O U M L Simple Line Shape
//===========================================================================

class CFOUMLSimpleLineShape : public CFOTurnCornerLinkShape  
{
protected:
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ S E R I A L, None Description.
	//		Returns A  value.  
	// Parameters:
	//		CFOUMLSimpleLineShape---F O U M L Simple Line Shape, Specifies a E-XD++ CFOUMLSimpleLineShape object.
	DECLARE_SERIAL(CFOUMLSimpleLineShape);
public:

	// constructor
	
	//-----------------------------------------------------------------------
	// Summary:
	// F O U M L Simple Line Shape, Constructs a CFOUMLSimpleLineShape object.
	//		Returns A  value.
	CFOUMLSimpleLineShape();

	// Copy constructor.
	
	//-----------------------------------------------------------------------
	// Summary:
	// F O U M L Simple Line Shape, Constructs a CFOUMLSimpleLineShape object.
	//		Returns A  value.  
	// Parameters:
	//		src---Specifies a const CFOUMLSimpleLineShape& src object.
	CFOUMLSimpleLineShape(const CFOUMLSimpleLineShape& src);

	// Destructor.
	
	//-----------------------------------------------------------------------
	// Summary:
	// C F O U M L Simple Line Shape, Destructor of class CFOUMLSimpleLineShape
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CFOUMLSimpleLineShape();

	
	//-----------------------------------------------------------------------
	// Summary:
	// You construct a CFOUMLSimpleLineShape object in two steps. First call the constructor, then call Create, which creates the object.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		CArray<CPoint---Array< C Point, Specifies A array.  
	//		ptArray---Array, A pointer to the CPoint> or NULL if the call failed.  
	//		*pFrom---From, A pointer to the CFOPortShape  or NULL if the call failed.  
	//		*pTo---To, A pointer to the CFOPortShape  or NULL if the call failed.
	// Create the link shape from a CRect object.
	BOOL Create(CArray<CPoint,CPoint>* ptArray,CFOPortShape *pFrom = NULL,CFOPortShape *pTo = NULL);
	
	
	//-----------------------------------------------------------------------
	// Summary:
	// You construct a CFOUMLSimpleLineShape object in two steps. First call the constructor, then call Create, which creates the object.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		pptPoints---Points, Specifies A Points array.  
	//		nCount---Count, Specifies A integer value.  
	//		*pFrom---From, A pointer to the CFOPortShape  or NULL if the call failed.  
	//		*pTo---To, A pointer to the CFOPortShape  or NULL if the call failed.
	// .Create
	BOOL Create(LPPOINT pptPoints, int nCount,CFOPortShape *pFrom = NULL,CFOPortShape *pTo = NULL);

public:

	// Assignment operator.
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	//		Returns A E-XD++ CFOUMLSimpleLineShape& value.  
	// Parameters:
	//		src---Specifies a const CFOUMLSimpleLineShape& src object.
	CFOUMLSimpleLineShape& operator=(const CFOUMLSimpleLineShape& src);

	
	//-----------------------------------------------------------------------
	// Summary:
	// Create a duplicate copy of this object.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CFODrawShape,or NULL if the call failed
	// Creates a copy of this shape.
	virtual CFODrawShape* Copy() const;

	//Generate Shape Area
	
	//-----------------------------------------------------------------------
	// Summary:
	// Geometry Updated, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pRgn---Rgn, A pointer to the CFOArea or NULL if the call failed.
	virtual void GeometryUpdated(CFOArea* pRgn);

	// Calc the label start position.
	// pDC -- pointer of the DC.
	// bFullSize -- using full size or not.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Calculate Label Position, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CRect type value.  
	// Parameters:
	//		*pDC---D C, A pointer to the CDC  or NULL if the call failed.  
	//		&bFullSize---Full Size, Specifies A Boolean value.
	virtual CRect CalcLabelPosition(CDC *pDC,BOOL &bFullSize) const;

	// Re calc extend bound rectangle.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Calculate Extend Bound Rectangle, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		&rcBound---Bound, Specifies A CRect type value.
	virtual void CalcExtendBoundRect(CRect &rcBound) const;

	// Relayout points.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Relayout Points, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
	virtual BOOL RelayoutPoints();

	// Relayout track state points
	
	//-----------------------------------------------------------------------
	// Summary:
	// Relayout Track Points, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.
	virtual BOOL RelayoutTrackPoints();

	// Obtain the composite of the shape.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Path Simple Polygon, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		rPoly---Polygon, Specifies a FOPSimpleCompositePolygon& rPoly object.
	virtual void GetPathSimplePolygon(FOPSimpleCompositePolygon& rPoly) const;

public:

	
	//-----------------------------------------------------------------------
	// Summary:
	// Reads or writes this object from or to an archive.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		&ar---Specifies a CArchive &ar object.
	// Serializes the data.
	virtual void Serialize(CArchive &ar);
	
	// Save document.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Save Document, Call this function to save the specify data to a file.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		lpszPathName---Path Name, Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.
	virtual BOOL SaveDocument(LPCTSTR lpszPathName);

	// Open document.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Open Document, Open document from specify file.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		lpszPathName---Path Name, Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.
	virtual BOOL OpenDocument(LPCTSTR lpszPathName);
	
	// Get file.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get File, Returns the specified value.
	//		Returns a pointer to the object CFile ,or NULL if the call failed  
	// Parameters:
	//		lpszFileName---File Name, Specifies A 32-bit pointer to a constant character string that is portable for Unicode and DBCS.  
	//		nOpenFlags---Open Flags, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.  
	//		pError---Error, A pointer to the CFileException or NULL if the call failed.
	CFile *GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,CFileException* pError);
	
	// Release file.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Release File, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pFile---File, A pointer to the CFile or NULL if the call failed.  
	//		bAbort---Abort, Specifies A Boolean value.
	virtual void ReleaseFile(CFile* pFile, BOOL bAbort);

public:

	//Draw flat status.

	// Draws custom tracker.
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Draw Track Custom, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pDC---D C, A pointer to the CDC  or NULL if the call failed.
	virtual void OnDrawTrackCustom(CDC *pDC);

	// Creates GDI objects and sets up the device context for drawing. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// Prepare D C, Creates GDI objects and sets up the device context for drawing.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.
	virtual void PrepareDC(CDC* pDC);

	// Draws the flat status of the shape.
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Draw Flat, Draws the flat status of the shape.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pDC---D C, A pointer to the CDC  or NULL if the call failed.
	virtual void OnDrawFlat(CDC *pDC);

	// Do draw visio like bounding selection line.
	// pDC -- pointer of the DC.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Draw Microsoft Visio style Order Line, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pDC---D C, A pointer to the CDC  or NULL if the call failed.
	virtual void DoDrawVisioOrderLine(CDC *pDC);

	// Draws shadow of shape.
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Draw Shadow, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pDC---D C, A pointer to the CDC  or NULL if the call failed.
	virtual void OnDrawShadow(CDC *pDC);

	// Draws the 3D status of the shape.
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Draw3d, Draws the 3d status of the shape.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pDC---D C, A pointer to the CDC  or NULL if the call failed.
	virtual void OnDraw3d(CDC *pDC);

	// Frees GDI objects and restores the state of the device context.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Clear D C, Remove the specify data from the list.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.
	virtual void ClearDC(CDC* pDC);
	// Implementation

	// Build current line end object.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Build Line End Object, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		&nType---Type, Specifies A integer value.
	virtual void BuildLineEndObject(int &nType);

	// Build current line start object.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Build Line Start Object, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		&nType---Type, Specifies A integer value.
	virtual void BuildLineStartObject(int &nType);

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



#endif // !defined(FO_FOUMLSIMPLELINESHAPE_H__EDB97901_A11C_4626_8106_9A5991187250__INCLUDED_)
