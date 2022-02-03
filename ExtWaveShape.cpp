// ExtWaveShape.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ExtWaveShape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// CExtWaveShape Class
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CExtWaveShape, CFODrawPortsShape, 0)
CExtWaveShape::CExtWaveShape()
{
	SetType(EXT_WAVE_SHAPE);
	SetPolyObject(FALSE);
	SetRotateProtect(TRUE);
	SetLineWidth(2);
}

CExtWaveShape::CExtWaveShape(const CExtWaveShape& src)
{
	SetPolyObject(TRUE);
	*this = src;
}

CExtWaveShape::~CExtWaveShape()
{

}

/////////////////////////////////////////////////////////////////////////////
// CExtWaveShape diagnostics

#ifdef _DEBUG
void CExtWaveShape::AssertValid() const
{
	CFODrawPortsShape::AssertValid();
}

void CExtWaveShape::Dump(CDumpContext& dc) const
{
	CFODrawPortsShape::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////

void CExtWaveShape::Create(CRect &rcPos,CString strCaption)
{
// Example code:
	AllocMemory(8);

	FOPRect theRect = rcPos;

	FOPPoint controlPoint1 = FOPPoint(theRect.left, theRect.top + theRect.Height() / 4);
	FOPPoint controlPoint2 = theRect.BottomCenter();

	FOPPoint upPoints[4];
	FOPPoint downPoints[4];
	int tmpHeight = controlPoint1.y - theRect.top;
	int tmpWidth = controlPoint2.x - (theRect.left + theRect.Width()/2);
	int i;
	
	if ( ((theRect.Width()>0)&&(tmpWidth>0)) || ((theRect.Width()<0)&&(tmpWidth<0)) )
		upPoints[0].x = theRect.left;
	else 
		upPoints[0].x = theRect.left - tmpWidth*2;
	upPoints[0].y = theRect.top + tmpHeight;
	
	for (i=1;i<3;i++)
	{
		if (theRect.Width()>0)
			upPoints[i].x = CFODrawHelper::RoundValue(upPoints[0].x + (2*i-1)*(fabs((double)theRect.Width()) - 2*fabs((double)tmpWidth))/4);
		else
			upPoints[i].x = CFODrawHelper::RoundValue(upPoints[0].x - (2*i-1)*(fabs((double)theRect.Width()) - 2*fabs((double)tmpWidth))/4);
	}
	
	if (theRect.Width()>0)
		upPoints[3].x = CFODrawHelper::RoundValue(upPoints[0].x + (fabs((double)theRect.Width()) - 2*fabs((double)tmpWidth)));
	else 
		upPoints[3].x = CFODrawHelper::RoundValue(upPoints[0].x - (fabs((double)theRect.Width()) - 2*fabs((double)tmpWidth)));
	
	upPoints[1].y = upPoints[0].y - tmpHeight;
	upPoints[2].y = upPoints[0].y + tmpHeight;
	upPoints[3].y = upPoints[0].y;
	
	//down points
	if ( ((theRect.Width()>0)&&(tmpWidth>0)) || ((theRect.Width()<0)&&(tmpWidth<0)) )
		downPoints[0].x = theRect.left+theRect.Width();
	else 
		downPoints[0].x = theRect.left+theRect.Width() + tmpWidth*2;

	downPoints[0].y = theRect.top + theRect.Height() - tmpHeight;
	
	for (i=1;i<3;i++)
	{
		if (theRect.Width()>0)
			downPoints[i].x = CFODrawHelper::RoundValue(downPoints[0].x - (2*i-1)*(fabs((double)theRect.Width()) - 2*fabs((double)tmpWidth))/4);
		else 
			downPoints[i].x = CFODrawHelper::RoundValue(downPoints[0].x + (2*i-1)*(fabs((double)theRect.Width()) - 2*fabs((double)tmpWidth))/4);
	}
	if (theRect.Width()>0)
		downPoints[3].x = CFODrawHelper::RoundValue(downPoints[0].x - (fabs((double)theRect.Width()) - 2*fabs((double)tmpWidth)));
	else 
		downPoints[3].x = CFODrawHelper::RoundValue(downPoints[0].x + (fabs((double)theRect.Width()) - 2*fabs((double)tmpWidth)));
	
	downPoints[1].y = downPoints[0].y + tmpHeight;
	downPoints[2].y = downPoints[0].y - tmpHeight;
	downPoints[3].y = downPoints[0].y;

	m_lpShapePoints[0] = upPoints[0];
	m_lpShapePoints[1] = upPoints[1];
	m_lpShapePoints[2] = upPoints[2];
	m_lpShapePoints[3] = upPoints[3];
	m_lpShapePoints[4] = downPoints[0];
	m_lpShapePoints[5] = downPoints[1];
	m_lpShapePoints[6] = downPoints[2];
	m_lpShapePoints[7] = downPoints[3];

//	m_ptSaveAnchor = m_ptAnchor = controlPoint1;
//	m_ptSaveExtAnchor = m_ptExtAnchor = controlPoint2;

	CFODrawPortsShape::Create(rcPos,strCaption);
//	CreateDefaultPort(0.5,0.5);
	CreateDefaultPort(0.5,0.0);
	CreateDefaultPort(0.0,0.5);
	CreateDefaultPort(1.0,0.5);
	CreateDefaultPort(0.5,1.0);

}

void CExtWaveShape::Serialize(CArchive& ar)
{
	CFODrawPortsShape::Serialize(ar);
	if(ar.IsStoring())
	{
		//FODO:Add your own code here.
	ar << m_ptSaveAnchor.x;
	ar << m_ptSaveAnchor.y;
	ar << m_ptSaveExtAnchor.x;
	ar << m_ptSaveExtAnchor.y;
	}
	else
	{
		//FODO:Add your own code here.
	if(m_nVersion >= 48)
	{
		ar >> m_ptSaveAnchor.x;
		ar >> m_ptSaveAnchor.y;
	}
	else
	{
		FOPPoint ptAt;
		ar >>ptAt;
		m_ptSaveAnchor = ptAt;
	}
	if(m_nVersion >= 48)
	{
		ar >> m_ptSaveExtAnchor.x;
		ar >> m_ptSaveExtAnchor.y;
	}
	else
	{
		FOPPoint ptAt;
		ar >>ptAt;
		m_ptSaveExtAnchor = ptAt;
	}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPrintBaseJob serialization
CFile* CExtWaveShape::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
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

void CExtWaveShape::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CExtWaveShape::OpenDocument(LPCTSTR lpszPathName)
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

BOOL CExtWaveShape::SaveDocument(LPCTSTR lpszPathName)
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


CExtWaveShape& CExtWaveShape::operator=(const CExtWaveShape& src)
{
	(*(CFODrawPortsShape*)this) = src;
	return (*this);
}

CFODrawShape* CExtWaveShape::Copy() const
{
	return (new CExtWaveShape(*this));
}

void CExtWaveShape::PrepareDC(CDC* pDC)
{
	CFODrawPortsShape::PrepareDC(pDC);

	//FODO:Add your own code below.
	
}

void CExtWaveShape::GetPlusSpotLocation(CFOPHandleList& lstHandle)
{
}

void CExtWaveShape::GetPathSimplePolygon(FOPSimpleCompositePolygon& rPoly) const
{
	CFODrawPortsShape::GetPathSimplePolygon(rPoly);

}

BYTE types[] = {
				PT_MOVETO,
				PT_BEZIERTO,
				PT_BEZIERTO,
				PT_BEZIERTO,
				PT_LINETO,
				PT_BEZIERTO,
				PT_BEZIERTO,
				PT_BEZIERTO,
				PT_LINETO
				};

void CExtWaveShape::OnDrawTrackCustom(CDC *pDC)
{
	CFODrawPortsShape::OnDrawTrackCustom(pDC);

	// Add your own code here.
}

void CExtWaveShape::DoDrawVisioOrderLine(CDC *pDC)
{
	CFODrawPortsShape::DoDrawVisioOrderLine(pDC);

	//FODO:Add your own code below.
	
}

void CExtWaveShape::OnDrawFlat(CDC *pDC)
{
	CFODrawPortsShape::OnDrawFlat(pDC);

	//FODO:Add your own code below.
	{
		CRect rc = GetDrawRect();

		int count = sizeof(types)/sizeof(BYTE);
		
		BYTE types1[9];
		CFODrawHelper::ConvertToBasicFlags(types,types1,count);
		
		CFOPVisualProxy::GetInstance()->PrepareTransparent(GetTransparentValue());
		CFOPVisualProxy::GetInstance()->FillNewPolygonBezier(pDC,rc,m_nCompPtCount,(fopPointExt *)m_lpShapePoints,
			types1,GetBkColor(),
			GetPatternColor(),GetBrushType(),GetBrush(pDC));
	}

}

void CExtWaveShape::OnDrawShadow(CDC *pDC)
{
//	CFODrawPortsShape::OnDrawShadow(pDC);


	{
		CPoint ptOffset = CPoint(GetShadowOffsetX(),GetShadowOffsetY());
		
		CPoint ptNew;
		// Hapy:Changed
		int i = 0;
		for (i = 0; i < m_nCompPtCount; i++)
		{
			ptNew = CPoint(m_lpShapePoints[i]);
			ptNew += ptOffset;
			m_lpShapePoints[i] = CPoint(ptNew);
		}
		
		CRect rc = CFODrawHelper::GetBoundRect(m_lpShapePoints,m_nCompPtCount);
		
		int count = sizeof(types)/sizeof(BYTE);
		
		BYTE types1[9];
		CFODrawHelper::ConvertToBasicFlags(types,types1,count);
		
		CFOPVisualProxy::GetInstance()->PrepareTransparent(GetTransparentValue());
		CFOPVisualProxy::GetInstance()->FillNewPolygonBezier(pDC,rc,m_nCompPtCount,(fopPointExt *)m_lpShapePoints,
			types1,GetShadowColor(),
			GetShadowPatternColor(),
			GetShadowBrushType(),GetShadowBrush(pDC));
		
		for (i = 0; i < m_nCompPtCount; i++)
		{
			ptNew = CPoint(m_lpShapePoints[i]);
			ptNew -= ptOffset;
			m_lpShapePoints[i] = CPoint(ptNew);
		}
	}
}

void CExtWaveShape::OnDraw3d(CDC *pDC)
{
	CFODrawPortsShape::OnDraw3d(pDC);
	
	//FODO:Add your own code below.

	{
		CRect rc = GetDrawRect();

		int count = sizeof(types)/sizeof(BYTE);
		
		BYTE types1[9];
		CFODrawHelper::ConvertToBasicFlags(types,types1,count);
		
		CFOPVisualProxy::GetInstance()->PrepareTransparent(GetTransparentValue());
		CFOPVisualProxy::GetInstance()->FillNewPolygonBezier(pDC,rc,m_nCompPtCount,(fopPointExt *)m_lpShapePoints,
			types1,GetBkColor(),
			GetPatternColor(),GetBrushType(),GetBrush(pDC));
	}

}

void CExtWaveShape::ClearDC(CDC* pDC)
{
	CFODrawPortsShape::ClearDC(pDC);

	//FODO:Add your own code below.

}

void CExtWaveShape::GeometryUpdated(CFOArea* pRgn)
{
// Example code:
	if (m_lpShapePoints && pRgn)
	{
		pRgn->BuildPolygonArea(m_lpShapePoints, m_nCompPtCount);
		m_rectPosition = pRgn->GetBoundingRect();
	}

}

BOOL CExtWaveShape::OffsetAnchorPoint(CPoint ptOffset)
{
	return CFODrawPortsShape::OffsetAnchorPoint(ptOffset);
}

BOOL CExtWaveShape::TrackOffsetAnchorPoint(CPoint ptOffset)
{
	return CFODrawPortsShape::TrackOffsetAnchorPoint(ptOffset);
}

BOOL CExtWaveShape::OffsetExtAnchorPoint(CPoint ptOffset)
{
	return CFODrawPortsShape::OffsetExtAnchorPoint(ptOffset);
}

BOOL CExtWaveShape::TrackOffsetExtAnchorPoint(CPoint ptOffset)
{
	return CFODrawPortsShape::TrackOffsetExtAnchorPoint(ptOffset);
}
