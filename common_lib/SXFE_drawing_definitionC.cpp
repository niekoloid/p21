/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_drawing_definitionC.cpp								作成日：2001.06.18

	１．クラス概要
	エンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.18			佐々木(FQS)			なし。
	更新			2004.01.30			K.Naono				Ver3.0対応

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFE_drawing_definitionC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_drawing_definitionC.cpp								作成日：2001.06.18

	１．機能概要
		コンストラクタ

	２．インターフェース
	void	SXFE_drawing_definitionC(SXFD_StrC* str)
	引数:	型								引数名				内容
			SXFD_StrC*						str				ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.18			佐々木(FQS)			なし。
	更新			2004.01.30			K.Naono				Ver3.0対応

**/
SXFE_drawing_definitionC
::SXFE_drawing_definitionC(SXFD_StrC* str){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_DRAWING_DEFINITION;

	m_Data.AddTail(str);
	m_str = new SXFD_StrC(DEF_DOLLAR);
	m_Data.AddTail(m_str);
}

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
SXFE_drawing_definitionC::SXFE_drawing_definitionC(
									SXFD_StrC*		IN_Str1,
									SXFD_StrC*		IN_Str2) {

	m_Flg = 1 ;

	m_InstanceID = gl_InstanceID ;
	gl_InstanceID += 10 ;

	m_Entity = DEF_DRAWING_DEFINITION ;

	m_Data.AddTail(IN_Str1) ;
	m_Data.AddTail(IN_Str2) ;
}
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_drawing_definitionC.cpp								作成日：2001.06.18

	１．機能概要
		デストラクタ

	２．インターフェース
	void	SXFE_drawing_definitionC::~SXFE_drawing_definitionC()
	引数:	型								引数名				内容
			なし					

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.18			佐々木(FQS)			なし。

**/
SXFE_drawing_definitionC
::~SXFE_drawing_definitionC(){
}
