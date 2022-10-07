/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_cartesian_pointC.cpp								作成日：2000.4.18

	１．クラス概要
	cartesian_pointのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_cartesian_pointC.cpp								作成日：2000.4.18

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFE_cartesian_pointC(SXFD_StrC* str,SXFD_AggrC* aggr)
	引数:	型								引数名				内容
			SXFD_StrC*						str			ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_AggrC*						aggr		ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
SXFE_cartesian_pointC::SXFE_cartesian_pointC(SXFD_StrC* str,SXFD_AggrC* aggr){
	m_Flg = 1;
	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_CARTESIAN_POINT;

	m_Data.AddTail(str);
	m_Data.AddTail(aggr);
}
