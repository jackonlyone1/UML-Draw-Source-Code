// ExtActorShape.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ExtActorShape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// CExtActorShape Class
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CExtActorShape, CFODrawPortsShape, 0)
CExtActorShape::CExtActorShape()
{
	SetType(EXT_ACTOR_SHAPE);
	ShowFontProp(TRUE);
//	SetNullPen(TRUE);
	SetPointSize(10);
	m_bShowLabelAtFirst = TRUE;
	SetPolyObject(FALSE);
	SetRotateProtect(TRUE);
	
	SetLineWidth(2);
}

CExtActorShape::CExtActorShape(const CExtActorShape& src)
{
	*this = src;
}

CExtActorShape::~CExtActorShape()
{

}

/////////////////////////////////////////////////////////////////////////////
// CExtActorShape diagnostics

#ifdef _DEBUG
void CExtActorShape::AssertValid() const
{
	CFODrawPortsShape::AssertValid();
}

void CExtActorShape::Dump(CDumpContext& dc) const
{
	CFODrawPortsShape::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////

void CExtActorShape::Create(CRect &rcPos,CString strCaption)
{
	AllocMemory(4);

	m_lpShapePoints[0] = CPoint(rcPos.left,  rcPos.top);
	m_lpShapePoints[1] = CPoint(rcPos.right, rcPos.top);
	m_lpShapePoints[2] = CPoint(rcPos.right, rcPos.bottom);
	m_lpShapePoints[3] = CPoint(rcPos.left,  rcPos.bottom);
	SetObjectCaption(strCaption);
	CFODrawPortsShape::Create(rcPos,strCaption);
	BuildAllDefaultPorts();
	UpdateComp();
}

void CExtActorShape::Serialize(CArchive& ar)
{
	CFODrawPortsShape::Serialize(ar);
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
CFile* CExtActorShape::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
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

void CExtActorShape::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CExtActorShape::OpenDocument(LPCTSTR lpszPathName)
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

BOOL CExtActorShape::SaveDocument(LPCTSTR lpszPathName)
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


CExtActorShape& CExtActorShape::operator=(const CExtActorShape& src)
{
	(*(CFODrawPortsShape*)this) = src;
	return (*this);
}

CFODrawShape* CExtActorShape::Copy() const
{
	return (new CExtActorShape(*this));
}

void CExtActorShape::PrepareDC(CDC* pDC)
{
	CFODrawPortsShape::PrepareDC(pDC);

	//FODO:Add your own code below.
	
}

void CExtActorShape::GetPathSimplePolygon(FOPSimpleCompositePolygon& rPoly) const
{
	CFODrawPortsShape::GetPathSimplePolygon(rPoly);

}

void CExtActorShape::OnDrawTrackCustom(CDC *pDC)
{
	CFODrawPortsShape::OnDrawTrackCustom(pDC);

	// Add your own code here.
}

void CExtActorShape::DoDrawVisioOrderLine(CDC *pDC)
{
	CFODrawPortsShape::DoDrawVisioOrderLine(pDC);

	//FODO:Add your own code below.
	
}

void CExtActorShape::OnDraw(CDC *pDC)
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

#define FOP_ACTOR_WIDTH 2.2
#define FOP_ACTOR_HEIGHT 4.6
#define FOP_ACTOR_HEAD(h) (h*0.6/4.6)
#define FOP_ACTOR_BODY(h) (h*4.0/4.6)
#define FOP_ACTOR_LINEWIDTH 0.1
#define FOP_ACTOR_MARGIN_X 0.3
#define FOP_ACTOR_MARGIN_Y 0.3

void CExtActorShape::OnDrawFlat(CDC *pDC)
{
	CFODrawPortsShape::OnDrawFlat(pDC);
	CSize szImage = CSize(40,60);
	
	CRect rcTemp;
	rcTemp = CRect(m_lpShapePoints[0],m_lpShapePoints[2]);
	rcTemp.NormalizeRect();

	CString strText = GetObjectCaption();
	CRect rcNew = rcTemp;
	if(!m_bWithTextWrap)
			rcNew.InflateRect(gfxData.fo_DefaultSnapLineSizPix * 20000,gfxData.fo_DefaultSnapLineSizPix * 20000,
			gfxData.fo_DefaultSnapLineSizPix * 20000,gfxData.fo_DefaultSnapLineSizPix * 20000);

	CSize sizeText = GetTextSize(pDC,rcNew,strText);

	if(rcTemp.Height() != szImage.cy || rcTemp.Width() != szImage.cx)
	{
		rcTemp.bottom = rcTemp.top + szImage.cy;
		rcTemp.right = rcTemp.left + szImage.cx;

		PositionShape(rcTemp);
	}

	FOPRect rcBitmap = GetDrawRect();
	rcBitmap.bottom = rcBitmap.top + szImage.cy;
	int nCenterX = rcBitmap.CenterPoint().x;

	rcBitmap.left = nCenterX - (int)(szImage.cx / 2.0);
	rcBitmap.right = nCenterX + (int)(szImage.cx / 2.0);
	
	FOPRect rcDraw = rcBitmap;
	rcDraw.OffsetRect(CPoint(0,8));
	double x, y, w, h;
	double r, r1;  
	FOPPoint ch, cb, p1, p2;
	double actor_height;
	
	x = (double)rcDraw.left;
	y = (double)rcDraw.top;
	w = (double)rcDraw.Width();
	h = (double)rcDraw.Height();
	actor_height = (double)rcDraw.Height() -5;//actor->text->height;
	
	
	r = FOP_ACTOR_HEAD(actor_height);
	r1 = 2*r;
	ch.x = CFODrawHelper::RoundValue(x + w*0.5);
	ch.y = CFODrawHelper::RoundValue(y + r + FOP_ACTOR_MARGIN_Y);
	cb.x = ch.x;
	cb.y = CFODrawHelper::RoundValue(ch.y + r1 + r);

	/* head */
	FOPRect rc = FOPRect(CFODrawHelper::RoundValue(ch.x - r),
		CFODrawHelper::RoundValue(ch.y - r),
		CFODrawHelper::RoundValue(ch.x + r),
		CFODrawHelper::RoundValue(ch.y + r));
	pDC->Ellipse(&rc);

	/* Arms */
	p1.x = CFODrawHelper::RoundValue(ch.x - r1);
	p2.x = CFODrawHelper::RoundValue(ch.x + r1);
	p1.y = p2.y = CFODrawHelper::RoundValue(ch.y + r);
	pDC->MoveTo(p1);
	pDC->LineTo(p2);
	
	p1.x = ch.x;
	p1.y = CFODrawHelper::RoundValue(ch.y + r*0.5);
	/* body & legs  */

	pDC->MoveTo(p1);
	pDC->LineTo(cb);
	
	p2.x = CFODrawHelper::RoundValue(ch.x - r1);
	p2.y = CFODrawHelper::RoundValue(y + FOP_ACTOR_BODY(actor_height));

	pDC->MoveTo(cb);
	pDC->LineTo(p2);
	
	p2.x =  CFODrawHelper::RoundValue(ch.x + r1);

	pDC->MoveTo(cb);
	pDC->LineTo(p2);

	CRect rcTextBox  = rcTemp;
	rcTextBox.top = rcTemp.top + szImage.cy + sizeText.cy + 4;
	rcTextBox.left = rcTemp.CenterPoint().x - sizeText.cx / 2 + 2;
	rcTextBox.right = rcTemp.CenterPoint().x + sizeText.cx / 2 + 2;

	if (m_pEdit != NULL)
	{
		if(GetWithLabelEditing())
		{
			OnDrawTextAndEdit(pDC,rcTextBox,FALSE);
		}
	}
	else
	{
		COLORREF crColor = GetFontColor();
		DoDrawText(pDC,GetObjectCaption(),rcTextBox,GetDrawFormatType(),crColor,FALSE);
	}
}

CSize CExtActorShape::GetTextSize(CDC* pDC,CRect rcPos,CString strText)
{
	CSize sizeText(0,0);

	CStringArray setBreaks;
	CreateTextArray(pDC,strText,rcPos,setBreaks);
	
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	
	for (int nBreak = 0; nBreak < setBreaks.GetSize(); nBreak++)
	{
		CString strLine = setBreaks.GetAt(nBreak);
		CSize sizeLine(0,0);
		
		if (strLine.GetLength() > 0)
		{
			sizeLine = pDC->GetTextExtent(strLine);
		}
		else
		{
			sizeLine.cx = 1;
			sizeLine.cy = tm.tmHeight;
		}
		
		sizeText.cx = FORMMAX(sizeText.cx, sizeLine.cx);
		sizeText.cy += sizeLine.cy;
	}
	
	return sizeText;
}


UINT CExtActorShape::GetDrawFormatType()
{
	UINT nTextHorz = GetTextHorzAlignment();
	UINT nTextVert = GetTextVertAlignment();
	UINT nAlign;
	if(IsMultiLine())
	{
		nAlign = DT_WORDBREAK;
		switch(nTextHorz)
		{
		case TextLeft: 
			{
				nAlign |= DT_LEFT;
			}
			break;
		case TextMiddle: 
			{
				nAlign |= DT_CENTER;
			}
			break;
		case TextRight:
			{
				nAlign |= DT_RIGHT;
			}
			break;
			
		}
	}
	else
	{
		nAlign = DT_SINGLELINE;
		switch(nTextHorz)
		{
		case TextLeft: 
			{
				nAlign |= DT_LEFT;
			}
			break;
		case TextMiddle: 
			{
				nAlign |= DT_CENTER;
			}
			break;
		case TextRight:
			{
				nAlign |= DT_RIGHT;
			}
			break;
			
		}
		
		switch(nTextVert)
		{
		case TextTop: 
			{
				nAlign |= DT_TOP;
			}
			break;
		case TextCenter: 
			{
				nAlign |= DT_VCENTER;
			}
			break;
		case TextBottom:
			{
				nAlign |= DT_BOTTOM;
			}
			break;
			
		}
	}
	return nAlign;
}

int CExtActorShape::CreateTextArray(CDC* pDC, CString strText,CRect rcBox,CStringArray& arLines)
{
	return CFODrawShape::CreateTextArray(pDC,strText,rcBox,arLines);
}

void CExtActorShape::OnDrawShadow(CDC *pDC)
{
	FillShadowPoly(pDC,m_lpShapePoints, m_nCompPtCount);
}

void CExtActorShape::OnDraw3d(CDC *pDC)
{
	CFODrawPortsShape::OnDraw3d(pDC);

	CSize szImage = CSize(40,60);
	
	CRect rcTemp;
	rcTemp = CRect(m_lpShapePoints[0],m_lpShapePoints[2]);
	rcTemp.NormalizeRect();

	CString strText = GetObjectCaption();
	CRect rcNew = rcTemp;
	if(!m_bWithTextWrap)
			rcNew.InflateRect(gfxData.fo_DefaultSnapLineSizPix * 20000,gfxData.fo_DefaultSnapLineSizPix * 20000,
			gfxData.fo_DefaultSnapLineSizPix * 20000,gfxData.fo_DefaultSnapLineSizPix * 20000);

	CSize sizeText = GetTextSize(pDC,rcNew,strText);

	if(rcTemp.Height() != szImage.cy || rcTemp.Width() != szImage.cx)
	{
		rcTemp.bottom = rcTemp.top + szImage.cy;
		rcTemp.right = rcTemp.left + szImage.cx;

		PositionShape(rcTemp);
	}

	FOPRect rcBitmap = GetDrawRect();
	rcBitmap.bottom = rcBitmap.top + szImage.cy;
	int nCenterX = rcBitmap.CenterPoint().x;

	rcBitmap.left = nCenterX - (int)(szImage.cx / 2.0);
	rcBitmap.right = nCenterX + (int)(szImage.cx / 2.0);
	
	FOPRect rcDraw = rcBitmap;
	rcDraw.OffsetRect(CPoint(0,8));
	double x, y, w, h;
	double r, r1;  
	FOPPoint ch, cb, p1, p2;
	double actor_height;
	
	x = (double)rcDraw.left;
	y = (double)rcDraw.top;
	w = (double)rcDraw.Width();
	h = (double)rcDraw.Height();
	actor_height = (double)rcDraw.Height() -5;//actor->text->height;
	
	
	r = FOP_ACTOR_HEAD(actor_height);
	r1 = 2*r;
	ch.x = CFODrawHelper::RoundValue(x + w*0.5);
	ch.y = CFODrawHelper::RoundValue(y + r + FOP_ACTOR_MARGIN_Y);
	cb.x = ch.x;
	cb.y = CFODrawHelper::RoundValue(ch.y + r1 + r);

	/* head */
	FOPRect rc = FOPRect(CFODrawHelper::RoundValue(ch.x - r),
		CFODrawHelper::RoundValue(ch.y - r),
		CFODrawHelper::RoundValue(ch.x + r),
		CFODrawHelper::RoundValue(ch.y + r));
	pDC->Ellipse(&rc);

	/* Arms */
	p1.x = CFODrawHelper::RoundValue(ch.x - r1);
	p2.x = CFODrawHelper::RoundValue(ch.x + r1);
	p1.y = p2.y = CFODrawHelper::RoundValue(ch.y + r);
	pDC->MoveTo(p1);
	pDC->LineTo(p2);
	
	p1.x = ch.x;
	p1.y = CFODrawHelper::RoundValue(ch.y + r*0.5);
	/* body & legs  */

	pDC->MoveTo(p1);
	pDC->LineTo(cb);
	
	p2.x = CFODrawHelper::RoundValue(ch.x - r1);
	p2.y = CFODrawHelper::RoundValue(y + FOP_ACTOR_BODY(actor_height));

	pDC->MoveTo(cb);
	pDC->LineTo(p2);
	
	p2.x =  CFODrawHelper::RoundValue(ch.x + r1);

	pDC->MoveTo(cb);
	pDC->LineTo(p2);

	CRect rcTextBox  = rcTemp;
	rcTextBox.top = rcTemp.top + szImage.cy + sizeText.cy + 4;
	rcTextBox.left = rcTemp.CenterPoint().x - sizeText.cx / 2 + 2;
	rcTextBox.right = rcTemp.CenterPoint().x + sizeText.cx / 2 + 2;

	if (m_pEdit != NULL)
	{
		if(GetWithLabelEditing())
		{
			OnDrawTextAndEdit(pDC,rcTextBox,FALSE);
		}
	}
	else
	{
		COLORREF crColor = GetFontColor();
		DoDrawText(pDC,GetObjectCaption(),rcTextBox,GetDrawFormatType(),crColor,FALSE);
	}
}

void CExtActorShape::ClearDC(CDC* pDC)
{
	CFODrawPortsShape::ClearDC(pDC);

	//FODO:Add your own code below.

}

void CExtActorShape::GeometryUpdated(CFOArea* pArea)
{

	if (m_lpShapePoints && pArea)
	{
		pArea->BuildPolygonArea(m_lpShapePoints, m_nCompPtCount);
		m_rectPosition = pArea->GetBoundingRect();
	}

}
