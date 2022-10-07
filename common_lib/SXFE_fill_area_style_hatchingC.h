/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_fill_area_style_hatchingC.h								作成日：2000.4.18

	１．クラス概要
	fill_area_style_hatchingのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_FILL_AREA_STYLE_HATCHING_H_
#define _E_FILL_AREA_STYLE_HATCHING_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_RealC;
//
//
//
class SXFE_fill_area_style_hatchingC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_fill_area_style_hatchingC(SXFD_StrC*,SXFD_InstC*,SXFD_InstC*,SXFD_InstC*,SXFD_InstC*,SXFD_RealC*);
} ;

#endif	// _E_FILL_AREA_STYLE_HATCHING_H_
