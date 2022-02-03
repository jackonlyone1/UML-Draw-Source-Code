// FOUMLEndShape.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "FOUMLEndShape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// CFOUMLEndShape Class
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CFOUMLEndShape, CFOEllipseShape, 0)
CFOUMLEndShape::CFOUMLEndShape()
{
	SetType(EXT_END_SHAPE);
	SetBkColor(RGB(0,0,0));
	SetAspectRatio(TRUE);
	SetResizeProtect(TRUE);
	SetPolyObject(FALSE);
	SetRotateProtect(TRUE);
	SetLineWidth(2);
}

CFOUMLEndShape::CFOUMLEndShape(const CFOUMLEndShape& src)
{
	*this = src;
}

CFOUMLEndShape::~CFOUMLEndShape()
{

}

/////////////////////////////////////////////////////////////////////////////
// CFOUMLEndShape diagnostics

#ifdef _DEBUG
void CFOUMLEndShape::AssertValid() const
{
	CFOEllipseShape::AssertValid();
}

void CFOUMLEndShape::Dump(CDumpContext& dc) const
{
	CFOEllipseShape::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
void CFOUMLEndShape::Create(CRect &rcPos,CString strCaption)
{
	CFOEllipseShape::Create(rcPos,strCaption);

	// FODO: Add your own code here.
	RemoveAllPorts();
	CreateDefaultPort(0.5,0.0);
	CreateDefaultPort(0.0,0.5);
	CreateDefaultPort(1.0,0.5);
	CreateDefaultPort(0.5,1.0);

}

void CFOUMLEndShape::Serialize(CArchive& ar)
{
	CFOEllipseShape::Serialize(ar);
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
CFile* CFOUMLEndShape::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
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

void CFOUMLEndShape::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CFOUMLEndShape::OpenDocument(LPCTSTR lpszPathName)
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

BOOL CFOUMLEndShape::SaveDocument(LPCTSTR lpszPathName)
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

CFOUMLEndShape& CFOUMLEndShape::operator=(const CFOUMLEndShape& src)
{
	(*(CFOEllipseShape*)this) = src;
	return (*this);
}

CFODrawShape* CFOUMLEndShape::Copy() const
{
	return (new CFOUMLEndShape(*this));
}

void CFOUMLEndShape::PrepareDC(CDC* pDC)
{
	CFOEllipseShape::PrepareDC(pDC);

	//FODO:Add your own code below.
	
}

void CFOUMLEndShape::OnDrawTrackCustom(CDC *pDC)
{
	CFOEllipseShape::OnDrawTrackCustom(pDC);

	// Add your own code here.

}

void CFOUMLEndShape::OnDrawShadow(CDC *pDC)
{
	CFOEllipseShape::OnDrawShadow(pDC);
	
	//FODO:Add your own code below.
	
}

void CFOUMLEndShape::OnDrawFlat(CDC *pDC)
{
	CRect rcTemp = GetDrawRect();
	rcTemp.NormalizeRect();
	
	CBrush *pOldBrush = (CBrush *)pDC->SelectStockObject(NULL_BRUSH);
	
	pDC->Ellipse(&rcTemp);
	
	pDC->SelectObject(pOldBrush);
	rcTemp.DeflateRect(8,8,8,8);
	
	CBrush brush(RGB(0,0,0));
	pOldBrush = (CBrush *)pDC->SelectObject(&brush);
	
	pDC->Ellipse(&rcTemp);
	
	pDC->SelectObject(pOldBrush);
	brush.DeleteObject();
}

void CFOUMLEndShape::OnDraw3d(CDC *pDC)
{
	CRect rcTemp = GetDrawRect();
	rcTemp.NormalizeRect();
	
	CBrush *pOldBrush = (CBrush *)pDC->SelectStockObject(NULL_BRUSH);

	pDC->Ellipse(&rcTemp);

	pDC->SelectObject(pOldBrush);
	rcTemp.DeflateRect(8,8,8,8);

	CBrush brush(RGB(0,0,0));
	pOldBrush = (CBrush *)pDC->SelectObject(&brush);
	
	pDC->Ellipse(&rcTemp);
	
	pDC->SelectObject(pOldBrush);
	brush.DeleteObject();
}

void CFOUMLEndShape::ClearDC(CDC* pDC)
{
	CFOEllipseShape::ClearDC(pDC);

	//FODO:Add your own code below.

}

void CFOUMLEndShape::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CFOEllipseShape::OnLButtonDown(nFlags,point);
	
	//FODO:Add your own code below.

}

void CFOUMLEndShape::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CFOEllipseShape::OnLButtonUp(nFlags,point);

	//FODO:Add your own code below.

}

void CFOUMLEndShape::GeometryUpdated(CFOArea* pRgn)
{
	CFOEllipseShape::GeometryUpdated(pRgn);

	//FODO:Add your own code below.

}
