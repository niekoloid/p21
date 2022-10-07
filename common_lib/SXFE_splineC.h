/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_splineC.h								作成日：2000.4.18

	１．クラス概要
	splineのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

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
