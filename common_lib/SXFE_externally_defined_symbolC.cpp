/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_externally_defined_symbolC.cpp								作成日：2000.4.18

	１．クラス概要
	エンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_TypeC.h"
#include "SXFE_externally_defined_symbolC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_externally_defined_symbolC.cpp								作成日：2000.4.18

	１．機能概要
		コンストラクタ

	２．インターフェース
	void	SXFE_externally_defined_symbolC(SXFD_StrC *str1,SXFD_StrC *str2)
	引数:	型								引数名				内容
			SXFD_StrC						*str1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_StrC						*str2				ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
SXFE_externally_defined_symbolC
::SXFE_externally_defined_symbolC(SXFD_StrC *str1,SXFD_StrC *str2){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_EXTERNALLY_DEFINED_SYMBOL;

	m_Data.AddTail(str1);
	m_Data.AddTail(str2);
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_externally_defined_symbolC.cpp								作成日：2000.4.18

	１．機能概要

	２．インターフェース
	void	SXFE_externally_defined_symbolC(SXFD_TypeC *type,SXFD_InstC *ins)
	引数:	型								引数名				内容
			SXFD_TypeC						*type
			SXFD_InstC						*ins

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
SXFE_externally_defined_symbolC
::SXFE_externally_defined_symbolC(SXFD_TypeC *type,SXFD_InstC *ins){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_EXTERNALLY_DEFINED_SYMBOL;

	m_Data.AddTail(type);
	m_Data.AddTail(ins);

}
