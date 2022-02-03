// UMLSampleDoc.cpp : implementation of the CUMLSampleDoc class
//

#include "stdafx.h"
#include "UMLSample.h"

#include "UMLSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUMLSampleDoc

IMPLEMENT_DYNCREATE(CUMLSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CUMLSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CUMLSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUMLSampleDoc construction/destruction

CUMLSampleDoc::CUMLSampleDoc()
{
	// TODO: add one-time construction code here
	//E-XD++ Library add lines.
	m_pDataModel = new CExtDataModel;
}

CUMLSampleDoc::~CUMLSampleDoc()
{
	//E-XD++ Library add lines.
	if(m_pDataModel != NULL)
	{
		delete m_pDataModel;
		m_pDataModel = NULL;
	}
}

BOOL CUMLSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CUMLSampleDoc serialization

void CUMLSampleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		//E-XD++ Library add lines.	
		m_pDataModel->Serialize(ar);
	}
	else
	{
		// TODO: add loading code here
		//E-XD++ Library add lines.	
		m_pDataModel->Serialize(ar);
	}
}


//E-XD++ Library add lines.
void CUMLSampleDoc::SetTitle(LPCTSTR lpszTitle)
{
	m_pDataModel->SetDocTitle(lpszTitle);
	CDocument::SetTitle(lpszTitle);
}

void CUMLSampleDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	m_pDataModel->ResetContent();
	CDocument::DeleteContents();
}

//added override
BOOL CUMLSampleDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnSaveDocument(lpszPathName))
	{
		return FALSE;
	}
	m_pDataModel->SetClean();		// Tells the command history that the document is "clean" at this point
	SetModifiedFlag(FALSE);
	return TRUE;
}

//added override (optional as long as you never call this member)
void CUMLSampleDoc::SetModifiedFlag(BOOL b)
{
	// Do nothing
	m_pDataModel->SetModifiedFlag(b);
}

//added override
BOOL CUMLSampleDoc::IsModified()
{
	return m_pDataModel->IsModified();
}

BOOL CUMLSampleDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if(!CDocument::OnOpenDocument(lpszPathName))
	{
		return FALSE;
	}
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CUMLSampleDoc diagnostics

#ifdef _DEBUG
void CUMLSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUMLSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUMLSampleDoc commands
