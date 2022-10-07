/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC.cpp						作成日：2000.04.17

	１．クラス概要
		DRAUGHTING_PRE_DEFINED_CURVE_FONTを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC::SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC::SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC()
{
//	<初期化>
	m_EntityName = DEF_DRAUGHTING_PRE_DEFINED_CURVE_FONT;

//<エンティティデータ>
//#20 = DRAUGHTING_PRE_DEFINED_CURVE_FONT('continuous');
	//nameパラメタ
	m_name.Empty();	
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC::SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数 ：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC::SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<初期化>
	m_EntityName = DEF_DRAUGHTING_PRE_DEFINED_CURVE_FONT;

//<エンティティデータ>
//#20 = DRAUGHTING_PRE_DEFINED_CURVE_FONT('continuous');
	//nameパラメタ
	m_name.Empty();	

}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC::~SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC::~SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC::SetParameter()

{
//	<1. エンティティパラメタの設定>
//<エンティティデータ>
//#20 = DRAUGHTING_PRE_DEFINED_CURVE_FONT('continuous');

	SXFMapEntAConvC convent(m_EntityArray);
	//<name>
	if ( convent.GetCString(0,m_name) < 0 ) {
		//エンティティパラメタの数に謝りがあります。
			SXFErrorMsgC::RecordError(
				SXFPARAMS,			//errメッセージ番号
				m_EntityName,		//エンティティ名
				2,					//パラメタの個数
				m_RootID,			//パラメタ
				m_EntityName
				);
		return SXFPARAMS;	//-55003
	}

	return 0;
}
