//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFUserDefColorC.h                    ì¬úF2000.04.10
//
//	PDNXTv
//      UserDefColor Instance Table DataðÇ·é
//
//	QDð
//	    ðÔ    út¯         SÒ    Tv
//      ì¬		2000.04.10     ü
//
//------------------------------------------------------------
#ifndef _SXFUSERDEFCOLORC_H_
#define _SXFUSERDEFCOLORC_H_

#include <afx.h>

class SXFTableMapManagerC;

class SXFUserDefColorC
{
public:
	SXFUserDefColorC(  );
	virtual ~SXFUserDefColorC();

public:
	int m_Code;
	int m_ID;
	CString m_Name;
	int R,G,B;

	SXFTableMapManagerC* m_MappingManager;

	int m_Level1Code;

};
#endif
