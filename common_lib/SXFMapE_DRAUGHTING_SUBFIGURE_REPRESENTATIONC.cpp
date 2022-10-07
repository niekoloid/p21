/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC.cpp						作成日：2000.04.17

	１．クラス概要
		DRAUGHTING_SUBFIGURE_REPRESENTATIONを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC::SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC::SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC()
{
	m_EntityName = DEF_DRAWING_SHEET_REVISION;

	m_ItemCount = 0;
	m_ContextOfItem_Inst = 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC::SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数 ：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC::SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_DRAUGHTING_SUBFIGURE_REPRESENTATION;

	m_ItemCount = 0;
	m_ContextOfItem_Inst = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC::~SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC::~SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC::SetParameter( )
{

	SXFMapEntAConvC convent(m_EntityArray);

	//引数エラー
	if ( convent.GetCString(0,m_Name) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetSetInst(1,m_ItemCount, m_ItemArray_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetInst(2,m_ContextOfItem_Inst ) < 0 ){
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
