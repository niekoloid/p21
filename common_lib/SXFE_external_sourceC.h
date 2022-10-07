/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_external_sourceC.h								作成日：2000.4.18

	１．クラス概要
	external_sourceのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_EXTERNAL_SOURCE_H_
#define _E_EXTERNAL_SOURCE_H_

#include "SXFD_InstC.h"

class SXFD_TypeC;
//
//
//
class SXFE_external_sourceC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_external_sourceC(SXFD_TypeC*);
} ;

#endif	// _E_EXTERNAL_SOURCE_H_
