#if !defined(FO_NEWVISUALPROXY_H__C4F5BA8E_D795_41AD_851D_FB8B93DE7AFD__INCLUDED_)
#define AFC_NEWVISUALPROXY_H__C4F5BA8E_D795_41AD_851D_FB8B93DE7AFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//------------------------------------------------------
// Description
// Author: ucancode.net Software.
//------------------------------------------------------
#include "FOPVisualProxy.h"
#include "FOPGDIPlusProxy.h"

 
//===========================================================================
// Summary:
//     The CNewVisualProxy class derived from CFOPVisualProxy
//      New Visual Proxy
//===========================================================================

class CNewVisualProxy : public CFOPGDIPlusProxy  
{
protected:
	
	//-----------------------------------------------------------------------
	// Summary:
	// E C L A R E_ D Y N C R E A T E, None Description.
	//		Returns A  value.  
	// Parameters:
	//		CNewVisualProxy---New Visual Proxy, Specifies a CNewVisualProxy object.
	DECLARE_DYNCREATE(CNewVisualProxy);
public:
	
	//-----------------------------------------------------------------------
	// Summary:
	// New Visual Proxy, Constructs a CNewVisualProxy object.
	//		Returns A  value.
	CNewVisualProxy();
	
	//-----------------------------------------------------------------------
	// Summary:
	// C New Visual Proxy, Destructor of class CNewVisualProxy
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns A  value.
	virtual ~CNewVisualProxy();
public:

#ifdef _DEBUG
	
	//-----------------------------------------------------------------------
	// Summary:
	// Assert Valid, Assert performs a validity check on this object by checking its internal state.
	// This member function is also a virtual function, you can Override it if you need,
	virtual void AssertValid() const;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Dumps the contents of your object to a CDumpContext object.
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		dc---Specifies a CDumpContext& dc object.
	virtual void Dump(CDumpContext& dc) const;
#endif

public:

	// Generate dimension text.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Generate Dimension Text, None Description.
	// This member function is also a virtual function, you can Override it if you need,  
	//		Returns a CString type value.  
	// Parameters:
	//		nLength---Length, Specifies A integer value.
	virtual CString GenerateDimText(int nLength);

	// Drawing selection additional type.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Draw Additional With Type, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		*pDC---D C, A pointer to the CDC  or NULL if the call failed.  
	//		&rcPos---Position, Specifies A CRect type value.  
	//		&nType---Type, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	virtual void DoDrawAddiWithType(CDC *pDC,const CRect &rcPos,const UINT &nType);

	// Do generate the tooltip text of additional icons.
	// strGen -- tooltip text that generated.
	// nType -- icon type ID.
	
	//-----------------------------------------------------------------------
	// Summary:
	// Do Generate Additional Tool Tips, Do a event. 
	// This member function is also a virtual function, you can Override it if you need,  
	// Parameters:
	//		&strGen---Generate, Specifies A CString type value.  
	//		&nType---Type, Specifies A 16-bit unsigned integer on Windows versions 3.0 and 3.1; a 32-bit unsigned integer on Win32.
	virtual void DoGenAddiToolTips(CString &strGen, const UINT &nType);

};


#endif // !defined(AFC_NEWVISUALPROXY_H__C4F5BA8E_D795_41AD_851D_FB8B93DE7AFD__INCLUDED_)
