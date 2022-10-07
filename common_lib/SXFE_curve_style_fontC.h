/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_curve_style_fontC.h								作成日：2000.4.18

	１．クラス概要
	curve_style_fontのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_CURVE_STYLE_FONT_H_
#define _E_CURVE_STYLE_FONT_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_AggrC;
class SXFD_ListAggrC;
//
//
//
class SXFE_curve_style_fontC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_curve_style_fontC(SXFD_StrC*,SXFD_AggrC*);
	SXFE_curve_style_fontC(SXFD_StrC*,SXFD_ListAggrC*);
} ;

#endif	// _E_CURVE_STYLE_FONT_H_
