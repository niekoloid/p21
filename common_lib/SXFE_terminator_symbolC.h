/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_terminator_symbolC.h								ì¬úF2000.4.18

	PDNXTv
	terminator_symbolÌGeBeBf[^Ç

	QDð
	ðÔ		út¯				SÒ				Tv
	ì¬			2000.4.18			{(FQS)			ÈµB

**/
#ifndef _E_TERMINATOR_SYMBOL_H_
#define _E_TERMINATOR_SYMBOL_H_

#include "SXFD_InstC.h"

class SXFD_EnumC;
class SXFD_StrC;
class SXFD_AggrC;
//
//
//
class SXFE_terminator_symbolC : public SXFD_InstC {
protected :
	int type_flag;
public :
//
//	Constructor
//
	SXFE_terminator_symbolC(SXFD_EnumC*,SXFD_StrC*,SXFD_AggrC*,SXFD_InstC*,SXFD_InstC*);
	SXFE_terminator_symbolC(SXFD_StrC*,SXFD_AggrC*,SXFD_InstC*,SXFD_InstC*);
//
//
//
	void WriteP21(SXFPart21FileC *IN_file);
} ;

#endif	// _E_TERMINATOR_SYMBOL_H_
