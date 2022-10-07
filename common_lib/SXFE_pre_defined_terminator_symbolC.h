/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_pre_defined_terminator_symbolC.h								作成日：2000.4.18

	１．クラス概要
	pre_defined_terminator_symbolのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_PRE_DEFINED_TERMINATOR_SYMBOL_H_
#define _E_PRE_DEFINED_TERMINATOR_SYMBOL_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
//
//
class SXFE_pre_defined_terminator_symbolC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_pre_defined_terminator_symbolC(SXFD_StrC*);
} ;

#endif	// _E_PRE_DEFINED_TERMINATOR_SYMBOL_H_
