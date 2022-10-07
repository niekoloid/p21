/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_DRAWING_DEFINITIONC.cpp						作成日：2000.04.17

	１．クラス概要
		DRAWING_DEFINITIONを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_DRAWING_DEFINITIONC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_DEFINITIONC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_DRAWING_DEFINITIONC::SXFMapE_DRAWING_DEFINITIONC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_DRAWING_DEFINITIONC::SXFMapE_DRAWING_DEFINITIONC()
{
	m_EntityName = DEF_DRAWING_DEFINITION;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_DEFINITIONC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_DRAWING_DEFINITIONC::SXFMapE_DRAWING_DEFINITIONC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)


	引数 ：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_DRAWING_DEFINITIONC::SXFMapE_DRAWING_DEFINITIONC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_DRAWING_DEFINITION;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_DEFINITIONC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_DRAWING_DEFINITIONC::~SXFMapE_DRAWING_DEFINITIONC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_DRAWING_DEFINITIONC::~SXFMapE_DRAWING_DEFINITIONC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_DEFINITIONC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_DRAWING_DEFINITIONC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_DRAWING_DEFINITIONC::SetParameter( )
{

	SXFMapEntAConvC convent(m_EntityArray);

	//引数エラー
	if ( convent.GetCString(0,m_DrawingNumber) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetCString(1,m_DrawingType ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	return 0;
}
