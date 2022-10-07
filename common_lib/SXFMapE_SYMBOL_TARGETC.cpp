/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_SYMBOL_TARGETC.cpp						作成日：2000.04.17

	１．クラス概要
		SYMBOL_TARGETを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_SYMBOL_TARGETC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_TARGETC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_SYMBOL_TARGETC::SXFMapE_SYMBOL_TARGETC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_SYMBOL_TARGETC::SXFMapE_SYMBOL_TARGETC()
{
	m_EntityName = DEF_SYMBOL_TARGET;

	m_Placement_Inst = 0;
	m_Placement_p = NULL;
	m_Scale_x = 0.0;
	m_Scale_y = 0.0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_TARGETC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_SYMBOL_TARGETC::SXFMapE_SYMBOL_TARGETC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数  ：	型				引数名				内容
				SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_SYMBOL_TARGETC::SXFMapE_SYMBOL_TARGETC(
	SXFInstanceIDC* IN_InstanceIDManeger)
	:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_SYMBOL_TARGET;

	m_Placement_Inst = 0;
	m_Placement_p = NULL;
	m_Scale_x = 0.0;
	m_Scale_y = 0.0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_TARGETC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_SYMBOL_TARGETC::~SXFMapE_SYMBOL_TARGETC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_SYMBOL_TARGETC::~SXFMapE_SYMBOL_TARGETC()
{

	if(m_Placement_p !=NULL)
		delete m_Placement_p;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_TARGETC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_SYMBOL_TARGETC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_SYMBOL_TARGETC::SetParameter( )
{

	int ircode;

	SXFMapEntAConvC convent(m_EntityArray);

	//引数エラー
	if ( convent.GetCString(0,m_Name) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetInst(1,m_Placement_Inst ) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	m_Placement_p =
		new SXFMapE_AXIS2_PLACEMENT_2DC(m_InstanceIDManager );

	ircode = m_Placement_p->SetRootID(m_Placement_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_Placement_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	//引数エラー
	if ( convent.GetDouble(2,m_Scale_x ) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetDouble(3,m_Scale_y ) < 0 ){
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
