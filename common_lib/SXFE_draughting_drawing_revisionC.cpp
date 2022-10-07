/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_draughting_drawing_revisionC.cpp								作成日：2001.06.18

	１．クラス概要
	エンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.18			佐々木(FQS)			なし。
	更新			2004.01.30			K.Naono				Ver3.0対応

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFE_draughting_drawing_revisionC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_draughting_drawing_revisionC.cpp								作成日：2001.06.18

	１．機能概要
		コンストラクタ

	２．インターフェース
	void	SXFE_draughting_drawing_revisionC(SXFD_StrC* str,SXFD_InstC* inst)
	引数:	型								引数名				内容
			SXFD_StrC*						str				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_InstC*						inst			ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.18			佐々木(FQS)			なし。
	更新			2004.01.30			K.Naono				Ver3.0対応

**/
SXFE_draughting_drawing_revisionC
	::SXFE_draughting_drawing_revisionC(SXFD_StrC* str,SXFD_InstC* inst){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_DRAUGHTING_DRAWING_REVISION;

	m_Data.AddTail(str);
	m_Data.AddTail(inst);
	m_str = new SXFD_StrC(DEF_DOLLAR);
	m_Data.AddTail(m_str);
}

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
SXFE_draughting_drawing_revisionC::SXFE_draughting_drawing_revisionC(
									SXFD_StrC*	str1,
									SXFD_InstC*	inst,
									SXFD_StrC*	str2)
{

	m_Flg = 1 ;

	m_InstanceID = gl_InstanceID ;
	gl_InstanceID += 10 ;

	m_Entity = DEF_DRAUGHTING_DRAWING_REVISION ;

	m_Data.AddTail(str1) ;
	m_Data.AddTail(inst) ;
	m_Data.AddTail(str2) ;
}
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_draughting_drawing_revisionC.cpp								作成日：2001.06.18

	１．機能概要
		デストラクタ
	２．インターフェース
	void	SXFE_draughting_drawing_revisionC::~SXFE_draughting_drawing_revisionC()
	引数:	型								引数名				内容
			なし					

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.18			佐々木(FQS)			なし。

**/
SXFE_draughting_drawing_revisionC
	::~SXFE_draughting_drawing_revisionC(){
}
