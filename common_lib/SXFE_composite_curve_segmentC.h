/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_composite_curve_segmentC.h								作成日：2000.4.18

	１．クラス概要
	composite_curve_segmentのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_COMPOSITE_CURVE_SEGMENT_H_
#define _E_COMPOSITE_CURVE_SEGMENT_H_

#include "SXFD_InstC.h"

class SXFD_EnumC;
class SXFD_BoolC;

//
//
//
class SXFE_composite_curve_segmentC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_composite_curve_segmentC(SXFD_EnumC*,SXFD_BoolC*,SXFD_InstC*);
} ;

#endif	// _E_COMPOSITE_CURVE_SEGMENT_H_
