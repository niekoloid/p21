/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_clothoidC.cpp								作成日：2007.1.30

	１．クラス概要
	エンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.30			西木				なし。

**/
#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_RealC.h"
#include "SXFE_clothoidC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_clothoidC.cpp								作成日：2007.1.30

	１．機能概要
		コンストラクタ

	２．インターフェース
	void	SXFE_clothoidC(SXFD_StrC *str,
						 SXFD_IntC *in,
						 SXFD_RealC *real)
	引数:	型				引数名			内容
			SXFD_StrC 		*str				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_IntC 		*in					ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_RealC 		*real				ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.30			西木				なし。

**/
SXFE_clothoidC :: SXFE_clothoidC(SXFD_StrC *str,SXFD_InstC *inst,SXFD_RealC *real){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_CLOTHOID;

	m_Data.AddTail(str);
	m_Data.AddTail(inst);
	m_Data.AddTail(real);
}

