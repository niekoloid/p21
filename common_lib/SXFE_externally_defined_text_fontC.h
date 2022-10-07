/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_externally_defined_text_fontC.h								作成日：2000.4.18

	１．クラス概要
	externally_defined_text_fontのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _SXFE_EXTERNALLY_DEFINED_TEXT_FONTC_H_
#define _SXFE_EXTERNALLY_DEFINED_TEXT_FONTC_H_

#include "SXFD_InstC.h"

class SXFD_TypeC;
//
//
//
class SXFE_externally_defined_text_fontC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_externally_defined_text_fontC(SXFD_TypeC*,SXFD_InstC*);
} ;

#endif	// _E_EXTERNALLY_DEFINED_TEXT_FONT_H_
