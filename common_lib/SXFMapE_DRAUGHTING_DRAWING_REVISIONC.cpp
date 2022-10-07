/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_DRAUGHTING_DRAWING_REVISIONC.cpp						作成日：2000.04.17

	１．クラス概要
		DRAUGHTING_DRAWING_REVISIONを管理する

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_DRAUGHTING_DRAWING_REVISIONC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_DRAWING_REVISIONC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_DRAUGHTING_DRAWING_REVISIONC::SXFMapE_DRAUGHTING_DRAWING_REVISIONC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_DRAUGHTING_DRAWING_REVISIONC::SXFMapE_DRAUGHTING_DRAWING_REVISIONC()
{
	m_EntityName = DEF_DRAUGHTING_DRAWING_REVISION;

	m_DrawingIdentifier_Inst = 0;
	m_DrawingIdentifier_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_DRAWING_REVISIONC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティデータを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_DRAUGHTING_DRAWING_REVISIONC::SXFMapE_DRAUGHTING_DRAWING_REVISIONC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_DRAUGHTING_DRAWING_REVISIONC::SXFMapE_DRAUGHTING_DRAWING_REVISIONC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_DRAUGHTING_DRAWING_REVISION;

	m_DrawingIdentifier_Inst = 0;
	m_DrawingIdentifier_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_DRAWING_REVISIONC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_DRAUGHTING_DRAWING_REVISIONC::~SXFMapE_DRAUGHTING_DRAWING_REVISIONC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_DRAUGHTING_DRAWING_REVISIONC::~SXFMapE_DRAUGHTING_DRAWING_REVISIONC()
{

	if(m_DrawingIdentifier_p !=NULL)
		delete m_DrawingIdentifier_p;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_DRAWING_REVISIONC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティデータの登録

	２．インターフェイス
		int		SXFMapE_DRAUGHTING_DRAWING_REVISIONC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_DRAUGHTING_DRAWING_REVISIONC::SetParameter( )
{

	int ircode;

	SXFMapEntAConvC convent(m_EntityArray);

	//引数エラー
	if ( convent.GetCString(0,m_RevisionIdentifier) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetInst(1,m_DrawingIdentifier_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//オブジェクト生成
	m_DrawingIdentifier_p =
		new SXFMapE_DRAWING_DEFINITIONC(m_InstanceIDManager );

	ircode = m_DrawingIdentifier_p->SetRootID(m_DrawingIdentifier_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_DrawingIdentifier_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	//引数エラー
	if ( convent.GetCString(2,m_IntendedScale ) < 0 ){
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
