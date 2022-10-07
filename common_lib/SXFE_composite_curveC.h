/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_composite_curveC.h								作成日：2000.4.18

	１．クラス概要
	composite_curveのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_COMPOSITE_CURVE_H_
#define _E_COMPOSITE_CURVE_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_AggrC;
class SXFD_BoolC;
//
//
//
class SXFE_composite_curveC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_composite_curveC(SXFD_StrC*,SXFD_AggrC*,SXFD_BoolC*);
} ;

#endif	// _E_COMPOSITE_CURVE_H_
