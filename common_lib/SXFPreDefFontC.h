//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPreDefFontC.h					 ì¬úF2000.04.16
//
//	PDNXTv
//		PreDefFont Instance Table DataðÇ·é
//
//	QDð
//		ðÔ	út¯		   SÒ	 Tv
//		ì¬		2000.04.16	   ü
//
//------------------------------------------------------------
#ifndef _SXFPREDEFFONTC_H_
#define _SXFPREDEFFONTC_H_

#include <afx.h>

class SXFTableMapManagerC;

class SXFPreDefFontC  
{
public:
	SXFPreDefFontC( );
	virtual ~SXFPreDefFontC();
	BOOL SetName(LPCTSTR IN_Name);

public:
	int m_Code;
	int m_ID;
	CString m_Name;

	SXFTableMapManagerC* m_MappingManager;

};

#endif
