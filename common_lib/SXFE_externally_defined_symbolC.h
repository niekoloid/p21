/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_externally_defined_symbolC.h								ì¬úF2000.4.18

	PDNXTv
	externally_defined_symbolÌGeBeBf[^Ç

	QDð
	ðÔ		út¯				SÒ				Tv
	ì¬			2000.4.18			{(FQS)			ÈµB

**/
#ifndef _E_EXTERNALLY_DEFINED_SYMBOL_H_
#define _E_EXTERNALLY_DEFINED_SYMBOL_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_TypeC;
//
//
//
class SXFE_externally_defined_symbolC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_externally_defined_symbolC(SXFD_StrC*,SXFD_StrC*);
	SXFE_externally_defined_symbolC(SXFD_TypeC*,SXFD_InstC*);

} ;

#endif	// _E_EXTERNALLY_DEFINED_SYMBOL_H_
