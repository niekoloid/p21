//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPreDefColorC.h					  ì¬úF2000.04.16
//
//	PDNXTv
//		PreDefColor Instance Table DataðÇ·é
//
//	QDð
//		ðÔ	út¯		   SÒ	 Tv
//		ì¬		2000.04.16	   ü
//
//------------------------------------------------------------
#ifndef _SXFPREDEFCOLORC_H_
#define _SXFPREDEFCOLORC_H_

#include <afx.h>

class SXFTableMapManagerC;

class SXFPreDefColorC  
{
public:
	SXFPreDefColorC(  );
	virtual ~SXFPreDefColorC();
	BOOL SetName(LPCTSTR IN_Name);
public:
	int m_Code;
	int m_ID;
	CString m_Name;
	int R,G,B;

	SXFTableMapManagerC* m_MappingManager;

};

#endif
