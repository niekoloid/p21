/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_colour_rgbC.h								作成日：2000.4.18

	１．クラス概要
	colour_rgbのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _SXFE_COLOUR_RGBC_H_
#define _SXFE_COLOUR_RGBC_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_RealC;

//
//
//
class SXFE_colour_rgbC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_colour_rgbC(SXFD_StrC*,SXFD_RealC*,SXFD_RealC*,SXFD_RealC*);
} ;

#endif	// _E_COLOUR_RGB_H_
