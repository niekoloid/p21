//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTextFontC.h                        ì¬úF2000.04.16
//
//	PDNXTv
//		TextFont Instance Table DataðÇ·é
// 
//	QDð
//	    ðÔ    út¯         SÒ    Tv
//      ì¬		2000.04.16     ü
//
//------------------------------------------------------------
#ifndef _SXFTEXTFONTC_H_
#define _SXFTEXTFONTC_H_

#include <afx.h>

class SXFTableMapManagerC;

class SXFTextFontC
{
public:
	SXFTextFontC(  );
	virtual ~SXFTextFontC();

public:
	int m_Code;
	int m_ID;
	double m_Ascent;
	double m_Decent;

	CString m_Name;

	SXFTableMapManagerC* m_MappingManager;

};

#endif
