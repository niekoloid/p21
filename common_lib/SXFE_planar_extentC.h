/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_planar_extentC.h								์ฌ๚F2000.4.18

	PDNXTv
	planar_extentฬGeBeBf[^ว

	QD๐
	๐ิ		๚tฏ				Sา				Tv
	์ฌ			2000.4.18			{(FQS)			ศตB

**/
#ifndef _E_PLANAR_EXTENT_H_
#define _E_PLANAR_EXTENT_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_RealC;
//
//
//
class SXFE_planar_extentC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_planar_extentC(SXFD_StrC*,SXFD_RealC*,SXFD_RealC*);
	SXFE_planar_extentC(SXFD_RealC*,SXFD_RealC*);

} ;

#endif	// _E_PLANAR_EXTENT_H_
