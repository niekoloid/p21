/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_externally_defined_hatch_styleC.h								作成日：2000.4.18

	１．クラス概要
	externally_defined_hatch_styleのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_EXTERNALLY_DEFINED_HATCH_STYLE_H_
#define _E_EXTERNALLY_DEFINED_HATCH_STYLE_H_

#include "SXFD_InstC.h"

class SXFD_TypeC;
class SXFD_StrC;
//
//
class SXFE_externally_defined_hatch_styleC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_externally_defined_hatch_styleC(SXFD_TypeC*,SXFD_InstC*,SXFD_StrC*);
} ;

#endif	// _E_EXTERNALLY_DEFINED_HATCH_STYLE_H_
