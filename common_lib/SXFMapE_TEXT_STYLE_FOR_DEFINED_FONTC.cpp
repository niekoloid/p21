/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC.cpp						作成日：2000.04.17

	１．クラス概要
		TEXT_STYLE_FOR_DEFINED_FONTを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC::SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC::SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC()
{
	m_EntityName = DEF_TEXT_STYLE_FOR_DEFINED_FONT;

	m_Color_Inst = 0;
	//m_Color_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC::SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数 ：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC::SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC(
	SXFInstanceIDC* IN_InstanceIDManeger)
	:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_TEXT_STYLE_FOR_DEFINED_FONT;

	m_Color_Inst = 0;
	//m_Color_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC::~SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC::~SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC::SetParameter( )
{

	SXFMapEntAConvC convent(m_EntityArray);

	//引数エラー
	if ( convent.GetInst(0,m_Color_Inst ) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	return 0;
}
