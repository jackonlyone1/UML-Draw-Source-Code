// FOUMLComplexLineShape.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "FOUMLComplexLineShape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// CFOUMLComplexLineShape Class
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CFOUMLComplexLineShape, CFORoundTurnCornerLinkShape, 0)
CFOUMLComplexLineShape::CFOUMLComplexLineShape()
{
	SetType(ID_FOP_SAMPLE_COMPLEX_LINE);
	SetLineWidth(2);
	SetEndArrowLength(24);
	SetEndArrowWidth(6);
	SetEndArrowType2(13);
	ShowLabelBorder(FALSE);
	SetPointSize(14);
}

CFOUMLComplexLineShape::CFOUMLComplexLineShape(const CFOUMLComplexLineShape& src)
{
	*this = src;
}

CFOUMLComplexLineShape::~CFOUMLComplexLineShape()
{

}

/////////////////////////////////////////////////////////////////////////////
// CFOUMLComplexLineShape diagnostics

#ifdef _DEBUG
void CFOUMLComplexLineShape::AssertValid() const
{
	CFORoundTurnCornerLinkShape::AssertValid();
}

void CFOUMLComplexLineShape::Dump(CDumpContext& dc) const
{
	CFORoundTurnCornerLinkShape::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
BOOL CFOUMLComplexLineShape::Create(CArray<CPoint,CPoint>* ptArray,CFOPortShape *pFrom,CFOPortShape *pTo)
{
	BOOL bReturn = CFORoundTurnCornerLinkShape::Create(ptArray,pFrom,pTo);

	// FODO: Add your own code here.

	return bReturn;
}

BOOL CFOUMLComplexLineShape::Create(LPPOINT pptPoints, int nCount,CFOPortShape *pFrom,CFOPortShape *pTo)
{
	BOOL bReturn = CFORoundTurnCornerLinkShape::Create(pptPoints,nCount,pFrom,pTo);

	// FODO: Add your own code here.

	return bReturn;
}

void CFOUMLComplexLineShape::Serialize(CArchive& ar)
{
	CFORoundTurnCornerLinkShape::Serialize(ar);
	if(ar.IsStoring())
	{
		//FODO:Add your own code here.

	}
	else
	{
		//FODO:Add your own code here.

	}
}

/////////////////////////////////////////////////////////////////////////////
// CPrintBaseJob serialization
CFile* CFOUMLComplexLineShape::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
								 CFileException* pError)
{
	CMirrorFile* pFile = new CMirrorFile;
	ASSERT(pFile != NULL);
	if (!pFile->Open(lpszFileName, nOpenFlags, pError))
	{
		delete pFile;
		pFile = NULL;
	}
	return pFile;
}

void CFOUMLComplexLineShape::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CFOUMLComplexLineShape::OpenDocument(LPCTSTR lpszPathName)
{
	
	CFileException fe;
	CFile* pFile = GetFile(lpszPathName,
		CFile::modeRead|CFile::shareDenyWrite, &fe);
	if (pFile == NULL)
	{
		return FALSE;
	}
	
	CArchive loadArchive(pFile, CArchive::load | CArchive::bNoFlushOnDelete);
	loadArchive.m_bForceFlat = FALSE;
	TRY
	{
		CWaitCursor wait;
		if (pFile->GetLength() != 0)
			Serialize(loadArchive);     // load me
		loadArchive.Close();
		ReleaseFile(pFile, FALSE);
	}
	CATCH_ALL(e)
	{
		ReleaseFile(pFile, TRUE);
		
		return FALSE;
	}
	END_CATCH_ALL
		
		
		return TRUE;
}

