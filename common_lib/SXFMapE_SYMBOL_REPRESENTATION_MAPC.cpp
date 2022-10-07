/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_SYMBOL_REPRESENTATION_MAPC.cpp						作成日：2000.04.17

	１．クラス概要
		SYMBOL_REPRESENTATION_MAPを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_SYMBOL_REPRESENTATION_MAPC.h"
#include "SXFMapE_AXIS2_PLACEMENT_2DC.h"
#include "SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_REPRESENTATION_MAPC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_SYMBOL_REPRESENTATION_MAPC::SXFMapE_SYMBOL_REPRESENTATION_MAPC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_SYMBOL_REPRESENTATION_MAPC::SXFMapE_SYMBOL_REPRESENTATION_MAPC()
{
	m_EntityName = DEF_ELLIPSE;

	m_axis2_Inst = 0;
	m_axis2_P = NULL;

	m_subfig_rep_Inst=0;
	m_subfig_rep_P =NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_REPRESENTATION_MAPC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_SYMBOL_REPRESENTATION_MAPC::SXFMapE_SYMBOL_REPRESENTATION_MAPC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数  ：	型				引数名				内容
				SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_SYMBOL_REPRESENTATION_MAPC::SXFMapE_SYMBOL_REPRESENTATION_MAPC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_ELLIPSE;

	m_axis2_Inst = 0;
	m_axis2_P = NULL;

	m_subfig_rep_Inst=0;
	m_subfig_rep_P =NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_REPRESENTATION_MAPC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_SYMBOL_REPRESENTATION_MAPC::~SXFMapE_SYMBOL_REPRESENTATION_MAPC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_SYMBOL_REPRESENTATION_MAPC::~SXFMapE_SYMBOL_REPRESENTATION_MAPC()
{
	if(m_axis2_P!= NULL)
		delete m_axis2_P;
	if(m_subfig_rep_P!= NULL)
		delete m_subfig_rep_P;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_REPRESENTATION_MAPC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_SYMBOL_REPRESENTATION_MAPC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_SYMBOL_REPRESENTATION_MAPC::SetParameter( )
{

	SXFMapEntAConvC convent(m_EntityArray);
    
	//引数エラー
	if ( convent.GetInst(0,m_axis2_Inst) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetInst(1,m_subfig_rep_Inst) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	m_axis2_P =
		new SXFMapE_AXIS2_PLACEMENT_2DC(m_InstanceIDManager);
	int ircode = m_axis2_P->SetRootID(m_axis2_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_axis2_P->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	m_subfig_rep_P =
		new SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC(m_InstanceIDManager);
	ircode = m_subfig_rep_P->SetRootID(m_subfig_rep_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_subfig_rep_P->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	return 0;
}
