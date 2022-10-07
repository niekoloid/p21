/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_curve_style_font_patternC.cpp								作成日：2000.4.18

	１．クラス概要
	エンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFD_RealC.h"
#include "SXFE_curve_style_font_patternC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_curve_style_font_patternC.cpp								作成日：2000.4.18

	１．機能概要
		コンストラクタ

	２．インターフェース
	void	SXFE_curve_style_font_patternC(SXFD_RealC *real1,SXFD_RealC *real2)
	引数:	型								引数名				内容
			SXFD_RealC						*real1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_RealC						*real2				ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
SXFE_curve_style_font_patternC
::SXFE_curve_style_font_patternC(SXFD_RealC *real1,SXFD_RealC *real2){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_CURVE_STYLE_FONT_PATTERN;

	m_Data.AddTail(real1);
	m_Data.AddTail(real2);

}
