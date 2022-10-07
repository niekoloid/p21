/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_text_literal_with_extentC.h								作成日：2000.4.18

	１．クラス概要
	text_literal_with_extentのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_TEXT_LITERAL_WITH_EXTENT_H_
#define _E_TEXT_LITERAL_WITH_EXTENT_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_EnumC;
//
//
//
class SXFE_text_literal_with_extentC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_text_literal_with_extentC(SXFD_StrC*,SXFD_StrC*,SXFD_InstC*,SXFD_StrC*,SXFD_EnumC*,SXFD_InstC*,SXFD_InstC*);
} ;

#endif	// _E_TEXT_LITERAL_WITH_EXTENT_H_
