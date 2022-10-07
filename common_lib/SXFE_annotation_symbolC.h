/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_annotation_symbolC.h								作成日：2000.4.18

	１．クラス概要
	annotation_symbolのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_ANNOTATION_SYMBOL_H_
#define _E_ANNOTATION_SYMBOL_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFPart21FileC;

//
//
//
class SXFE_annotation_symbolC : public SXFD_InstC {
protected :
public :
	void WriteP21(SXFPart21FileC *IN_file);
//
//	Constructor
//
	SXFE_annotation_symbolC(SXFD_InstC*,SXFD_InstC*,SXFD_StrC*);
} ;

#endif	// _E_ANNOTATION_SYMBOL_H_
