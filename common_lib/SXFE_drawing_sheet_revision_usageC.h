/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_drawing_sheet_revision_usageC.h								作成日：2000.4.18

	１．クラス概要
	drawing_sheet_revision_usageのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_DRAWING_SHEET_REVISION_USAGE_H_
#define _E_DRAWING_SHEET_REVISION_USAGE_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
//
//
//
class SXFE_drawing_sheet_revision_usageC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_drawing_sheet_revision_usageC(SXFD_InstC*,SXFD_InstC*,SXFD_StrC*);
} ;

#endif	// _E_DRAWING_SHEET_REVISION_USAGE_H_