BOOL CFOUMLComplexLineShape::SaveDocument(LPCTSTR lpszPathName)
{
	
	CFileException fe;
	CFile* pFile = NULL;
	pFile = GetFile(lpszPathName, CFile::modeCreate |
		CFile::modeReadWrite | CFile::shareExclusive, &fe);
	
	if (pFile == NULL)
	{
		
		return FALSE;
	}
	
	CArchive saveArchive(pFile, CArchive::store | CArchive::bNoFlushOnDelete);
	saveArchive.m_bForceFlat = FALSE;
	TRY
	{
		CWaitCursor wait;
		Serialize(saveArchive);     // save me
		saveArchive.Close();
		ReleaseFile(pFile, FALSE);
	}
	CATCH_ALL(e)
	{
		ReleaseFile(pFile, TRUE);
		
		return FALSE;
	}
	END_CATCH_ALL
		
		
		return TRUE;        // success
}

CFOUMLComplexLineShape& CFOUMLComplexLineShape::operator=(const CFOUMLComplexLineShape& src)
{
	(*(CFORoundTurnCornerLinkShape*)this) = src;
	return (*this);
}

CFODrawShape* CFOUMLComplexLineShape::Copy() const
{
	return (new CFOUMLComplexLineShape(*this));
}

void CFOUMLComplexLineShape::GetPathSimplePolygon(FOPSimpleCompositePolygon& rPoly) const
{
	CFORoundTurnCornerLinkShape::GetPathSimplePolygon(rPoly);
}

CRect CFOUMLComplexLineShape::CalcLabelPosition(CDC *pDC,BOOL &bFullSize) const
{
	return CFORoundTurnCornerLinkShape::CalcLabelPosition(pDC,bFullSize);
}

void CFOUMLComplexLineShape::CalcExtendBoundRect(CRect &rcBound) const
{
	CFORoundTurnCornerLinkShape::CalcExtendBoundRect(rcBound);
	
}

void CFOUMLComplexLineShape::DoDrawVisioOrderLine(CDC *pDC)
{
	CFORoundTurnCornerLinkShape::DoDrawVisioOrderLine(pDC);
}

BOOL CFOUMLComplexLineShape::RelayoutPoints()
{
	return CFORoundTurnCornerLinkShape::RelayoutPoints();
}

BOOL CFOUMLComplexLineShape::RelayoutTrackPoints()
{
	return CFORoundTurnCornerLinkShape::RelayoutTrackPoints();
}

void CFOUMLComplexLineShape::PrepareDC(CDC* pDC)
{
	CFORoundTurnCornerLinkShape::PrepareDC(pDC);

	//FODO:Add your own code below.
	
}

void CFOUMLComplexLineShape::OnDrawTrackCustom(CDC *pDC)
{
	CFORoundTurnCornerLinkShape::OnDrawTrackCustom(pDC);

	// Add your own code here.

}

void CFOUMLComplexLineShape::OnDrawShadow(CDC *pDC)
{
	CFORoundTurnCornerLinkShape::OnDrawShadow(pDC);
	
	//FODO:Add your own code below.
	
}

void CFOUMLComplexLineShape::OnDrawFlat(CDC *pDC)
{
	CFORoundTurnCornerLinkShape::OnDrawFlat(pDC);

	//FODO:Add your own code below.
	
}

void CFOUMLComplexLineShape::OnDraw3d(CDC *pDC)
{
	CFORoundTurnCornerLinkShape::OnDraw3d(pDC);

	//FODO:Add your own code below.

}

void CFOUMLComplexLineShape::ClearDC(CDC* pDC)
{
	CFORoundTurnCornerLinkShape::ClearDC(pDC);

	//FODO:Add your own code below.

}

void CFOUMLComplexLineShape::GeometryUpdated(CFOArea* pRgn)
{
	CFORoundTurnCornerLinkShape::GeometryUpdated(pRgn);

	//FODO:Add your own code below.

}

void CFOUMLComplexLineShape::BuildLineStartObject(int &nType)
{
	CFORoundTurnCornerLinkShape::BuildLineStartObject(nType);

	//FODO:Add your own code below.

}

void CFOUMLComplexLineShape::BuildLineEndObject(int &nType)
{
	CFORoundTurnCornerLinkShape::BuildLineEndObject(nType);

	//FODO:Add your own code below.

}
