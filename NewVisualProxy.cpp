// NewVisualProxy.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "NewVisualProxy.h"
#include "resource.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CNewVisualProxy, CFOPGDIPlusProxy)

CNewVisualProxy::CNewVisualProxy()
{

}

CNewVisualProxy::~CNewVisualProxy()
{

}

/////////////////////////////////////////////////////////////////////////////
// CNewVisualProxy diagnostics

#ifdef _DEBUG
void CNewVisualProxy::AssertValid() const
{
	CObject::AssertValid();
}

void CNewVisualProxy::Dump(CDumpContext& dc) const
{
	CObject::Dump(dc);
}
#endif //_DEBUG

CString CNewVisualProxy::GenerateDimText(int nLength)
{
	CString strReturn;
	strReturn.Format(_T("%u Pixel"),nLength);
	return strReturn;
}

void CNewVisualProxy::DoGenAddiToolTips(CString &strGen, const UINT &nType)
{
	if(nType == 31056)
	{
		strGen = _T("Class Define...");
	}
	else if(nType == 31057)
	{
		strGen = _T("Import From .H File...");
	}
	else
	{
		CFOPGDIPlusProxy::DoGenAddiToolTips(strGen,nType);
	}
}

void CNewVisualProxy::DoDrawAddiWithType(CDC *pDC,const CRect &rcPos,const UINT &nType)
{
	if(nType == 31057)
	{
		HICON hIcon = (HICON)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON_NEW), IMAGE_ICON, 16, 16, 0);
		DrawIconEx(pDC->m_hDC, rcPos.left, rcPos.top, hIcon, 16, 16, 0, NULL, DI_NORMAL);
		DestroyIcon(hIcon);
	}
	else
	{
		CFOPGDIPlusProxy::DoDrawAddiWithType(pDC,rcPos,nType);
	}
}
