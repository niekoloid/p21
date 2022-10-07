/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_diameter_dimensionC.h								作成日：2000.4.18

	１．クラス概要
	diameter_dimensionのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_DIAMETER_DIMENSION_H_
#define _E_DIAMETER_DIMENSION_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_AggrC;
class SXFPart21FileC;
//
//
//
class SXFE_diameter_dimensionC : public SXFD_InstC {
public :
//
//	Constructor
//
	SXFE_diameter_dimensionC(SXFD_StrC*,SXFD_AggrC*);
//
//
//
	void WriteP21(SXFPart21FileC *IN_file);
} ;

#endif	// _E_DIAMETER_DIMENSION_H_
