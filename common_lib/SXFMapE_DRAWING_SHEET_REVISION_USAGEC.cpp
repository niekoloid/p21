/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_DRAWING_SHEET_REVISION_USAGEC.cpp						作成日：2000.04.17

	１．クラス概要
		DRAWING_SHEET_REVISION_USAGEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_DRAWING_SHEET_REVISION_USAGEC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_SHEET_REVISION_USAGEC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_DRAWING_SHEET_REVISION_USAGEC::SXFMapE_DRAWING_SHEET_REVISION_USAGEC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_DRAWING_SHEET_REVISION_USAGEC::SXFMapE_DRAWING_SHEET_REVISION_USAGEC()
{
	m_EntityName = DEF_DRAWING_SHEET_REVISION_USAGE;

	m_Area_Inst = 0;
	m_Area_p = NULL;

	m_InSet_Inst = 0;
	m_InSet_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_DEFINITIONC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_DRAWING_SHEET_REVISION_USAGEC::SXFMapE_DRAWING_SHEET_REVISION_USAGEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数 ：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_DRAWING_SHEET_REVISION_USAGEC::SXFMapE_DRAWING_SHEET_REVISION_USAGEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_DRAWING_SHEET_REVISION_USAGE;

	m_Area_Inst = 0;
	m_Area_p = NULL;

	m_InSet_Inst = 0;
	m_InSet_p = NULL; 
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_SHEET_REVISION_USAGEC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_DRAWING_SHEET_REVISION_USAGEC::~SXFMapE_DRAWING_SHEET_REVISION_USAGEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_DRAWING_SHEET_REVISION_USAGEC::~SXFMapE_DRAWING_SHEET_REVISION_USAGEC()
{

	if(m_Area_p !=NULL)
		delete m_Area_p;

	if(m_InSet_p !=NULL)
		delete m_InSet_p;

}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_SHEET_REVISION_USAGEC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_DRAWING_SHEET_REVISION_USAGEC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_DRAWING_SHEET_REVISION_USAGEC::SetParameter( )
{

	int ircode;

	SXFMapEntAConvC convent(m_EntityArray);

	//引数エラー
	if ( convent.GetInst(0,m_Area_Inst) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//オブジェクト生成
	m_Area_p = 
		new SXFMapE_DRAWING_SHEET_REVISIONC(m_InstanceIDManager );

	ircode = m_Area_p->SetRootID(m_Area_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_Area_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	//引数エラー
	if ( convent.GetInst(1,m_InSet_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//オブジェクト生成
	m_InSet_p = 
		new SXFMapE_DRAUGHTING_DRAWING_REVISIONC(m_InstanceIDManager );

	ircode = m_InSet_p->SetRootID(m_InSet_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_InSet_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	//引数エラー
	if ( convent.GetCString(2,m_SheetNumber ) < 0 ){
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
