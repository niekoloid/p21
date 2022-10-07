/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_trimmed_curveC.cpp								作成日：2000.4.18

	１．クラス概要
	エンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFD_BoolC.h"
#include "SXFD_EnumC.h"
#include "SXFE_trimmed_curveC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_trimmed_curveC.cpp								作成日：2000.4.18

	１．機能概要
		コンストラクタ

	２．インターフェース
	void	SXFE_trimmed_curveC(SXFD_StrC *str,
								 SXFD_InstC *inst,
								 SXFD_AggrC *aggr1,
								 SXFD_AggrC *aggr2,
								 SXFD_BoolC *bo,
								 SXFD_EnumC *enu)
	引数:	型				引数名			内容
			SXFD_StrC 		*str		ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_InstC 		*inst		ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_AggrC 		*aggr1		ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_AggrC 		*aggr2		ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_BoolC 		*bo			ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_EnumC 		*enu		ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
SXFE_trimmed_curveC::SXFE_trimmed_curveC(SXFD_StrC *str,
								 SXFD_InstC *inst,
								 SXFD_AggrC *aggr1,
								 SXFD_AggrC *aggr2,
								 SXFD_BoolC *bo,
								 SXFD_EnumC *enu){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_TRIMMED_CURVE;

	m_Data.AddTail(str);
	m_Data.AddTail(inst);
	m_Data.AddTail(aggr1);
	m_Data.AddTail(aggr2);
	m_Data.AddTail(bo);
	m_Data.AddTail(enu);

}
