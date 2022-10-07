/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_text_literal_with_extentC.cpp								作成日：2000.4.18

	１．クラス概要
	エンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_EnumC.h"
#include "SXFE_text_literal_with_extentC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_text_literal_with_extentC.cpp								作成日：2000.4.18

	１．機能概要
		コンストラクタ
	
	２．インターフェース
	void	SXFE_text_literal_with_extentC(SXFD_StrC *str1,
										   SXFD_StrC *str2 ,
										   SXFD_InstC *ins1,
										   SXFD_StrC *str,
										   SXFD_EnumC *enu,
										   SXFD_InstC *ins2,
										   SXFD_InstC *ins3)

	引数:	型				引数名			内容
			SXFD_StrC 		*str1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_StrC 		*str2				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_InstC 		*ins1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_StrC 		*str				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_EnumC 		*enu				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_InstC 		*ins2				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_InstC 		*ins3				ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
SXFE_text_literal_with_extentC
::SXFE_text_literal_with_extentC
(SXFD_StrC *str1,SXFD_StrC *str2 ,SXFD_InstC *ins1,SXFD_StrC *str,SXFD_EnumC *enu,SXFD_InstC *ins2,SXFD_InstC *ins3){

	m_Flg = 1;

	extern int InstanceID;
	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_TEXT_LITERAL_WITH_EXTENT;

	m_Data.AddTail(str1);
	m_Data.AddTail(str2);
	m_Data.AddTail(ins1);
	m_Data.AddTail(str);
	m_Data.AddTail(enu);
	m_Data.AddTail(ins2);
	m_Data.AddTail(ins3);
}

