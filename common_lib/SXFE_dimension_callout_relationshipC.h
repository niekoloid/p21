/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_dimension_callout_relationshipC.h								作成日：2000.4.18

	１．クラス概要
	dimension_callout_relationshipのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_DIMENSION_CALLOUT_RELATIONSHIP_H_
#define _E_DIMENSION_CALLOUT_RELATIONSHIP_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
//
//
//
class SXFE_dimension_callout_relationshipC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_dimension_callout_relationshipC(SXFD_StrC*,SXFD_StrC*,SXFD_InstC*,SXFD_InstC*);
} ;

#endif	// _E_DIMENSION_CALLOUT_RELATIONSHIP_H_
