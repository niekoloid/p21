/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_ELLIPSEC.cpp						作成日：2000.04.17

	１．クラス概要
		ELLIPSEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_ELLIPSEC.h"
#include "SXFMapE_AXIS2_PLACEMENT_2DC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ELLIPSEC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_ELLIPSEC::SXFMapE_ELLIPSEC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_ELLIPSEC::SXFMapE_ELLIPSEC()
{
	m_EntityName = DEF_ELLIPSE;

	m_axis2_Inst = 0;
	m_axis2_P = NULL;

	m_semi_axis_1 = 0.0;
	m_semi_axis_2 = 0.0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ELLIPSEC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_ELLIPSEC::SXFMapE_ELLIPSEC(
					SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数 ：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_ELLIPSEC::SXFMapE_ELLIPSEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_ELLIPSE;

	m_axis2_Inst = 0;
	m_axis2_P = NULL;

	m_semi_axis_1 = 0.0;
	m_semi_axis_2 = 0.0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ELLIPSEC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_ELLIPSEC::~SXFMapE_ELLIPSEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_ELLIPSEC::~SXFMapE_ELLIPSEC()
{
	if(m_axis2_P!= NULL)
		delete m_axis2_P;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ELLIPSEC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_ELLIPSEC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_ELLIPSEC::SetParameter( )
{

	SXFMapEntAConvC convent(m_EntityArray);

	//引数エラー
	if ( convent.GetCString(0,m_EllipseName) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetInst(1,m_axis2_Inst) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetDouble(2,m_semi_axis_1) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetDouble(3,m_semi_axis_2) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//オブジェクト生成
	m_axis2_P = 
		new SXFMapE_AXIS2_PLACEMENT_2DC(m_InstanceIDManager);
	int ircode = m_axis2_P->SetRootID(m_axis2_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_axis2_P->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	return 0;
}
