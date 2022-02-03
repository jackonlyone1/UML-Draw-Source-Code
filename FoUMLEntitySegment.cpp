// FoUMLEntitySegment.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "FoUMLEntitySegment.h"

#include "UMLEntityClass.h"
#include "UMLLineSegment.h"
#include "UMLEntityNote.h"
#include "UMLEntityPackage.h"
#include "UMLEntityLabel.h"
#include "UMLEntityInterface.h"
#include "UMLEntityClassTemplate.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// CFoUMLEntitySegment Class
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CFoUMLEntitySegment, CFODrawPortsShape, 0)
CFoUMLEntitySegment::CFoUMLEntitySegment()
{
	//SetType(You own ID here); you must asign a new ID for this control.
	SetType(ID_FOP_SAMPLE_UML_SEGMENT);
	SetPatternColor(RGB(0,160,196));
	SetWithLabelEditing(FALSE);
	SetRotateProtect(TRUE);

	m_umlEntity = UMLLineSegment;
	m_pEntityClass = new CUMLLineSegment;
}

CFoUMLEntitySegment::CFoUMLEntitySegment(const CFoUMLEntitySegment& src)
{
	*this = src;
}

CFoUMLEntitySegment::~CFoUMLEntitySegment()
{
	_SafeDeletePtr(m_pEntityClass);
}

/////////////////////////////////////////////////////////////////////////////
// CFoUMLEntitySegment diagnostics

#ifdef _DEBUG
void CFoUMLEntitySegment::AssertValid() const
{
	CFODrawPortsShape::AssertValid();
}

