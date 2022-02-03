// ExtDataModel.cpp: implementation of the CExtDataModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ExtDataModel.h"
#include "UMLSample.h"
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
#include "FOUMLSimpleLineShape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CExtDataModel construction/destruction

IMPLEMENT_SERIAL(CExtDataModel, CFODataModel, 0)

CExtDataModel::CExtDataModel()
{
	//FOTO:Add you code here.
}

CExtDataModel::CExtDataModel(const CExtDataModel& source)
{
	*this			= source;
}

CExtDataModel::~CExtDataModel()
{
	//FOTO:Add you code here.

}

CFODataModel* CExtDataModel::Copy() const
{
	return (new CExtDataModel(*this));
}

CExtDataModel& CExtDataModel::operator=(const CExtDataModel& source)
{
	(*(CFODataModel*)this) = source;

	return (*this);
}

void CExtDataModel::DoInitData()
{
	CFODataModel::DoInitData();

	//FOTO:Add you code here.

}

void CExtDataModel::DoInitCreateShape(CFODrawShape *pShape)
{
	CFODataModel::DoInitCreateShape(pShape);
}

void CExtDataModel::NotifyObserver(LPARAM lHint, CObject*pHint)
{
	CFODataModel::NotifyObserver(lHint,pHint);

	//FOTO:Add you code here.

}

void CExtDataModel::UpdateTitle()
{
	CFODataModel::UpdateTitle();

//	if(m_pOwner == NULL)
//	{
//		return;
//	}
//
//	if(m_pOwner->GetSafeHwnd() != NULL)
//	{
//		if(m_pOwner ->IsKindOf(RUNTIME_CLASS(CFODrawView)))
//		{
//			CFODrawView *pView = (CFODrawView *) m_pOwner;
//			CDocument *m_pDocument = (CDocument *)pView->GetDocument();
//			if(m_pDocument != NULL)
//			{
//				if (m_strTitleOrg.IsEmpty() && !m_pDocument->GetTitle().IsEmpty())
//					m_strTitleOrg = m_pDocument->GetTitle();
//				
//				if (!m_strTitleOrg.IsEmpty())
//				{
//					TCHAR szStr[256+_MAX_PATH];
//					_tcscpy(szStr, m_strTitleOrg);
//					if (IsDirty())
//					{
//						if(m_strTitleOrg.Find(_T("*"))<0)
//						{
//							lstrcat(szStr, _T(" *"));
//						}
//					}
//					if (m_pDocument->GetTitle() != szStr)
//					{
//						m_pDocument->SetTitle(szStr);
//						m_pDocument->UpdateFrameCounts();
//					}
//				}
//			}
//		}
//	}
}

void CExtDataModel::DoActionChange(const CFOBaseAction* pAction)
{
	CFODataModel::DoActionChange(pAction);
	
	// FODO:Add your own specify code here.

}


CString CExtDataModel::CreateBaseName(UINT nType)
{
	/*switch(nType)
	{
	case MY_DROPMENUBUTTON:
		{
			return _T("DropMenuButton");
		}
		break;

	case MY_DROPCOLORBUTTON:
		{
			return _T("DropColorButton");
		}
		break;

	default:
		{*/
			return CFODataModel::CreateBaseName(nType);
		/*}
		break;
	}*/

}

CString CExtDataModel::CreateBaseCaption(UINT nType)
{
	/*switch(nType)
	{
	case MY_DROPMENUBUTTON:
		{
			return _T("Drop Menu Button");
		}
		break;

	case MY_DROPCOLORBUTTON:
		{
			return _T("Color");
		}
		break;

	default:
		{*/
			return CFODataModel::CreateBaseCaption(nType);
		/*}
		break;
	}*/

}

CString CExtDataModel::GetUniqueName(UINT nType)
{
	return CFODataModel::GetUniqueName(nType);
}

CString CExtDataModel::GetUniqueCaption(UINT nType)
{

	return CFODataModel::GetUniqueCaption(nType);
}

