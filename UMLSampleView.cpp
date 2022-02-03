// UMLSampleView.cpp : implementation of the CUMLSampleView class
//

#include "stdafx.h"
#include "UMLSample.h"

#include "UMLSampleDoc.h"
#include "UMLSampleView.h"
#include "ChildFrm.h"
#include "UMLEntityClass.h"
#include "FoUMLEntityClass.h"
#include "FoUMLEntityInterface.h"
#include "FoUMLEntityLabel.h"
#include "FoUMLEntityNote.h"
#include "FoUMLEntityPackage.h"
#include "FoUMLEntitySegment.h"
#include "FoUMLEntityTemplate.h"
#include "FOActionStateShape.h"
#include "FONormalStateShape.h"
#include "FOUMLControlLineShape.h"
#include "FOObjectLineShape.h"
#include "ExtWaveShape.h"
#include "ExtActorShape.h"
#include "FOUMLStartShape.h"
#include "FOUMLEndShape.h"
#include "ExtCompShape.h"
#include "FOUMLComplexLineShape.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUMLSampleView

IMPLEMENT_DYNCREATE(CUMLSampleView, CFODrawView)
BEGIN_MESSAGE_MAP(CUMLSampleView,CFODrawView)
	//{{AFX_MSG_MAP(CUMLSampleView)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
	ON_COMMAND(ID_ADD_UML_CLASS, OnAddUmlClass)
	ON_COMMAND(ID_ADD_UML_TEMPLATE, OnAddUmlTemplate)
	ON_COMMAND(ID_ADD_UML_INTERFACE, OnAddUmlInterface)
	ON_COMMAND(ID_ADD_UML_LABEL, OnAddUmlLabel)
	ON_COMMAND(ID_ADD_UML_NOTE, OnAddUmlNote)
	ON_COMMAND(ID_ADD_UML_PACKAGE, OnAddUmlPackage)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_ADD_UML_OPEN, OnAddUmlOpen)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_PRINT, CFODrawView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFODrawView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUMLSampleView construction/destruction

CUMLSampleView::CUMLSampleView()
{
	// TODO: add construction code here
	m_ptStart = CPoint(100, 100);
}

CUMLSampleView::~CUMLSampleView()
{
}

BOOL CUMLSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREAFOAPPWIZARDRUCT cs
	return CFODrawView::PreCreateWindow(cs);

}

/////////////////////////////////////////////////////////////////////////////
// CUMLSampleView drawing

void CUMLSampleView::OnDraw(CDC* pDC)
{
	CUMLSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	Draw(pDC);
	// TODO: add draw code for native data here
}

void CUMLSampleView::DoChangeModel(CFODataModel * pModel)
{
	CFODrawView::DoChangeModel(pModel);
	// Adding your data model init codes here..
	CSize szCanvas = CSize(5000,5000);
	
	pModel->SetCanvasSize(szCanvas);
	GetCurrentModel()->SetGridLineType(GRID_DOT);
	GetCurrentModel()->SetGridColor(RGB(0,0,0));
}

void CUMLSampleView::OnInitialUpdate()
{
	SetCurrentModel(GetDocument()->m_pDataModel);
	CFODrawView::OnInitialUpdate();

}

/////////////////////////////////////////////////////////////////////////////
// CUMLSampleView printing

BOOL CUMLSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{

	// default preparation
	return CFODrawView::OnPreparePrinting(pInfo);

}

void CUMLSampleView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: add extra initialization before printing
	// E-XD++ Library Add line.
	CFODrawView::OnBeginPrinting(pDC,pInfo);
}

void CUMLSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CUMLSampleView::OnFilePrintPreview() 
{
	FOPrintPreview(this);
}

void CUMLSampleView::InitLinkShape()
{
	m_drawshape = FO_COMP_UPRIGHTLINK;
	m_bUpRightMode = FALSE;
	SetCurrentDrawingCursor(IDC_FO_DRAWLINK_CURSOR);
}

void CUMLSampleView::OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo,
							  POINT pt, CPreviewView* pView) 
{
	CScrollView::OnEndPrintPreview(pDC, pInfo,pt, pView); 

}

/////////////////////////////////////////////////////////////////////////////
// CUMLSampleView diagnostics

#ifdef _DEBUG
void CUMLSampleView::AssertValid() const
{
//E-XD++ Library add lines.
	CFODrawView::AssertValid();


	//CView::AssertValid();
}

void CUMLSampleView::Dump(CDumpContext& dc) const
{
//E-XD++ Library add lines.
	CFODrawView::Dump(dc);


	//CView::Dump(dc);
}

CUMLSampleDoc* CUMLSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUMLSampleDoc)));
	return (CUMLSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUMLSampleView message handlers
//E-XD++ Library add line.
void CUMLSampleView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	//CView::OnPrint(pDC, pInfo);
	//E-XD++ Library Add line.
	CFODrawView::OnPrint(pDC,pInfo);
}

