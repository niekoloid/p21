/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_curve_styleC.h								์ฌ๚F2000.4.18

	PDNXTv
	curve_styleฬGeBeBf[^ว

	QD๐
	๐ิ		๚tฏ				Sา				Tv
	์ฌ			2000.4.18			{(FQS)			ศตB

**/
#ifndef _E_CURVE_STYLE_H_
#define _E_CURVE_STYLE_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_TypeC;
//
//
class SXFE_curve_styleC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_curve_styleC(SXFD_StrC*,SXFD_InstC*,SXFD_TypeC*,SXFD_InstC*);
	SXFE_curve_styleC(SXFD_StrC*,SXFD_InstC*,SXFD_InstC*,SXFD_InstC*);

} ;

#endif	// _E_CURVE_STYLE_H_
