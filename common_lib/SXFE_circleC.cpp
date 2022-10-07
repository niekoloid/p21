/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_circleC.cpp								作成日：2000.4.18

	１．クラス概要
	エンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFE_circleC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_circleC.cpp								作成日：2000.4.18

	１．機能概要
		コンストラクタ

	２．インターフェース
	void	SXFE_circleC(SXFD_StrC *str,SXFD_InstC *inst1,SXFD_RealC *rea)
	引数:	型							引数名				内容
			SXFD_StrC					*str			ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_InstC					*inst1			ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_RealC					*rea			ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
SXFE_circleC :: SXFE_circleC(SXFD_StrC *str,SXFD_InstC *inst1,SXFD_RealC *rea){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_CIRCLE;

	m_Data.AddTail(str);
	m_Data.AddTail(inst1);
	m_Data.AddTail(rea);
}
