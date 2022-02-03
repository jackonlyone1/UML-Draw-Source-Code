// FOUMLControlLineShape.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "FOUMLControlLineShape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// CFOUMLControlLineShape Class
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CFOUMLControlLineShape, CFORoundTurnCornerLinkShape, 0)
CFOUMLControlLineShape::CFOUMLControlLineShape()
{
	SetType(ID_FOP_SAMPLE_UML_CONTROL_LINE);
	SetLineWidth(2);
	SetEndArrowLength(15);
	SetEndArrowWidth(10);
	SetEndArrowType2(1);
	ShowLabelBorder(FALSE);
	SetPointSize(14);
}

CFOUMLControlLineShape::CFOUMLControlLineShape(const CFOUMLControlLineShape& src)
{
	*this = src;
}

CFOUMLControlLineShape::~CFOUMLControlLineShape()
{

}

/////////////////////////////////////////////////////////////////////////////
// CFOUMLControlLineShape diagnostics

#ifdef _DEBUG
void CFOUMLControlLineShape::AssertValid() const
{
	CFORoundTurnCornerLinkShape::AssertValid();
}

void CFOUMLControlLineShape::Dump(CDumpContext& dc) const
{
	CFORoundTurnCornerLinkShape::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
BOOL CFOUMLControlLineShape::Create(CArray<CPoint,CPoint>* ptArray)
{
	BOOL bReturn = CFORoundTurnCornerLinkShape::Create(ptArray);

	// FODO: Add your own code here.

	return bReturn;
}

BOOL CFOUMLControlLineShape::Create(LPPOINT pptPoints, int nCount)
{
	BOOL bReturn = CFORoundTurnCornerLinkShape::Create(pptPoints,nCount);

	// FODO: Add your own code here.

	return bReturn;
}

void CFOUMLControlLineShape::Serialize(CArchive& ar)
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
CFile* CFOUMLControlLineShape::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
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

void CFOUMLControlLineShape::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CFOUMLControlLineShape::OpenDocument(LPCTSTR lpszPathName)
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

BOOL CFOUMLControlLineShape::SaveDocument(LPCTSTR lpszPathName)
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

CFOUMLControlLineShape& CFOUMLControlLineShape::operator=(const CFOUMLControlLineShape& src)
{
	(*(CFORoundTurnCornerLinkShape*)this) = src;
	return (*this);
}

CFODrawShape* CFOUMLControlLineShape::Copy() const
{
	return (new CFOUMLControlLineShape(*this));
}

void CFOUMLControlLineShape::PrepareDC(CDC* pDC)
{
	CFORoundTurnCornerLinkShape::PrepareDC(pDC);

	//FODO:Add your own code below.
	
}

void CFOUMLControlLineShape::OnDrawTrackCustom(CDC *pDC)
{
	CFORoundTurnCornerLinkShape::OnDrawTrackCustom(pDC);

	// Add your own code here.

}

void CFOUMLControlLineShape::OnDrawShadow(CDC *pDC)
{
	CFORoundTurnCornerLinkShape::OnDrawShadow(pDC);
	
	//FODO:Add your own code below.
	
}

void CFOUMLControlLineShape::OnDrawFlat(CDC *pDC)
{
	CFORoundTurnCornerLinkShape::OnDrawFlat(pDC);

	//FODO:Add your own code below.
	
}

void CFOUMLControlLineShape::OnDraw3d(CDC *pDC)
{
	CFORoundTurnCornerLinkShape::OnDraw3d(pDC);

	//FODO:Add your own code below.

}

void CFOUMLControlLineShape::ClearDC(CDC* pDC)
{
	CFORoundTurnCornerLinkShape::ClearDC(pDC);

	//FODO:Add your own code below.

}

void CFOUMLControlLineShape::GeometryUpdated(CFOArea* pRgn)
{
	CFORoundTurnCornerLinkShape::GeometryUpdated(pRgn);

	//FODO:Add your own code below.

}

void CFOUMLControlLineShape::BuildLineStartObject(int &nType)
{
	CFORoundTurnCornerLinkShape::BuildLineStartObject(nType);

	//FODO:Add your own code below.

}

void CFOUMLControlLineShape::BuildLineEndObject(int &nType)
{
	CFORoundTurnCornerLinkShape::BuildLineEndObject(nType);

	//FODO:Add your own code below.

}