void CFoUMLEntitySegment::Dump(CDumpContext& dc) const
{
	CFODrawPortsShape::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////

void CFoUMLEntitySegment::Create(CRect &rcPos,CString strCaption)
{
// Example code:
	AllocMemory(4);
	m_lpShapePoints[0] = CPoint(rcPos.left,  rcPos.top);
	m_lpShapePoints[1] = CPoint(rcPos.right, rcPos.top);
	m_lpShapePoints[2] = CPoint(rcPos.right, rcPos.bottom);
	m_lpShapePoints[3] = CPoint(rcPos.left,  rcPos.bottom);
	CFODrawPortsShape::Create(rcPos,strCaption);
	CreateDefaultPort(0.5,0.5);
}

void CFoUMLEntitySegment::Serialize(CArchive& ar)
{
	CFODrawPortsShape::Serialize(ar);
	if(ar.IsStoring())
	{
		//FODO:Add your own code here.
		ar << (int)m_umlEntity;	
		CString strTemp = m_pEntityClass->GetString();
		ar << strTemp;
	}
	else
	{
		//FODO:Add your own code here.
		int nTemp = UMLNOEntity;
		ar >> nTemp;
		m_umlEntity = (FOP_UML_ENTITY)nTemp;

		CString strTemp = _T("");
		ar >> strTemp;

		_SafeDeletePtr(m_pEntityClass);
		switch (m_umlEntity)
		{
		case UMLEntityClass:
			m_pEntityClass = CUMLEntityClass::CreateFromString(strTemp);
			break;
		case UMLLineSegment:
			m_pEntityClass = CUMLLineSegment::CreateFromString(strTemp);
			break;
		case UMLEntityNote:
			m_pEntityClass = CUMLEntityNote::CreateFromString(strTemp);
			break;
		case UMLEntityPackage:
			m_pEntityClass = CUMLEntityPackage::CreateFromString(strTemp);
			break;
		case UMLEntityLabel:
			m_pEntityClass = CUMLEntityLabel::CreateFromString(strTemp);
			break;
		case UMLEntityInterface:
			m_pEntityClass = CUMLEntityInterface::CreateFromString(strTemp);
			break;
		case UMLEntityClassTemplate:
			m_pEntityClass = CUMLEntityClassTemplate::CreateFromString(strTemp);
			break;
		default:
			m_pEntityClass = CUMLEntityClass::CreateFromString(strTemp);
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPrintBaseJob serialization
CFile* CFoUMLEntitySegment::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
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

void CFoUMLEntitySegment::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CFoUMLEntitySegment::OpenDocument(LPCTSTR lpszPathName)
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

BOOL CFoUMLEntitySegment::SaveDocument(LPCTSTR lpszPathName)
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


CFoUMLEntitySegment& CFoUMLEntitySegment::operator=(const CFoUMLEntitySegment& src)
{
	(*(CFODrawPortsShape*)this) = src;

	m_pEntityClass = NULL;
	m_umlEntity = UMLNOEntity;
	SetEntityType(src.m_umlEntity);
	return (*this);
}

CFODrawShape* CFoUMLEntitySegment::Copy() const
{
	return (new CFoUMLEntitySegment(*this));
}

void CFoUMLEntitySegment::PrepareDC(CDC* pDC)
{
	CFODrawPortsShape::PrepareDC(pDC);

	//FODO:Add your own code below.
	
}

void CFoUMLEntitySegment::GetPathSimplePolygon(FOPSimpleCompositePolygon& rPoly) const
{
	CFODrawPortsShape::GetPathSimplePolygon(rPoly);

}

void CFoUMLEntitySegment::OnDrawTrackCustom(CDC *pDC)
{
	CFODrawPortsShape::OnDrawTrackCustom(pDC);

	// Add your own code here.
}

void CFoUMLEntitySegment::DoDrawVisioOrderLine(CDC *pDC)
{
	CFODrawPortsShape::DoDrawVisioOrderLine(pDC);

	//FODO:Add your own code below.
	
}

void CFoUMLEntitySegment::OnDrawFlat(CDC *pDC)
{
	CFODrawPortsShape::OnDrawFlat(pDC);

	//FODO:Add your own code below.

// Example code:
	FillPoly(pDC,m_lpShapePoints, m_nCompPtCount,GetBkColor(),
		GetPatternColor(),GetBrushType());

}

void CFoUMLEntitySegment::OnDrawShadow(CDC *pDC)
{
	CFODrawPortsShape::OnDrawShadow(pDC);

	//FODO:Add your own code below.

// Example code:
	FillShadowPoly(pDC,m_lpShapePoints, m_nCompPtCount);
}

void CFoUMLEntitySegment::OnDraw3d(CDC *pDC)
{
	CFODrawPortsShape::OnDraw3d(pDC);
	
	//FODO:Add your own code below.

	if (NULL != m_pEntityClass)
	{
		m_pEntityClass->SetFont(GetFaceName());
		m_pEntityClass->SetFontSize(GetPointSize());
		m_pEntityClass->Draw(pDC, GetSnapRect());
	}
	else
	{
		FillPoly(pDC,m_lpShapePoints, m_nCompPtCount,GetBkColor(), GetPatternColor(),GetBrushType());
	}
}

void CFoUMLEntitySegment::ClearDC(CDC* pDC)
{
	CFODrawPortsShape::ClearDC(pDC);

	//FODO:Add your own code below.
}

void CFoUMLEntitySegment::GeometryUpdated(CFOArea* pRgn)
{
// Example code:
	if (m_lpShapePoints && pRgn)
	{
		pRgn->BuildPolygonArea(m_lpShapePoints, m_nCompPtCount);
		m_rectPosition = pRgn->GetBoundingRect();
	}
}

void CFoUMLEntitySegment::SetEntityType(const FOP_UML_ENTITY &umlEntity)
{
	if (m_umlEntity == umlEntity)
		return;
	else
		m_umlEntity = umlEntity;

	_SafeDeletePtr(m_pEntityClass);

	switch (umlEntity)
	{
	case UMLEntityClass:
		m_pEntityClass = new CUMLEntityClass;
		break;
	case UMLLineSegment:
		m_pEntityClass = new CUMLLineSegment;
		break;
	case UMLEntityNote:
		m_pEntityClass = new CUMLEntityNote;
		break;
	case UMLEntityPackage:
		m_pEntityClass = new CUMLEntityPackage;
		break;
	case UMLEntityLabel:
		m_pEntityClass = new CUMLEntityLabel;
		break;
	case UMLEntityInterface:
		m_pEntityClass = new CUMLEntityInterface;
		break;
	case UMLEntityClassTemplate:
		m_pEntityClass = new CUMLEntityClassTemplate;
		break;
	default:
		m_pEntityClass = new CUMLEntityClass;
		break;
	}
}
