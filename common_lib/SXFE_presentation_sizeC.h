/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_presentation_sizeC.h								作成日：2000.4.18

	１．クラス概要
	presentation_sizeのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_PRESENTATION_SIZE_H_
#define _E_PRESENTATION_SIZE_H_

#include "SXFD_InstC.h"

class SXFPart21FileC;
//
//
//
class SXFE_presentation_sizeC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_presentation_sizeC(SXFD_InstC*,SXFD_InstC*);
	void WriteP21(SXFPart21FileC *IN_file);
} ;

#endif	// _E_PRESENTATION_SIZE_H_
