// FOUMLStartShape.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "FOUMLStartShape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// CFOUMLStartShape Class
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CFOUMLStartShape, CFOEllipseShape, 0)
CFOUMLStartShape::CFOUMLStartShape()
{
	SetType(EXT_START_SHAPE);
	SetBkColor(RGB(0,0,0));
	SetAspectRatio(TRUE);
	SetResizeProtect(TRUE);
	SetPolyObject(FALSE);
	SetRotateProtect(TRUE);
}

CFOUMLStartShape::CFOUMLStartShape(const CFOUMLStartShape& src)
{
	*this = src;
}

CFOUMLStartShape::~CFOUMLStartShape()
{

}

/////////////////////////////////////////////////////////////////////////////
// CFOUMLStartShape diagnostics

#ifdef _DEBUG
void CFOUMLStartShape::AssertValid() const
{
	CFOEllipseShape::AssertValid();
}

void CFOUMLStartShape::Dump(CDumpContext& dc) const
{
	CFOEllipseShape::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
void CFOUMLStartShape::Create(CRect &rcPos,CString strCaption)
{
	CFOEllipseShape::Create(rcPos,strCaption);

	RemoveAllPorts();
	
	CreateDefaultPort(0.5,0.0);
	CreateDefaultPort(0.0,0.5);
	CreateDefaultPort(1.0,0.5);
	CreateDefaultPort(0.5,1.0);
	// FODO: Add your own code here.

}

void CFOUMLStartShape::Serialize(CArchive& ar)
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
CFile* CFOUMLStartShape::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
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

void CFOUMLStartShape::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CFOUMLStartShape::OpenDocument(LPCTSTR lpszPathName)
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

BOOL CFOUMLStartShape::SaveDocument(LPCTSTR lpszPathName)
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

CFOUMLStartShape& CFOUMLStartShape::operator=(const CFOUMLStartShape& src)
{
	(*(CFOEllipseShape*)this) = src;
	return (*this);
}

CFODrawShape* CFOUMLStartShape::Copy() const
{
	return (new CFOUMLStartShape(*this));
}

void CFOUMLStartShape::PrepareDC(CDC* pDC)
{
	CFOEllipseShape::PrepareDC(pDC);

	//FODO:Add your own code below.
	
}

void CFOUMLStartShape::OnDrawTrackCustom(CDC *pDC)
{
	CFOEllipseShape::OnDrawTrackCustom(pDC);

	// Add your own code here.

}

void CFOUMLStartShape::OnDrawShadow(CDC *pDC)
{
	CFOEllipseShape::OnDrawShadow(pDC);
	
	//FODO:Add your own code below.
	
}

void CFOUMLStartShape::OnDrawFlat(CDC *pDC)
{
	CFOEllipseShape::OnDrawFlat(pDC);

	//FODO:Add your own code below.
	
}

void CFOUMLStartShape::OnDraw3d(CDC *pDC)
{
	CFOEllipseShape::OnDraw3d(pDC);

	//FODO:Add your own code below.

}

void CFOUMLStartShape::ClearDC(CDC* pDC)
{
	CFOEllipseShape::ClearDC(pDC);

	//FODO:Add your own code below.

}

void CFOUMLStartShape::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CFOEllipseShape::OnLButtonDown(nFlags,point);
	
	//FODO:Add your own code below.

}

void CFOUMLStartShape::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CFOEllipseShape::OnLButtonUp(nFlags,point);

	//FODO:Add your own code below.

}

void CFOUMLStartShape::GeometryUpdated(CFOArea* pRgn)
{
	CFOEllipseShape::GeometryUpdated(pRgn);

	//FODO:Add your own code below.

}
