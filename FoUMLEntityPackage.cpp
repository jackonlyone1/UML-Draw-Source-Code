// FoUMLEntityPackage.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "FoUMLEntityPackage.h"

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
// CFoUMLEntityPackage Class
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CFoUMLEntityPackage, CFODrawPortsShape, 0)
CFoUMLEntityPackage::CFoUMLEntityPackage()
{
	//SetType(You own ID here); you must asign a new ID for this control.
	SetType(ID_FOP_SAMPLE_UML_PACKAGE);
	SetPatternColor(RGB(0,160,196));
	SetWithLabelEditing(FALSE);
	SetRotateProtect(TRUE);

	m_umlEntity = UMLEntityPackage;
	m_pEntityClass = new CUMLEntityPackage;
}

CFoUMLEntityPackage::CFoUMLEntityPackage(const CFoUMLEntityPackage& src)
{
	*this = src;
}

CFoUMLEntityPackage::~CFoUMLEntityPackage()
{
	_SafeDeletePtr(m_pEntityClass);
}

/////////////////////////////////////////////////////////////////////////////
// CFoUMLEntityPackage diagnostics

#ifdef _DEBUG
void CFoUMLEntityPackage::AssertValid() const
{
	CFODrawPortsShape::AssertValid();
}

void CFoUMLEntityPackage::Dump(CDumpContext& dc) const
{
	CFODrawPortsShape::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////

void CFoUMLEntityPackage::Create(CRect &rcPos,CString strCaption)
{
// Example code:
	AllocMemory(4);
	m_lpShapePoints[0] = CPoint(rcPos.left,  rcPos.top);
	m_lpShapePoints[1] = CPoint(rcPos.right, rcPos.top);
	m_lpShapePoints[2] = CPoint(rcPos.right, rcPos.bottom);
	m_lpShapePoints[3] = CPoint(rcPos.left,  rcPos.bottom);
	CFODrawPortsShape::Create(rcPos,strCaption);
	// Top
//	CreateDefaultPort(0.5,0.0);
	CreateDefaultPort(0.25,0.0);
//	CreateDefaultPort(0.75,0.0);
	
	// Left
	CreateDefaultPort(0.0,0.5);
	CreateDefaultPort(0.0,0.25);
	CreateDefaultPort(0.0,0.75);
	
	// Bottom
	CreateDefaultPort(1.0,0.25);
	CreateDefaultPort(1.0,0.5);
	CreateDefaultPort(1.0,0.75);
	
	// Right
	CreateDefaultPort(0.5,1.0);
	CreateDefaultPort(0.25,1.0);
	CreateDefaultPort(0.75,1.0);
}

void CFoUMLEntityPackage::Serialize(CArchive& ar)
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
CFile* CFoUMLEntityPackage::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
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

void CFoUMLEntityPackage::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CFoUMLEntityPackage::OpenDocument(LPCTSTR lpszPathName)
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

BOOL CFoUMLEntityPackage::SaveDocument(LPCTSTR lpszPathName)
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


CFoUMLEntityPackage& CFoUMLEntityPackage::operator=(const CFoUMLEntityPackage& src)
{
	(*(CFODrawPortsShape*)this) = src;

	m_pEntityClass = NULL;
	m_umlEntity = UMLNOEntity;
	SetEntityType(src.m_umlEntity);
	return (*this);
}

CFODrawShape* CFoUMLEntityPackage::Copy() const
{
	return (new CFoUMLEntityPackage(*this));
}

void CFoUMLEntityPackage::PrepareDC(CDC* pDC)
{
	CFODrawPortsShape::PrepareDC(pDC);

	//FODO:Add your own code below.
	
}

void CFoUMLEntityPackage::GetPathSimplePolygon(FOPSimpleCompositePolygon& rPoly) const
{
	CFODrawPortsShape::GetPathSimplePolygon(rPoly);

}

void CFoUMLEntityPackage::OnDrawTrackCustom(CDC *pDC)
{
	CFODrawPortsShape::OnDrawTrackCustom(pDC);

	// Add your own code here.
}

void CFoUMLEntityPackage::DoDrawVisioOrderLine(CDC *pDC)
{
	CFODrawPortsShape::DoDrawVisioOrderLine(pDC);

	//FODO:Add your own code below.
	
}

void CFoUMLEntityPackage::OnDrawFlat(CDC *pDC)
{
	CFODrawPortsShape::OnDrawFlat(pDC);

	//FODO:Add your own code below.

// Example code:
	FillPoly(pDC,m_lpShapePoints, m_nCompPtCount,GetBkColor(),
		GetPatternColor(),GetBrushType());

}

void CFoUMLEntityPackage::OnDrawShadow(CDC *pDC)
{
	CFODrawPortsShape::OnDrawShadow(pDC);

	//FODO:Add your own code below.

// Example code:
	FillShadowPoly(pDC,m_lpShapePoints, m_nCompPtCount);
}

void CFoUMLEntityPackage::OnDraw3d(CDC *pDC)
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

void CFoUMLEntityPackage::ClearDC(CDC* pDC)
{
	CFODrawPortsShape::ClearDC(pDC);

	//FODO:Add your own code below.
}

void CFoUMLEntityPackage::GeometryUpdated(CFOArea* pRgn)
{
// Example code:
	if (m_lpShapePoints && pRgn)
	{
		pRgn->BuildPolygonArea(m_lpShapePoints, m_nCompPtCount);
		m_rectPosition = pRgn->GetBoundingRect();
	}
}

void CFoUMLEntityPackage::SetEntityType(const FOP_UML_ENTITY &umlEntity)
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
