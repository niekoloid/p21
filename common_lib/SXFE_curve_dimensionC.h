/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_curve_dimensionC.h								作成日：2007.1.29

	１．クラス概要
	curve_dimensionのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/

#ifndef _E_CURVE_DIMENSION_H_
#define _E_CURVE_DIMENSION_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_AggrC;
class SXFPart21FileC;
//
//
//
class SXFE_curve_dimensionC : public SXFD_InstC {
public :
//
//	Constructor
//
	SXFE_curve_dimensionC(SXFD_StrC*,SXFD_AggrC*);
//
//
//
	void WriteP21(SXFPart21FileC *IN_file);
} ;

#endif	// _E_CURVE_DIMENSION_H_
