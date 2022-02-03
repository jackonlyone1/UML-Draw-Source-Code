// FoUMLEntityNote.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "FoUMLEntityNote.h"

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
// CFoUMLEntityNote Class
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CFoUMLEntityNote, CFODrawPortsShape, 0)
CFoUMLEntityNote::CFoUMLEntityNote()
{
	//SetType(You own ID here); you must asign a new ID for this control.
	SetType(ID_FOP_SAMPLE_UML_NOTE);
	SetPatternColor(RGB(0,160,196));
	SetWithLabelEditing(FALSE);
	SetRotateProtect(TRUE);

	m_umlEntity = UMLEntityNote;
	m_pEntityClass = new CUMLEntityNote;
}

CFoUMLEntityNote::CFoUMLEntityNote(const CFoUMLEntityNote& src)
{
	*this = src;
}

CFoUMLEntityNote::~CFoUMLEntityNote()
{
	_SafeDeletePtr(m_pEntityClass);
}

/////////////////////////////////////////////////////////////////////////////
// CFoUMLEntityNote diagnostics

#ifdef _DEBUG
void CFoUMLEntityNote::AssertValid() const
{
	CFODrawPortsShape::AssertValid();
}

void CFoUMLEntityNote::Dump(CDumpContext& dc) const
{
	CFODrawPortsShape::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////

void CFoUMLEntityNote::Create(CRect &rcPos,CString strCaption)
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

void CFoUMLEntityNote::Serialize(CArchive& ar)
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
CFile* CFoUMLEntityNote::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
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

void CFoUMLEntityNote::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CFoUMLEntityNote::OpenDocument(LPCTSTR lpszPathName)
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

BOOL CFoUMLEntityNote::SaveDocument(LPCTSTR lpszPathName)
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


CFoUMLEntityNote& CFoUMLEntityNote::operator=(const CFoUMLEntityNote& src)
{
	(*(CFODrawPortsShape*)this) = src;

	m_pEntityClass = NULL;
	m_umlEntity = UMLNOEntity;
	SetEntityType(src.m_umlEntity);
	return (*this);
}

CFODrawShape* CFoUMLEntityNote::Copy() const
{
	return (new CFoUMLEntityNote(*this));
}

void CFoUMLEntityNote::PrepareDC(CDC* pDC)
{
	CFODrawPortsShape::PrepareDC(pDC);

	//FODO:Add your own code below.
	
}

void CFoUMLEntityNote::GetPathSimplePolygon(FOPSimpleCompositePolygon& rPoly) const
{
	CFODrawPortsShape::GetPathSimplePolygon(rPoly);

}

void CFoUMLEntityNote::OnDrawTrackCustom(CDC *pDC)
{
	CFODrawPortsShape::OnDrawTrackCustom(pDC);

	// Add your own code here.
}

void CFoUMLEntityNote::DoDrawVisioOrderLine(CDC *pDC)
{
	CFODrawPortsShape::DoDrawVisioOrderLine(pDC);

	//FODO:Add your own code below.
	
}

void CFoUMLEntityNote::OnDrawFlat(CDC *pDC)
{
	CFODrawPortsShape::OnDrawFlat(pDC);

	//FODO:Add your own code below.

// Example code:
	FillPoly(pDC,m_lpShapePoints, m_nCompPtCount,GetBkColor(),
		GetPatternColor(),GetBrushType());

}

void CFoUMLEntityNote::OnDrawShadow(CDC *pDC)
{
	CFODrawPortsShape::OnDrawShadow(pDC);

	//FODO:Add your own code below.

// Example code:
	FillShadowPoly(pDC,m_lpShapePoints, m_nCompPtCount);
}

void CFoUMLEntityNote::OnDraw3d(CDC *pDC)
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

void CFoUMLEntityNote::ClearDC(CDC* pDC)
{
	CFODrawPortsShape::ClearDC(pDC);

	//FODO:Add your own code below.
}

void CFoUMLEntityNote::GeometryUpdated(CFOArea* pRgn)
{
// Example code:
	if (m_lpShapePoints && pRgn)
	{
		pRgn->BuildPolygonArea(m_lpShapePoints, m_nCompPtCount);
		m_rectPosition = pRgn->GetBoundingRect();
	}
}

void CFoUMLEntityNote::SetEntityType(const FOP_UML_ENTITY &umlEntity)
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
