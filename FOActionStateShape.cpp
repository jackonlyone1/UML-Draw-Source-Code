// FOActionStateShape.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "FOActionStateShape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// CFOActionStateShape Class
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CFOActionStateShape, CFORoundRectShape, 0)
CFOActionStateShape::CFOActionStateShape()
{
	SetType(ID_FOP_SAMPLE_UML_ACTION_STATE);
	SetShowLabelAtFirst(TRUE);
	SetPointSize(21);
	SetWeight(700);

}

CFOActionStateShape::CFOActionStateShape(const CFOActionStateShape& src)
{
	*this = src;
}

CFOActionStateShape::~CFOActionStateShape()
{

}

/////////////////////////////////////////////////////////////////////////////
// CFOActionStateShape diagnostics

#ifdef _DEBUG
void CFOActionStateShape::AssertValid() const
{
	CFORoundRectShape::AssertValid();
}

void CFOActionStateShape::Dump(CDumpContext& dc) const
{
	CFORoundRectShape::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////

void CFOActionStateShape::Create(CRect &rcPos,CString strCaption)
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

void CFOActionStateShape::Serialize(CArchive& ar)
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
CFile* CFOActionStateShape::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
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

void CFOActionStateShape::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CFOActionStateShape::OpenDocument(LPCTSTR lpszPathName)
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

BOOL CFOActionStateShape::SaveDocument(LPCTSTR lpszPathName)
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


CFOActionStateShape& CFOActionStateShape::operator=(const CFOActionStateShape& src)
{
	(*(CFORoundRectShape*)this) = src;
	return (*this);
}

CFODrawShape* CFOActionStateShape::Copy() const
{
	return (new CFOActionStateShape(*this));
}

void CFOActionStateShape::PrepareDC(CDC* pDC)
{
	CFORoundRectShape::PrepareDC(pDC);

	//FODO:Add your own code below.
	
}

void CFOActionStateShape::GetPathSimplePolygon(FOPSimpleCompositePolygon& rPoly) const
{
	CFORoundRectShape::GetPathSimplePolygon(rPoly);

}

void CFOActionStateShape::OnDrawTrackCustom(CDC *pDC)
{
	CFORoundRectShape::OnDrawTrackCustom(pDC);

	// Add your own code here.
}

void CFOActionStateShape::DoDrawVisioOrderLine(CDC *pDC)
{
	CFORoundRectShape::DoDrawVisioOrderLine(pDC);

	//FODO:Add your own code below.
	
}

void CFOActionStateShape::OnDrawFlat(CDC *pDC)
{
	CFORoundRectShape::OnDrawFlat(pDC);

	//FODO:Add your own code below.

// Example code:
//	FillPoly(pDC,m_lpShapePoints, m_nCompPtCount,GetBkColor(),
//		GetPatternColor(),GetBrushType());

}

void CFOActionStateShape::OnDrawShadow(CDC *pDC)
{
	CFORoundRectShape::OnDrawShadow(pDC);

	//FODO:Add your own code below.

// Example code:
//	FillShadowPoly(pDC,m_lpShapePoints, m_nCompPtCount);
}

void CFOActionStateShape::OnDraw3d(CDC *pDC)
{
	CFORoundRectShape::OnDraw3d(pDC);
	
	//FODO:Add your own code below.

// Example code:
//	FillPoly(pDC,m_lpShapePoints, m_nCompPtCount,GetBkColor(),
//		GetPatternColor(),GetBrushType());

}

void CFOActionStateShape::ClearDC(CDC* pDC)
{
	CFORoundRectShape::ClearDC(pDC);

	//FODO:Add your own code below.

}

void CFOActionStateShape::GeometryUpdated(CFOArea* pRgn)
{
	CFORoundRectShape::GeometryUpdated(pRgn);
// Example code:
//	if (m_lpShapePoints && pRgn)
//	{
//		pRgn->BuildPolygonArea(m_lpShapePoints, m_nCompPtCount);
//		m_rectPosition = pRgn->GetBoundingRect();
//	}

}
