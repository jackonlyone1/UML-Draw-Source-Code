// ExtCompShape.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ExtCompShape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// CExtCompShape Class
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CExtCompShape, CFORectShape, 0)
CExtCompShape::CExtCompShape()
{
	SetType(EXT_COMP_SHAPE);

	SetPolyObject(FALSE);
	SetRotateProtect(TRUE);

	ShowFontProp(TRUE);
//	SetNullPen(TRUE);
	SetPointSize(10);
	SetAspectRatio(TRUE);
	SetResizeProtect(TRUE);
	SetPolyObject(FALSE);
	SetRotateProtect(TRUE);
	SetLineWidth(2);

	m_bShowLabelAtFirst = TRUE;
	SetMultiLine(TRUE);
	m_bWithTextWrap = TRUE;

	SetWeight(700);
}

CExtCompShape::CExtCompShape(const CExtCompShape& src)
{
	*this = src;
}

CExtCompShape::~CExtCompShape()
{

}

/////////////////////////////////////////////////////////////////////////////
// CExtCompShape diagnostics

#ifdef _DEBUG
void CExtCompShape::AssertValid() const
{
	CFORectShape::AssertValid();
}

void CExtCompShape::Dump(CDumpContext& dc) const
{
	CFORectShape::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
void CExtCompShape::Create(CRect &rcPos,CString strCaption)
{
	CFORectShape::Create(rcPos,strCaption);
	RemoveAllPorts();
	// FODO: Add your own code here.
	CreateDefaultPort(0.5,0.0);
	CreateDefaultPort(0.0,0.25);
	CreateDefaultPort(0.0,0.75);
	CreateDefaultPort(1.0,0.5);
	CreateDefaultPort(1.0,0.0);
	CreateDefaultPort(1.0,1.0);
	CreateDefaultPort(0.5,1.0);
}

void CExtCompShape::Serialize(CArchive& ar)
{
	CFORectShape::Serialize(ar);
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
CFile* CExtCompShape::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
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

void CExtCompShape::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CExtCompShape::OpenDocument(LPCTSTR lpszPathName)
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

BOOL CExtCompShape::SaveDocument(LPCTSTR lpszPathName)
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

CExtCompShape& CExtCompShape::operator=(const CExtCompShape& src)
{
	(*(CFORectShape*)this) = src;
	return (*this);
}

CFODrawShape* CExtCompShape::Copy() const
{
	return (new CExtCompShape(*this));
}

void CExtCompShape::PrepareDC(CDC* pDC)
{
	CFORectShape::PrepareDC(pDC);

}

void CExtCompShape::OnDrawTrackCustom(CDC *pDC)
{
	CFORectShape::OnDrawTrackCustom(pDC);

	// Add your own code here.

}

void CExtCompShape::OnDrawShadow(CDC *pDC)
{
	CFORectShape::OnDrawShadow(pDC);
	
	//FODO:Add your own code below.
	
}

#define COMPONENT_CHEIGHT 14
#define COMPONENT_CWIDTH 40.0

void CExtCompShape::OnDrawFlat(CDC *pDC)
{
	CFODrawShape::OnDrawFlat(pDC);

	//FODO:Add your own code below.
	CRect rcText;
	FOPRect rcDraw = GetDrawRect();
	double x, y, w, h;
	FOPPoint p1, p2;
	x = (double)rcDraw.left;
	y = (double)rcDraw.top;
	w = (double)rcDraw.Width();
	h = (double)rcDraw.Height();
 
	p1.x = CFODrawHelper::RoundValue(x + COMPONENT_CWIDTH/2);
	p1.y = CFODrawHelper::RoundValue(y);

	p2.x = CFODrawHelper::RoundValue(x+w);
	p2.y = CFODrawHelper::RoundValue(y+h);
	
	FOPRect rc(p1, p2);
	rcText = rc;
	rcText.left = CFODrawHelper::RoundValue(rcText.left + COMPONENT_CWIDTH/2);
	pDC->Rectangle(&rc);
	
	p1.x= CFODrawHelper::RoundValue(x); 
	p1.y = CFODrawHelper::RoundValue(y +(h - 3*COMPONENT_CHEIGHT)/2.0);

	p2.x = CFODrawHelper::RoundValue(x+COMPONENT_CWIDTH); 
	p2.y = CFODrawHelper::RoundValue(p1.y + COMPONENT_CHEIGHT);
	
	rc = FOPRect(p1, p2);

	
	pDC->Rectangle(&rc);
	
	p1.y = CFODrawHelper::RoundValue(p2.y + COMPONENT_CHEIGHT);
	p2.y = CFODrawHelper::RoundValue(p1.y + COMPONENT_CHEIGHT);
	
	rc = FOPRect(p1, p2);
	pDC->Rectangle(&rc);

	if (m_pEdit != NULL)
	{
		if(GetWithLabelEditing())
		{
			OnDrawTextAndEdit(pDC,rcText,FALSE);
		}
	}
	else
	{
		COLORREF crColor = GetFontColor();
		DoDrawText(pDC,GetObjectCaption(),rcText,GetDrawFormatType(),crColor,FALSE);
	}
}

void CExtCompShape::OnDraw(CDC *pDC)
{
	if(!IsVisible())
	{
		return;
	}

	if(m_bCurUpdateDraw)
	{ 
		DoCurrentValueChange(m_dCurValue);
		m_bCurUpdateDraw = FALSE; 
	}
 
	if(m_bNeedValid)
	{
		UpdateComp();
		m_bNeedValid = FALSE;
	}
	
	if(GetShadow())
	{
		PrepareShadowDC(pDC);
		OnDrawShadow(pDC);
		ClearShadowDC(pDC);
	}

	PrepareDC(pDC);

	{
		if(IsFlat())
		{
			OnDrawFlat(pDC);
		}
		else
		{
			OnDraw3d(pDC);
		}
	}

	ClearDC(pDC);

	OnDrawPorts(pDC,TRUE);
}

void CExtCompShape::OnDraw3d(CDC *pDC)
{
	CFODrawShape::OnDraw3d(pDC);

	//FODO:Add your own code below.

	CRect rcText;
	FOPRect rcDraw = GetDrawRect();
	double x, y, w, h;
	FOPPoint p1, p2;
	x = (double)rcDraw.left;
	y = (double)rcDraw.top;
	w = (double)rcDraw.Width();
	h = (double)rcDraw.Height();
 
	p1.x = CFODrawHelper::RoundValue(x + COMPONENT_CWIDTH/2);
	p1.y = CFODrawHelper::RoundValue(y);

	p2.x = CFODrawHelper::RoundValue(x+w);
	p2.y = CFODrawHelper::RoundValue(y+h);
	
	FOPRect rc(p1, p2);
	rcText = rc;
	rcText.left = CFODrawHelper::RoundValue(rcText.left + COMPONENT_CWIDTH/2);
	pDC->Rectangle(&rc);
	
	p1.x= CFODrawHelper::RoundValue(x); 
	p1.y = CFODrawHelper::RoundValue(y +(h - 3*COMPONENT_CHEIGHT)/2.0);

	p2.x = CFODrawHelper::RoundValue(x+COMPONENT_CWIDTH); 
	p2.y = CFODrawHelper::RoundValue(p1.y + COMPONENT_CHEIGHT);
	
	rc = FOPRect(p1, p2);

	
	pDC->Rectangle(&rc);
	
	p1.y = CFODrawHelper::RoundValue(p2.y + COMPONENT_CHEIGHT);
	p2.y = CFODrawHelper::RoundValue(p1.y + COMPONENT_CHEIGHT);
	
	rc = FOPRect(p1, p2);
	pDC->Rectangle(&rc);

	if (m_pEdit != NULL)
	{
		if(GetWithLabelEditing())
		{
			OnDrawTextAndEdit(pDC,rcText,FALSE);
		}
	}
	else
	{
		COLORREF crColor = GetFontColor();
		DoDrawText(pDC,GetObjectCaption(),rcText,GetDrawFormatType(),crColor,FALSE);
	}
}

void CExtCompShape::ClearDC(CDC* pDC)
{
	CFORectShape::ClearDC(pDC);

	//FODO:Add your own code below.

}

void CExtCompShape::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CFORectShape::OnLButtonDown(nFlags,point);
	
	//FODO:Add your own code below.

}

void CExtCompShape::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CFORectShape::OnLButtonUp(nFlags,point);

	//FODO:Add your own code below.

}

void CExtCompShape::GeometryUpdated(CFOArea* pRgn)
{
	CFORectShape::GeometryUpdated(pRgn);

	//FODO:Add your own code below.

}
