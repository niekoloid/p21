/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_annotation_symbolC.h								ì¬úF2000.4.18

	PDNXTv
	annotation_symbolÌGeBeBf[^Ç

	QDð
	ðÔ		út¯				SÒ				Tv
	ì¬			2000.4.18			{(FQS)			ÈµB

**/
#ifndef _E_ANNOTATION_SYMBOL_H_
#define _E_ANNOTATION_SYMBOL_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFPart21FileC;

//
//
//
class SXFE_annotation_symbolC : public SXFD_InstC {
protected :
public :
	void WriteP21(SXFPart21FileC *IN_file);
//
//	Constructor
//
	SXFE_annotation_symbolC(SXFD_InstC*,SXFD_InstC*,SXFD_StrC*);
} ;

#endif	// _E_ANNOTATION_SYMBOL_H_
