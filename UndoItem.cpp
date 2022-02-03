
#include "stdafx.h"
#include "UndoItem.h"

// Construction/destruction
CUndoItem::CUndoItem()
{
}

CUndoItem::~CUndoItem()
{

	int max = arr.GetSize();
	for (int t = 0 ; t < max ; t++ )
		delete arr.GetAt( t );
	arr.RemoveAll();

}
