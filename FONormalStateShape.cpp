// FONormalStateShape.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "FONormalStateShape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// CFONormalStateShape Class
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CFONormalStateShape, CFORoundRectShape, 0)
CFONormalStateShape::CFONormalStateShape()
{
	SetType(ID_FOP_SAMPLE_UML_NORMAL_STATE);
	SetShowLabelAtFirst(TRUE);
	SetPointSize(21);
	SetWeight(700);
	SetLineWidth(3);
}

CFONormalStateShape::CFONormalStateShape(const CFONormalStateShape& src)
{
	*this = src;
}

CFONormalStateShape::~CFONormalStateShape()
{

}

/////////////////////////////////////////////////////////////////////////////
// CFONormalStateShape diagnostics

#ifdef _DEBUG
void CFONormalStateShape::AssertValid() const
{
	CFORoundRectShape::AssertValid();
}

void CFONormalStateShape::Dump(CDumpContext& dc) const
{
	CFORoundRectShape::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////

void CFONormalStateShape::Create(CRect &rcPos,CString strCaption)
{
// Example code:
//	AllocMemory(4);
//	m_lpShapePoints[0] = CPoint(rcPos.left,  rcPos.top);
//	m_lpShapePoints[1] = CPoint(rcPos.right, rcPos.top);
//	m_lpShapePoints[2] = CPoint(rcPos.right, rcPos.bottom);
//	m_lpShapePoints[3] = CPoint(rcPos.left,  rcPos.bottom);
	CFORoundRectShape::Create(rcPos,strCaption);
	CreateDefaultPort(0.5,0.0);
	CreateDefaultPort(0.0,0.5);
	CreateDefaultPort(1.0,0.5);
	CreateDefaultPort(0.5,1.0);


}

void CFONormalStateShape::Serialize(CArchive& ar)
{
	CFORoundRectShape::Serialize(ar);
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
CFile* CFONormalStateShape::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
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

void CFONormalStateShape::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CFONormalStateShape::OpenDocument(LPCTSTR lpszPathName)
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

BOOL CFONormalStateShape::SaveDocument(LPCTSTR lpszPathName)
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


CFONormalStateShape& CFONormalStateShape::operator=(const CFONormalStateShape& src)
{
	(*(CFORoundRectShape*)this) = src;
	return (*this);
}

CFODrawShape* CFONormalStateShape::Copy() const
{
	return (new CFONormalStateShape(*this));
}

void CFONormalStateShape::PrepareDC(CDC* pDC)
{
	CFORoundRectShape::PrepareDC(pDC);

	//FODO:Add your own code below.
	
}

void CFONormalStateShape::GetPathSimplePolygon(FOPSimpleCompositePolygon& rPoly) const
{
	CFORoundRectShape::GetPathSimplePolygon(rPoly);

}

void CFONormalStateShape::OnDrawTrackCustom(CDC *pDC)
{
	CFORoundRectShape::OnDrawTrackCustom(pDC);

	// Add your own code here.
}

void CFONormalStateShape::DoDrawVisioOrderLine(CDC *pDC)
{
	CFORoundRectShape::DoDrawVisioOrderLine(pDC);

	//FODO:Add your own code below.
	
}

void CFONormalStateShape::OnDrawFlat(CDC *pDC)
{
	CFORoundRectShape::OnDrawFlat(pDC);

	//FODO:Add your own code below.

// Example code:
//	FillPoly(pDC,m_lpShapePoints, m_nCompPtCount,GetBkColor(),
//		GetPatternColor(),GetBrushType());

}

void CFONormalStateShape::OnDrawShadow(CDC *pDC)
{
	CFORoundRectShape::OnDrawShadow(pDC);

	//FODO:Add your own code below.

// Example code:
//	FillShadowPoly(pDC,m_lpShapePoints, m_nCompPtCount);
}

void CFONormalStateShape::OnDraw3d(CDC *pDC)
{
	CFORoundRectShape::OnDraw3d(pDC);
	
	//FODO:Add your own code below.

// Example code:
//	FillPoly(pDC,m_lpShapePoints, m_nCompPtCount,GetBkColor(),
//		GetPatternColor(),GetBrushType());

}

void CFONormalStateShape::ClearDC(CDC* pDC)
{
	CFORoundRectShape::ClearDC(pDC);

	//FODO:Add your own code below.

}

void CFONormalStateShape::GeometryUpdated(CFOArea* pRgn)
{
	CFORoundRectShape::GeometryUpdated(pRgn);
// Example code:
//	if (m_lpShapePoints && pRgn)
//	{
//		pRgn->BuildPolygonArea(m_lpShapePoints, m_nCompPtCount);
//		m_rectPosition = pRgn->GetBoundingRect();
//	}

}
