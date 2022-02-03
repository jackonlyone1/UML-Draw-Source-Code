// FOUMLSimpleLineShape.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "FOUMLSimpleLineShape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// CFOUMLSimpleLineShape Class
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CFOUMLSimpleLineShape, CFOTurnCornerLinkShape, 0)
CFOUMLSimpleLineShape::CFOUMLSimpleLineShape()
{
	SetType(ID_FOP_SAMPLE_SIMPLE_LINE);

	SetLineWidth(2);
	SetEndArrowLength(24);
	SetEndArrowWidth(12);
	SetEndArrowType2(4);
	ShowLabelBorder(FALSE);
	SetPointSize(14);
}

CFOUMLSimpleLineShape::CFOUMLSimpleLineShape(const CFOUMLSimpleLineShape& src)
{
	*this = src;
}

CFOUMLSimpleLineShape::~CFOUMLSimpleLineShape()
{

}

/////////////////////////////////////////////////////////////////////////////
// CFOUMLSimpleLineShape diagnostics

#ifdef _DEBUG
void CFOUMLSimpleLineShape::AssertValid() const
{
	CFOTurnCornerLinkShape::AssertValid();
}

void CFOUMLSimpleLineShape::Dump(CDumpContext& dc) const
{
	CFOTurnCornerLinkShape::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
BOOL CFOUMLSimpleLineShape::Create(CArray<CPoint,CPoint>* ptArray,CFOPortShape *pFrom,CFOPortShape *pTo)
{
	BOOL bReturn = CFOTurnCornerLinkShape::Create(ptArray,pFrom,pTo);

	// FODO: Add your own code here.

	return bReturn;
}

BOOL CFOUMLSimpleLineShape::Create(LPPOINT pptPoints, int nCount,CFOPortShape *pFrom,CFOPortShape *pTo)
{
	BOOL bReturn = CFOTurnCornerLinkShape::Create(pptPoints,nCount,pFrom,pTo);

	// FODO: Add your own code here.

	return bReturn;
}

void CFOUMLSimpleLineShape::Serialize(CArchive& ar)
{
	CFOTurnCornerLinkShape::Serialize(ar);
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
CFile* CFOUMLSimpleLineShape::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
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

void CFOUMLSimpleLineShape::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CFOUMLSimpleLineShape::OpenDocument(LPCTSTR lpszPathName)
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

BOOL CFOUMLSimpleLineShape::SaveDocument(LPCTSTR lpszPathName)
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

CFOUMLSimpleLineShape& CFOUMLSimpleLineShape::operator=(const CFOUMLSimpleLineShape& src)
{
	(*(CFOTurnCornerLinkShape*)this) = src;
	return (*this);
}

CFODrawShape* CFOUMLSimpleLineShape::Copy() const
{
	return (new CFOUMLSimpleLineShape(*this));
}

void CFOUMLSimpleLineShape::GetPathSimplePolygon(FOPSimpleCompositePolygon& rPoly) const
{
	CFOTurnCornerLinkShape::GetPathSimplePolygon(rPoly);
}

CRect CFOUMLSimpleLineShape::CalcLabelPosition(CDC *pDC,BOOL &bFullSize) const
{
	return CFOTurnCornerLinkShape::CalcLabelPosition(pDC,bFullSize);
}

void CFOUMLSimpleLineShape::CalcExtendBoundRect(CRect &rcBound) const
{
	CFOTurnCornerLinkShape::CalcExtendBoundRect(rcBound);
	
}

void CFOUMLSimpleLineShape::DoDrawVisioOrderLine(CDC *pDC)
{
	CFOTurnCornerLinkShape::DoDrawVisioOrderLine(pDC);
}

BOOL CFOUMLSimpleLineShape::RelayoutPoints()
{
	return CFOTurnCornerLinkShape::RelayoutPoints();
}

BOOL CFOUMLSimpleLineShape::RelayoutTrackPoints()
{
	return CFOTurnCornerLinkShape::RelayoutTrackPoints();
}

void CFOUMLSimpleLineShape::PrepareDC(CDC* pDC)
{
	CFOTurnCornerLinkShape::PrepareDC(pDC);

	//FODO:Add your own code below.
	
}

void CFOUMLSimpleLineShape::OnDrawTrackCustom(CDC *pDC)
{
	CFOTurnCornerLinkShape::OnDrawTrackCustom(pDC);

	// Add your own code here.

}

void CFOUMLSimpleLineShape::OnDrawShadow(CDC *pDC)
{
	CFOTurnCornerLinkShape::OnDrawShadow(pDC);
	
	//FODO:Add your own code below.
	
}

void CFOUMLSimpleLineShape::OnDrawFlat(CDC *pDC)
{
	CFOTurnCornerLinkShape::OnDrawFlat(pDC);

	//FODO:Add your own code below.
	
}

void CFOUMLSimpleLineShape::OnDraw3d(CDC *pDC)
{
	CFOTurnCornerLinkShape::OnDraw3d(pDC);

	//FODO:Add your own code below.

}

void CFOUMLSimpleLineShape::ClearDC(CDC* pDC)
{
	CFOTurnCornerLinkShape::ClearDC(pDC);

	//FODO:Add your own code below.

}

void CFOUMLSimpleLineShape::GeometryUpdated(CFOArea* pRgn)
{
	CFOTurnCornerLinkShape::GeometryUpdated(pRgn);

	//FODO:Add your own code below.

}

void CFOUMLSimpleLineShape::BuildLineStartObject(int &nType)
{
	CFOTurnCornerLinkShape::BuildLineStartObject(nType);

	//FODO:Add your own code below.

}

void CFOUMLSimpleLineShape::BuildLineEndObject(int &nType)
{
	CFOTurnCornerLinkShape::BuildLineEndObject(nType);

	//FODO:Add your own code below.

}
