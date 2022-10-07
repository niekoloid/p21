/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_styled_itemC.h								作成日：2000.4.18

	１．クラス概要
	styled_itemのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_STYLED_ITEM_H_
#define _E_STYLED_ITEM_H_

#include "SXFD_InstC.h"
#include <afx.h>

class SXFD_AggrC;
class SXFD_StrC;
class SXFPart21FileC;
//
//
//
class SXFE_styled_itemC : public SXFD_InstC {
protected :
	CStringList *m_StrList;
	int type_flg;
public :
//
//	Constructor
//
	SXFE_styled_itemC(SXFD_StrC*,SXFD_AggrC*,SXFD_InstC*,CStringList*);
	SXFE_styled_itemC(SXFD_AggrC*,SXFD_AggrC*,SXFD_InstC*,SXFD_AggrC*);
	SXFE_styled_itemC(SXFD_AggrC*,SXFD_AggrC*,SXFD_InstC*);
	SXFE_styled_itemC(SXFD_StrC* str1,SXFD_AggrC* aggr1,SXFD_InstC *inst1);
//
//
//
	void WriteP21(SXFPart21FileC *IN_file);
} ;

#endif	// _E_STYLED_ITEM_H_
