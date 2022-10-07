/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_terminator_symbolC.h								作成日：2000.4.18

	１．クラス概要
	terminator_symbolのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_TERMINATOR_SYMBOL_H_
#define _E_TERMINATOR_SYMBOL_H_

#include "SXFD_InstC.h"

class SXFD_EnumC;
class SXFD_StrC;
class SXFD_AggrC;
//
//
//
class SXFE_terminator_symbolC : public SXFD_InstC {
protected :
	int type_flag;
public :
//
//	Constructor
//
	SXFE_terminator_symbolC(SXFD_EnumC*,SXFD_StrC*,SXFD_AggrC*,SXFD_InstC*,SXFD_InstC*);
	SXFE_terminator_symbolC(SXFD_StrC*,SXFD_AggrC*,SXFD_InstC*,SXFD_InstC*);
//
//
//
	void WriteP21(SXFPart21FileC *IN_file);
} ;

#endif	// _E_TERMINATOR_SYMBOL_H_
