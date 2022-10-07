/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_PLANAR_BOXC.cpp						作成日：2000.04.17

	１．クラス概要
		PLANAR_BOXを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_PLANAR_BOXC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PLANAR_BOXC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_PLANAR_BOXC::SXFMapE_PLANAR_BOXC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_PLANAR_BOXC::SXFMapE_PLANAR_BOXC()
{
	m_EntityName = DEF_PLANAR_BOX;

	m_Size_x = 0.0;
	m_Size_y = 0.0;

	m_Placement_Inst = 0;
	m_Placement_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PLANAR_BOXC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_PLANAR_BOXC::SXFMapE_PLANAR_BOXC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)

					

	引数 ：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_PLANAR_BOXC::SXFMapE_PLANAR_BOXC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_PLANAR_BOX;

	m_Size_x = 0.0;
	m_Size_y = 0.0;

	m_Placement_Inst = 0;
	m_Placement_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PLANAR_BOXC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_PLANAR_BOXC::~SXFMapE_PLANAR_BOXC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_PLANAR_BOXC::~SXFMapE_PLANAR_BOXC()
{

	if(m_Placement_p !=NULL)
		delete m_Placement_p;

}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PLANAR_BOXC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_PLANAR_BOXC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_PLANAR_BOXC::SetParameter( )
{

	int ircode;

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
	if ( convent.GetDouble(1,m_Size_x ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetDouble(2,m_Size_y ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetInst(3,m_Placement_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
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

	return 0;
}
