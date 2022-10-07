/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_curve_styleC.h								作成日：2000.4.18

	１．クラス概要
	curve_styleのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_CURVE_STYLE_H_
#define _E_CURVE_STYLE_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_TypeC;
//
//
class SXFE_curve_styleC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_curve_styleC(SXFD_StrC*,SXFD_InstC*,SXFD_TypeC*,SXFD_InstC*);
	SXFE_curve_styleC(SXFD_StrC*,SXFD_InstC*,SXFD_InstC*,SXFD_InstC*);

} ;

#endif	// _E_CURVE_STYLE_H_
