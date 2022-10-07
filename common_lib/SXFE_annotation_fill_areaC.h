/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_annotation_fill_areaC.h								作成日：2000.4.18

	１．クラス概要
	annotation_fill_areaのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_ANNOTATION_FILL_AREA_H_
#define _E_ANNOTATION_FILL_AREA_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_AggrC;
//
//
//
class SXFE_annotation_fill_areaC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_annotation_fill_areaC(SXFD_StrC*,SXFD_AggrC*);
} ;

#endif	// _E_ANNOTATION_FILL_AREA_H_