CFoUMLEntityClass *CUMLSampleView::CreateUmlEntity(const CFoUMLEntityClass::FOP_UML_ENTITY &entityType)
{
	CFoUMLEntityClass *pEntityNode;
	pEntityNode = new CFoUMLEntityClass;
	
	m_ptStart.Offset(25, 25);
		
	CRect rcPos = CRect(m_ptStart, CSize(160,150));
	pEntityNode->AddRef();
	pEntityNode->Create(rcPos, _T("Class"));
	GetCurrentModel()->AddChildAtTail(pEntityNode);
		
	pEntityNode->UpdateComp();
	pEntityNode->Release();	

	ASSERT(pEntityNode);
	
	pEntityNode->SetEntityType(entityType);

	InvalidateShape(pEntityNode);

	return pEntityNode;
}

void CUMLSampleView::OnAddUmlClass() 
{
	// TODO: Add your command handler code here

	CreateUmlEntity(CFoUMLEntityClass::UMLEntityClass);
}

void CUMLSampleView::OnAddUmlTemplate() 
{
	// TODO: Add your command handler code here
	
	CreateUmlEntity(CFoUMLEntityClass::UMLEntityClassTemplate);
}

void CUMLSampleView::OnAddUmlInterface() 
{
	// TODO: Add your command handler code here
	
	CreateUmlEntity(CFoUMLEntityClass::UMLEntityInterface);
}

void CUMLSampleView::OnAddUmlLabel() 
{
	// TODO: Add your command handler code here
	
	CreateUmlEntity(CFoUMLEntityClass::UMLEntityLabel);
}

void CUMLSampleView::OnAddUmlNote() 
{
	// TODO: Add your command handler code here
	
	CreateUmlEntity(CFoUMLEntityClass::UMLEntityNote);
}

void CUMLSampleView::OnAddUmlPackage() 
{
	// TODO: Add your command handler code here
	
	CreateUmlEntity(CFoUMLEntityClass::UMLEntityPackage);
}

void CUMLSampleView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CFODrawShape *pShape = GetCurrentSelectShape();

	if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityClass)))
	{
		CFoUMLEntityClass *pUMLEntity = static_cast<CFoUMLEntityClass *>(pShape);
		ASSERT(pUMLEntity);
		pUMLEntity->m_pEntityClass->ShowProperties(this, TRUE);
	}
	else if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityInterface)))
	{
		CFoUMLEntityInterface *pUMLEntity = static_cast<CFoUMLEntityInterface *>(pShape);
		ASSERT(pUMLEntity);
		pUMLEntity->m_pEntityClass->ShowProperties(this, TRUE);
	}
	else if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityLabel)))
	{
		CFoUMLEntityLabel *pUMLEntity = static_cast<CFoUMLEntityLabel *>(pShape);
		ASSERT(pUMLEntity);
		pUMLEntity->m_pEntityClass->ShowProperties(this, TRUE);
	}
	else if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityNote)))
	{
		CFoUMLEntityNote *pUMLEntity = static_cast<CFoUMLEntityNote *>(pShape);
		ASSERT(pUMLEntity);
		pUMLEntity->m_pEntityClass->ShowProperties(this, TRUE);
	}
	else if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityPackage)))
	{
		CFoUMLEntityPackage *pUMLEntity = static_cast<CFoUMLEntityPackage *>(pShape);
		ASSERT(pUMLEntity);
		pUMLEntity->m_pEntityClass->ShowProperties(this, TRUE);
	}
	else if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityTemplate)))
	{
		CFoUMLEntityTemplate *pUMLEntity = static_cast<CFoUMLEntityTemplate *>(pShape);
		ASSERT(pUMLEntity);
		pUMLEntity->m_pEntityClass->ShowProperties(this, TRUE);
	}
	
	CFODrawView::OnLButtonDblClk(nFlags, point);
}

void CUMLSampleView::DoGenInitItems(CFODrawShape *pShape)
{
	ClearAllAdditionalHandle();
	CFODrawView::DoGenInitItems(pShape);
	if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityClass)))
	{
		AddNewAdditionalHandle(new CFOPSelectHandleItem(31056));
		AddNewAdditionalHandle(new CFOPSelectHandleItem(31057));
	}
	else if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityInterface)))
	{
		AddNewAdditionalHandle(new CFOPSelectHandleItem(31056));
	}
	else if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityLabel)))
	{
		AddNewAdditionalHandle(new CFOPSelectHandleItem(31056));
	}
	else if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityNote)))
	{
		AddNewAdditionalHandle(new CFOPSelectHandleItem(31056));
	}
	else if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityPackage)))
	{
		AddNewAdditionalHandle(new CFOPSelectHandleItem(31056));
	}
	else if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityTemplate)))
	{
		AddNewAdditionalHandle(new CFOPSelectHandleItem(31056));
		AddNewAdditionalHandle(new CFOPSelectHandleItem(31057));
	}

}

