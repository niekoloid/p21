/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_splineC.h								์ฌ๚F2000.4.18

	PDNXTv
	splineฬGeBeBf[^ว

	QD๐
	๐ิ		๚tฏ				Sา				Tv
	์ฌ			2000.4.18			{(FQS)			ศตB

**/
#ifndef _E_SPLINE_H_
#define _E_SPLINE_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_IntC;
class SXFD_AggrC;
class SXFD_BoolC;
class SXFD_ListAggrC;
//
//
//
class SXFE_splineC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_splineC(SXFD_StrC *str,SXFD_IntC *in,SXFD_AggrC *aggr,SXFD_BoolC *str2,SXFD_BoolC *bool1,SXFD_BoolC *str3);
	SXFE_splineC(SXFD_StrC *str,SXFD_IntC *in,SXFD_ListAggrC *aggr,SXFD_BoolC *str2,SXFD_BoolC *bool1,SXFD_BoolC *str3);//ID_153_000607_ins
} ;

#endif	// _E_SPLINE_H_
