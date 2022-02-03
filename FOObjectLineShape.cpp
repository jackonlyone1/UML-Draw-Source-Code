// FOObjectLineShape.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "FOObjectLineShape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// CFOObjectLineShape Class
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CFOObjectLineShape, CFOLinkShape, 0)
CFOObjectLineShape::CFOObjectLineShape()
{
	SetType(ID_FOP_SAMPLE_UML_OBJECT_LINE);
	SetLineWidth(2);
	SetEndArrowLength(15);
	SetEndArrowWidth(10);
	SetEndArrowType2(1);
	SetPenStyle(PS_DASH);
	ShowLabelBorder(FALSE);
	SetPointSize(14);
}

CFOObjectLineShape::CFOObjectLineShape(const CFOObjectLineShape& src)
{
	*this = src;
}

CFOObjectLineShape::~CFOObjectLineShape()
{

}

/////////////////////////////////////////////////////////////////////////////
// CFOObjectLineShape diagnostics

#ifdef _DEBUG
void CFOObjectLineShape::AssertValid() const
{
	CFOLinkShape::AssertValid();
}

void CFOObjectLineShape::Dump(CDumpContext& dc) const
{
	CFOLinkShape::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
BOOL CFOObjectLineShape::Create(CArray<CPoint,CPoint>* ptArray)
{
	BOOL bReturn = CFOLinkShape::Create(ptArray);

	// FODO: Add your own code here.

	return bReturn;
}

BOOL CFOObjectLineShape::Create(LPPOINT pptPoints, int nCount)
{
	BOOL bReturn = CFOLinkShape::Create(pptPoints,nCount);

	// FODO: Add your own code here.

	return bReturn;
}

void CFOObjectLineShape::Serialize(CArchive& ar)
{
	CFOLinkShape::Serialize(ar);
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
CFile* CFOObjectLineShape::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
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

void CFOObjectLineShape::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CFOObjectLineShape::OpenDocument(LPCTSTR lpszPathName)
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

BOOL CFOObjectLineShape::SaveDocument(LPCTSTR lpszPathName)
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

CFOObjectLineShape& CFOObjectLineShape::operator=(const CFOObjectLineShape& src)
{
	(*(CFOLinkShape*)this) = src;
	return (*this);
}

CFODrawShape* CFOObjectLineShape::Copy() const
{
	return (new CFOObjectLineShape(*this));
}

void CFOObjectLineShape::PrepareDC(CDC* pDC)
{
	CFOLinkShape::PrepareDC(pDC);

	//FODO:Add your own code below.
	
}

void CFOObjectLineShape::OnDrawTrackCustom(CDC *pDC)
{
	CFOLinkShape::OnDrawTrackCustom(pDC);

	// Add your own code here.

}

void CFOObjectLineShape::OnDrawShadow(CDC *pDC)
{
	CFOLinkShape::OnDrawShadow(pDC);
	
	//FODO:Add your own code below.
	
}

void CFOObjectLineShape::OnDrawFlat(CDC *pDC)
{
	CFOLinkShape::OnDrawFlat(pDC);

	//FODO:Add your own code below.
	
}

void CFOObjectLineShape::OnDraw3d(CDC *pDC)
{
	CFOLinkShape::OnDraw3d(pDC);

	//FODO:Add your own code below.

}

void CFOObjectLineShape::ClearDC(CDC* pDC)
{
	CFOLinkShape::ClearDC(pDC);

	//FODO:Add your own code below.

}

void CFOObjectLineShape::GeometryUpdated(CFOArea* pRgn)
{
	CFOLinkShape::GeometryUpdated(pRgn);

	//FODO:Add your own code below.

}

void CFOObjectLineShape::BuildLineStartObject(int &nType)
{
	CFOLinkShape::BuildLineStartObject(nType);

	//FODO:Add your own code below.

}

void CFOObjectLineShape::BuildLineEndObject(int &nType)
{
	CFOLinkShape::BuildLineEndObject(nType);

	//FODO:Add your own code below.

}
