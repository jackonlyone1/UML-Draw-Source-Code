
#include "stdafx.h"
#include "GroupFactory.h"


int CGroupFactory::GetNewGroup()
{

	CGroupFactory::m_sCurrentGroup++;
	return CGroupFactory::m_sCurrentGroup;

}

int CGroupFactory::m_sCurrentGroup = 0;