CFODrawShape *CExtDataModel::DoCreateShapeByType(UINT m_drawshape,
														CRect &rcCreate,
														CString strFileName,
														CFOToolBoxItem *pCurItem)
{
	CFODrawShape *pReturn = NULL;
	CString strCaption;
	CString strName;
	strCaption = "";
	strName = "";
	CPoint ptTrack = rcCreate.TopLeft();
	if(m_drawshape != FO_COMP_NONE)
	{
		CRect rc(rcCreate);
		rc.NormalizeRect();
		if(rc.IsRectEmpty()||(rc.Width()<=10 && rc.Height()<20))
		{
			switch(m_drawshape)
			{
			case ID_FOP_SAMPLE_UML_CLASS:
				{
					rc = CRect(ptTrack.x-80,ptTrack.y-85,ptTrack.x+80,ptTrack.y+85);
				}
				break;

			case ID_FOP_SAMPLE_UML_INTERFACE:
				{
					rc = CRect(ptTrack.x-20,ptTrack.y-20,ptTrack.x+20,ptTrack.y+20);
				}
				break;

			case ID_FOP_SAMPLE_UML_LABEL:
				{
					rc = CRect(ptTrack.x-80,ptTrack.y-65,ptTrack.x+80,ptTrack.y+65);
				}
				break;

			case ID_FOP_SAMPLE_UML_NOTE:
				{
					rc = CRect(ptTrack.x-80,ptTrack.y-65,ptTrack.x+80,ptTrack.y+65);
				}
				break;

			case ID_FOP_SAMPLE_UML_PACKAGE:
				{
					rc = CRect(ptTrack.x-80,ptTrack.y-65,ptTrack.x+80,ptTrack.y+65);
				}
				break;

			case ID_FOP_SAMPLE_UML_SEGMENT:
				{
					rc = CRect(ptTrack.x-80,ptTrack.y-15,ptTrack.x+80,ptTrack.y+15);
				}
				break;

			case ID_FOP_SAMPLE_UML_TEMPLATE:
				{
					rc = CRect(ptTrack.x-80,ptTrack.y-85,ptTrack.x+80,ptTrack.y+85);
				}
				break;

			case ID_FOP_SAMPLE_UML_ACTION_STATE:
				{
					rc = CRect(ptTrack.x-80,ptTrack.y-45,ptTrack.x+80,ptTrack.y+45);
				}
				break;

			case EXT_WAVE_SHAPE:
			case ID_FOP_SAMPLE_UML_NORMAL_STATE:
				{
					rc = CRect(ptTrack.x-80,ptTrack.y-45,ptTrack.x+80,ptTrack.y+45);
				}
				break;

			case ID_FOP_SAMPLE_UML_OBJECT_LINE:
			case ID_FOP_SAMPLE_UML_CONTROL_LINE:
				{
					rc = CRect(ptTrack.x-80,ptTrack.y-45,ptTrack.x+80,ptTrack.y+45);
				}
				break;

			case EXT_ACTOR_SHAPE:
				{
					rc = CRect(ptTrack.x-30,ptTrack.y-55,ptTrack.x+30,ptTrack.y+55);
				}
				break;
				
			case EXT_START_SHAPE:
				{
					rc = CRect(ptTrack.x-30,ptTrack.y-30,ptTrack.x+30,ptTrack.y+30);
				}
				break;

			case EXT_END_SHAPE:
				{
					rc = CRect(ptTrack.x-30,ptTrack.y-30,ptTrack.x+30,ptTrack.y+30);
				}
				break;	
			case EXT_COMP_SHAPE:
				{
					rc = CRect(ptTrack.x-70,ptTrack.y-50,ptTrack.x+70,ptTrack.y+50);
				}
				break;

			case ID_FOP_SAMPLE_SIMPLE_LINE:
			case ID_FOP_SAMPLE_COMPLEX_LINE:
				{
					rc = CRect(ptTrack.x-80,ptTrack.y-45,ptTrack.x+80,ptTrack.y+45);
				}
				break;

			default:
				{
				}
				break;
			}
		}

		switch(m_drawshape)
		{
		case ID_FOP_SAMPLE_SIMPLE_LINE:
			{
				pReturn = new CFOUMLSimpleLineShape;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
			break;

		case ID_FOP_SAMPLE_COMPLEX_LINE:
			{
				pReturn = new CFOUMLComplexLineShape;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
			break;
				
		case EXT_COMP_SHAPE:
			{
				pReturn = new CExtCompShape;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
			break;
			
		case EXT_START_SHAPE:
			{
				pReturn = new CFOUMLStartShape;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
			break;
			
		case EXT_END_SHAPE:
			{
				pReturn = new CFOUMLEndShape;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
				break;	
				
		case ID_FOP_SAMPLE_UML_CLASS:
			{
				pReturn = new CFoUMLEntityClass;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
			break;
			
		case ID_FOP_SAMPLE_UML_INTERFACE:
			{
				pReturn = new CFoUMLEntityInterface;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
			break;

		case ID_FOP_SAMPLE_UML_LABEL:
			{
				pReturn = new CFoUMLEntityLabel;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
			break;

		case ID_FOP_SAMPLE_UML_NOTE:
			{
				pReturn = new CFoUMLEntityNote;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
			break;

		case ID_FOP_SAMPLE_UML_PACKAGE:
			{
				pReturn = new CFoUMLEntityPackage;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
			break;

		case ID_FOP_SAMPLE_UML_SEGMENT:
			{
				pReturn = new CFoUMLEntitySegment;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
			break;

		case ID_FOP_SAMPLE_UML_TEMPLATE:
			{
				pReturn = new CFoUMLEntityTemplate;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
			break;

		case ID_FOP_SAMPLE_UML_ACTION_STATE:
			{
				pReturn = new CFOActionStateShape;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = _T("Action State");//GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
			break;

		case ID_FOP_SAMPLE_UML_NORMAL_STATE:
			{
				pReturn = new CFONormalStateShape;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = _T("State");//GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
			break;

		case ID_FOP_SAMPLE_UML_CONTROL_LINE:
			{
				pReturn = new CFOUMLControlLineShape;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = _T("State");//GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
			break;	

		case ID_FOP_SAMPLE_UML_OBJECT_LINE:
			{
				pReturn = new CFOObjectLineShape;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = _T("State");//GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
			break;

		case EXT_WAVE_SHAPE:
			{
				pReturn = new CExtWaveShape;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
			break;

		case EXT_ACTOR_SHAPE:
			{
				pReturn = new CExtActorShape;
				pReturn->AddRef();
				pReturn->Create(rc,"");
				pReturn->UpdatePosition();
				strCaption = GetUniqueCaption(pReturn->GetType());
				strName = GetUniqueName(pReturn->GetType());
				pReturn->SetObjectCaption(strCaption);
				pReturn->SetObjectName(strName);
			}
			break;

		default:
			{
				pReturn = CFODataModel::DoCreateShapeByType(m_drawshape,rcCreate,strFileName);
			}
			break;
		}
	}
	return pReturn;
}

CFOCompositeShape *CExtDataModel::DoCreateCompositeShapeByType(UINT m_drawshape,
																  CRect &rcCreate,
																  CArray<FOPORTVALUE,FOPORTVALUE> *arInitPorts,
																  CString strFileName,
																  UINT nResID,
																  CFOToolBoxItem *pCurItem)
{
	CFOCompositeShape *pReturn = CFODataModel::DoCreateCompositeShapeByType(m_drawshape,
															rcCreate,
															arInitPorts,
															strFileName,
															nResID,
															pCurItem);
	// FODO: Add your own specify code here.

	return pReturn;
}


void CExtDataModel::SetModifiedFlag(BOOL b)
{
	CFODataModel::SetModifiedFlag(b);
	
	//FOTO:Add you code here.

}

BOOL CExtDataModel::IsModified()
{

	//FOTO:Add you code here.

	return CFODataModel::IsModified();
}

void CExtDataModel::Serialize(CArchive& ar)
{
	CFODataModel::Serialize(ar);
	if(ar.IsStoring())
	{
		//FOTO:Add you code here.

	}
	else
	{
		//FOTO:Add you code here.

	}
}

/////////////////////////////////////////////////////////////////////////////
// CPrintBaseJob serialization
CFile* CExtDataModel::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
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

void CExtDataModel::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CExtDataModel::OpenDocument(LPCTSTR lpszPathName)
{
	CFileException fe;
	CFile* pFile = GetFile(lpszPathName,
		CFile::modeRead|CFile::shareDenyWrite, &fe);
	if (pFile == NULL)
	{
		return FALSE;
	}
	strCurOpenFormFile = CString(lpszPathName);
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

BOOL CExtDataModel::SaveDocument(LPCTSTR lpszPathName)
{
	CFileException fe;
	CFile* pFile = NULL;
	pFile = GetFile(lpszPathName, CFile::modeCreate |
		CFile::modeReadWrite | CFile::shareExclusive, &fe);
	
	if (pFile == NULL)
	{
		
		return FALSE;
	}
	strCurOpenFormFile = CString(lpszPathName);
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

void CExtDataModel::OnDrawShape(CDC *pDC,const CRect &rcView)
{
	CFODataModel::OnDrawShape(pDC,rcView);
	//FOTO:Add you code here.

}

void CExtDataModel::OnDrawBack(CDC *pDC,const CRect &rcClip)
{
	CFODataModel::OnDrawBack(pDC,rcClip);
	//FOTO:Add you code here.

}


/////////////////////////////////////////////////////////////////////////////
// CExtDataModel diagnostics

#ifdef _DEBUG
void CExtDataModel::AssertValid() const
{
	CFODataModel::AssertValid();
}

void CExtDataModel::Dump(CDumpContext& dc) const
{
	CFODataModel::Dump(dc);
}
#endif //_DEBUG
