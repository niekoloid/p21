/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_length_measure_with_unitC.h								作成日：2000.4.18

	１．クラス概要
	length_measure_with_unitのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_LENGTH_MEASURE_WITH_UNIT_H_
#define _E_LENGTH_MEASURE_WITH_UNIT_H_

#include "SXFD_InstC.h"

class SXFD_TypeC;
//
//
//
class SXFE_length_measure_with_unitC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_length_measure_with_unitC(SXFD_TypeC*,SXFD_InstC*);
} ;

#endif	// _E_LENGTH_MEASURE_WITH_UNIT_H_
