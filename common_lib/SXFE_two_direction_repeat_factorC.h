/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_two_direction_repeat_factorC.h								作成日：2000.4.18

	１．クラス概要
	two_direction_repeat_factorのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_TWO_DIRECTION_REPEAT_FACTOR_H_
#define _E_TWO_DIRECTION_REPEAT_FACTOR_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
//
//
//
class SXFE_two_direction_repeat_factorC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_two_direction_repeat_factorC(SXFD_StrC*,SXFD_InstC*,SXFD_InstC*);
} ;

#endif	// _E_TWO_DIRECTION_REPEAT_FACTOR_H_
