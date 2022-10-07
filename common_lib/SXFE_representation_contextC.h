/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_representation_contextC.h								作成日：2000.4.18

	１．クラス概要
	representation_contextのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_REPRESENTATION_CONTEXT_H_
#define _E_REPRESENTATION_CONTEXT_H_

#include "SXFD_InstC.h"

class SXFPart21FileC;
//
//
//
class SXFE_representation_contextC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_representation_contextC();
//
//
//
	void WriteP21(SXFPart21FileC* IN_file);
} ;

#endif	// _E_REPRESENTATION_CONTEXT_H_
