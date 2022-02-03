
#include "stdafx.h"
#include "LinkFactory.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString CLinkFactory::GetID()
{
	CString str;

	str.Format( _T( "%i" ), CLinkFactory::s_currentID );
	CLinkFactory::s_currentID++;

	return str;

}

int CLinkFactory::s_currentID = 0;

