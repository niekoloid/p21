/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_trimmed_curveC.h								作成日：2000.4.18

	１．クラス概要
	trimmed_curveのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_TRIMMED_CURVE_H_
#define _E_TRIMMED_CURVE_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_AggrC;
class SXFD_BoolC;
class SXFD_EnumC;
//
//
//
class SXFE_trimmed_curveC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_trimmed_curveC(SXFD_StrC*,
		SXFD_InstC*,
		SXFD_AggrC*,
		SXFD_AggrC*,
		SXFD_BoolC*,
		SXFD_EnumC*);
} ;

#endif	// _E_TRIMMED_CURVE_H_
