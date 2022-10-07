/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_CLOTHOIDC.cpp						作成日：2007.01.30

	１．クラス概要
		SXFMapE_CLOTHOIDCを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2007.01.30	

**/
#include "stdafx.h"
#include "SXFMapE_CLOTHOIDC.h"
#include "SXFMapE_CARTESIAN_POINTC.h"
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
	SXFMapE_CLOTHOIDC.cpp						作成日：2007.01.30

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_CLOTHOIDC::SXFMapE_CLOTHOIDC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2007.01.30	
**/
SXFMapE_CLOTHOIDC::SXFMapE_CLOTHOIDC()
{
	m_EntityName = DEF_CLOTHOID;
	m_parameter = 0.0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CLOTHOIDC.cpp						作成日：2007.01.30

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_CLOTHOIDC::SXFMapE_CLOTHOIDC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数  ：	型				引数名				内容
				SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2007.01.30	
**/
SXFMapE_CLOTHOIDC::SXFMapE_CLOTHOIDC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_CLOTHOID;
	m_parameter = 0.0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CLOTHOIDC.cpp						作成日：2007.01.30

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_CLOTHOIDC::~SXFMapE_CLOTHOIDC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2007.01.30	
**/
SXFMapE_CLOTHOIDC::~SXFMapE_CLOTHOIDC()
{
	if(m_axis2_P != NULL)
	{
		delete m_axis2_P;
	}
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CLOTHOIDC.cpp						作成日：2007.01.30

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_CLOTHOIDC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2007.01.30	
**/
int SXFMapE_CLOTHOIDC::SetParameter( )
{

	SXFMapEntAConvC convent(m_EntityArray);

	//引数エラー
	if ( convent.GetCString(0,m_direction) < 0 ){
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
	if ( convent.GetDouble(2,m_parameter) < 0 ){
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
