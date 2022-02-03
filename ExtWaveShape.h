#if !defined(FO_EXTWAVESHAPE_H__5AB7FA38_F32B_4C10_8B47_865CE9BE553B__INCLUDED_)
#define FO_EXTWAVESHAPE_H__5AB7FA38_F32B_4C10_8B47_865CE9BE553B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//------------------------------------------------------
// Description
// Author: Author Name.
//------------------------------------------------------

#define EXT_WAVE_SHAPE	FO_COMP_CUSTOM + 12
 
//===========================================================================
// Summary:
//     The CExtWaveShape class derived from CFODrawPortsShape
//      Extend Wave Shape
//===========================================================================

class CExtWaveShape : public CFODrawPortsShape  
{
protected:
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ S E R I A L, None Description.
	//		Returns A  value.  
	// Parameters:
	//		CExtWaveShape---Extend Wave Shape, Specifies a CExtWaveShape object.
	DECLARE_SERIAL(CExtWaveShape);
public:

	// constructor
	
	//-----------------------------------------------------------------------
	// Summary:
	// Extend Wave Shape, Constructs a CExtWaveShape object.
	//		Returns A  value.
	CExtWaveShape();

	// Copy constructor.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Extend Wave Shape, Constructs a CExtWaveShape object.
	//		Returns A  value.  
	// Parameters:
	//		src---Specifies a const CExtWaveShape& src object.
	CExtWaveShape(const CExtWaveShape& src);

	// Destructor.
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Extend Wave Shape, Destructor of class CExtWaveShape
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CExtWaveShape();

	
	//-----------------------------------------------------------------------
	// Summary:
	// You construct a CExtWaveShape object in two steps. First call the constructor, then call Create, which creates the object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		&rcPos---Position, Specifies A CRect type value.  
	//		strCaption---Caption, Specifies A CString type value.
	// Creates the button Shape from a CRect object.
	virtual void Create(CRect &rcPos,CString strCaption = "");

public:

	// Assignment operator.
	
	//-----------------------------------------------------------------------
	// Summary:
	// None Description.
	//		Returns A CExtWaveShape& value.  
	// Parameters:
	//		src---Specifies a const CExtWaveShape& src object.
	CExtWaveShape& operator=(const CExtWaveShape& src);

	
	//-----------------------------------------------------------------------
	// Summary:
	// Create a duplicate copy of this object.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a pointer to the object CFODrawShape,or NULL if the call failed
	// Creates a copy of this Shape.
	virtual CFODrawShape* Copy() const;

	// Update shape's area.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Geometry Updated, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pRgn---Rgn, A pointer to the CFOArea or NULL if the call failed.
	virtual void GeometryUpdated(CFOArea* pRgn);

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

	// Op.
	// Offset one point.
	// ptOffset -- offset value.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Offset Anchor Point, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		ptOffset---Offset, Specifies A CPoint type value.
	virtual BOOL		OffsetAnchorPoint(CPoint ptOffset);
	
	// Offset the current point.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Track Offset Anchor Point, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		ptOffset---Offset, Specifies A CPoint type value.
	virtual BOOL TrackOffsetAnchorPoint(CPoint ptOffset);

	// Op.
	// Offset one point.
	// ptOffset -- offset value.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Offset Extend Anchor Point, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		ptOffset---Offset, Specifies A CPoint type value.
	virtual BOOL		OffsetExtAnchorPoint(CPoint ptOffset);
	
	// Offset the current point.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Track Offset Extend Anchor Point, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		ptOffset---Offset, Specifies A CPoint type value.
	virtual BOOL TrackOffsetExtAnchorPoint(CPoint ptOffset);

	// Get plus spots
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Plus Spot Location, Returns the specified value.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		lstHandle---Handle, Specifies a E-XD++ CFOPHandleList& lstHandle object.
	virtual void GetPlusSpotLocation(CFOPHandleList& lstHandle);

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

	// Do draw visio like bounding selection line.
	// pDC -- pointer of the DC.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Draw Microsoft Visio style Order Line, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pDC---D C, A pointer to the CDC  or NULL if the call failed.
	virtual void DoDrawVisioOrderLine(CDC *pDC);

	// Creates GDI objects and sets up the device context for drawing. 
	
	//-----------------------------------------------------------------------
	// Summary:
	// Prepare D C, Creates GDI objects and sets up the device context for drawing.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		pDC---D C, A pointer to the CDC or NULL if the call failed.
	virtual void PrepareDC(CDC* pDC);

	// Draws the flat status of the Shape.
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Draw Flat, Draws the flat status of the shape.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pDC---D C, A pointer to the CDC  or NULL if the call failed.
	virtual void OnDrawFlat(CDC *pDC);

	// Draws shadow of Shape.
	
	//-----------------------------------------------------------------------
	// Summary:
	// On Draw Shadow, This member function is called by the framework to allow your application to handle a Windows message.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pDC---D C, A pointer to the CDC  or NULL if the call failed.
	virtual void OnDrawShadow(CDC *pDC);

	// Draws the 3D status of the Shape.
	
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



#endif // !defined(FO_EXTWAVESHAPE_H__5AB7FA38_F32B_4C10_8B47_865CE9BE553B__INCLUDED_)