void CUMLSampleView::DoWhenClickAddi()
{
	if(m_nCurHitAddiType == 31056)
	{
		CFODrawShape *pShape = GetCurrentSelectShape();
		
		if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityClass)))
		{
			CFoUMLEntityClass *pUMLEntity = static_cast<CFoUMLEntityClass *>(pShape);
			ASSERT(pUMLEntity);
			pUMLEntity->m_pEntityClass->ShowProperties(this, TRUE);
		}
		else if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityInterface)))
		{
			CFoUMLEntityInterface *pUMLEntity = static_cast<CFoUMLEntityInterface *>(pShape);
			ASSERT(pUMLEntity);
			pUMLEntity->m_pEntityClass->ShowProperties(this, TRUE);
		}
		else if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityLabel)))
		{
			CFoUMLEntityLabel *pUMLEntity = static_cast<CFoUMLEntityLabel *>(pShape);
			ASSERT(pUMLEntity);
			pUMLEntity->m_pEntityClass->ShowProperties(this, TRUE);
		}
		else if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityNote)))
		{
			CFoUMLEntityNote *pUMLEntity = static_cast<CFoUMLEntityNote *>(pShape);
			ASSERT(pUMLEntity);
			pUMLEntity->m_pEntityClass->ShowProperties(this, TRUE);
		}
		else if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityPackage)))
		{
			CFoUMLEntityPackage *pUMLEntity = static_cast<CFoUMLEntityPackage *>(pShape);
			ASSERT(pUMLEntity);
			pUMLEntity->m_pEntityClass->ShowProperties(this, TRUE);
		}
		else if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityTemplate)))
		{
			CFoUMLEntityTemplate *pUMLEntity = static_cast<CFoUMLEntityTemplate *>(pShape);
			ASSERT(pUMLEntity);
			pUMLEntity->m_pEntityClass->ShowProperties(this, TRUE);
		}
	}
	else if(m_nCurHitAddiType == 31057)
	{
		CFODrawShape *pShape = GetCurrentSelectShape();
		
		if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityClass)))
		{
			CFoUMLEntityClass *pEntityNode = static_cast<CFoUMLEntityClass *>(pShape);
			ASSERT(pEntityNode);
			CFileDialog	dlg( TRUE, _T( "h" ), _T( "*.h" ) );
			if(IDOK ==  dlg.DoModal())
			{
				((CUMLEntityClass *)pEntityNode->m_pEntityClass)->ImportH(dlg.GetPathName());
				CSize sz = ((CUMLEntityClass *)pEntityNode->m_pEntityClass)->GetMinimumSize();
				
				CRect rc = pEntityNode->GetSnapRect();
				pEntityNode->PositionShape(CRect(rc.TopLeft(), sz));
				
				InvalidateShape(pEntityNode);
			}
	
		}
		else if (NULL != pShape && pShape->IsKindOf(RUNTIME_CLASS(CFoUMLEntityTemplate)))
		{
			CFoUMLEntityTemplate *pEntityNode = static_cast<CFoUMLEntityTemplate *>(pShape);
			ASSERT(pEntityNode);
			CFileDialog	dlg( TRUE, _T( "h" ), _T( "*.h" ) );
			if(IDOK ==  dlg.DoModal())
			{
				((CUMLEntityClass *)pEntityNode->m_pEntityClass)->ImportH(dlg.GetPathName());
				CSize sz = ((CUMLEntityClass *)pEntityNode->m_pEntityClass)->GetMinimumSize();
				
				CRect rc = pEntityNode->GetSnapRect();
				pEntityNode->PositionShape(CRect(rc.TopLeft(), sz));
				
				InvalidateShape(pEntityNode);
			}
		}
	}
	else
	{
		CFODrawView::DoWhenClickAddi();
	}
}


void CUMLSampleView::OnAddUmlOpen() 
{
	// TODO: Add your command handler code here

	CFoUMLEntityClass *pEntityNode = CreateUmlEntity(CFoUMLEntityClass::UMLEntityClass);
	if (CFoUMLEntityClass::UMLEntityClass == pEntityNode->m_umlEntity)
	{
		CFileDialog	dlg( TRUE, _T( "h" ), _T( "*.h" ) );
		if(IDOK ==  dlg.DoModal())
		{
			((CUMLEntityClass *)pEntityNode->m_pEntityClass)->ImportH(dlg.GetPathName());
			CSize sz = ((CUMLEntityClass *)pEntityNode->m_pEntityClass)->GetMinimumSize();

			CRect rc = pEntityNode->GetSnapRect();
			pEntityNode->PositionShape(CRect(rc.TopLeft(), sz));

			InvalidateShape(pEntityNode);
		}
	}
}
