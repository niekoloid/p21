/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_splineC.cpp								作成日：2000.4.18

	１．クラス概要
	エンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_IntC.h"
#include "SXFD_AggrC.h"
#include "SXFD_BoolC.h"
#include "SXFE_splineC.h"
#include "SXF_EXT.h"
#include "SXFD_ListAggrC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_splineC.cpp								作成日：2000.4.18

	１．機能概要
		コンストラクタ

	２．インターフェース
	void	SXFE_splineC(SXFD_StrC *str,
						 SXFD_IntC *in,
						 SXFD_AggrC *aggr,
						 SXFD_BoolC *str2,
						 SXFD_BoolC *bool1,
						 SXFD_BoolC *str3)
	引数:	型				引数名			内容
			SXFD_StrC 		*str				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_IntC 		*in					ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_AggrC 		*aggr				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_BoolC 		*str2				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_BoolC 		*bool1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_BoolC 		*str3				ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
SXFE_splineC :: SXFE_splineC(SXFD_StrC *str,SXFD_IntC *in,SXFD_AggrC *aggr,SXFD_BoolC *str2,SXFD_BoolC *bool1,SXFD_BoolC *str3){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_BEZIER_CURVE;

	m_Data.AddTail(str);
	m_Data.AddTail(in);
	m_Data.AddTail(aggr);
	m_Data.AddTail(str2);
	m_Data.AddTail(bool1);
	m_Data.AddTail(str3);
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_splineC.cpp								作成日：2000.4.18

	１．機能概要
		コンストラクタ

	２．インターフェース
	void	SXFE_splineC(SXFD_StrC *str,
						 SXFD_IntC *in,
						 SXFD_ListAggrC *aggr,
						 SXFD_BoolC *str2,
						 SXFD_BoolC *bool1,
						 SXFD_BoolC *str3)
	引数:	型				引数名			内容
			SXFD_StrC 		*str				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_IntC 		*in					ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_ListAggrC 	*aggr				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_BoolC 		*str2				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_BoolC 		*bool1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_BoolC 		*str3				ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
SXFE_splineC :: SXFE_splineC(SXFD_StrC *str,SXFD_IntC *in,SXFD_ListAggrC *aggr,SXFD_BoolC *str2,SXFD_BoolC *bool1,SXFD_BoolC *str3){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_BEZIER_CURVE;

	m_Data.AddTail(str);
	m_Data.AddTail(in);
	m_Data.AddTail(aggr);
	m_Data.AddTail(str2);
	m_Data.AddTail(bool1);
	m_Data.AddTail(str3);
}
