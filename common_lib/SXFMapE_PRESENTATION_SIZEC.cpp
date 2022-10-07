/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_PRESENTATION_SIZEC.cpp						作成日：2000.04.17

	１．クラス概要
		PRESENTATION_SIZEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_PRESENTATION_SIZEC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_SIZEC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_PRESENTATION_SIZEC::SXFMapE_PRESENTATION_SIZEC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_PRESENTATION_SIZEC::SXFMapE_PRESENTATION_SIZEC()
{
	m_EntityName = DEF_PRESENTATION_SIZE;

	m_Unit_Inst = 0;
	m_Unit_p = NULL;
	m_Size_Inst = 0;
	m_Size_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_SIZEC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_PRESENTATION_SIZEC::SXFMapE_PRESENTATION_SIZEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数 ：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_PRESENTATION_SIZEC::SXFMapE_PRESENTATION_SIZEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_PRESENTATION_SIZE;

	m_Unit_Inst = 0;
	m_Unit_p = NULL;
	m_Size_Inst = 0;
	m_Size_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_SIZEC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_PRESENTATION_SIZEC::~SXFMapE_PRESENTATION_SIZEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_PRESENTATION_SIZEC::~SXFMapE_PRESENTATION_SIZEC()
{

	if(m_Unit_p !=NULL)
		delete m_Unit_p;

	if(m_Size_p != NULL)
		delete m_Size_p;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_SIZEC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_PRESENTATION_SIZEC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_PRESENTATION_SIZEC::SetParameter( )
{

	int ircode;

	SXFMapEntAConvC convent(m_EntityArray);

	//引数エラー
	if ( convent.GetInst(0,m_Unit_Inst) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	m_Unit_p = 
		new SXFMapE_DRAWING_SHEET_REVISIONC(m_InstanceIDManager );

	ircode = m_Unit_p->SetRootID(m_Unit_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_Unit_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	//引数エラー
	if ( convent.GetInst(1,m_Size_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	m_Size_p = 
		new SXFMapE_PLANAR_BOXC(m_InstanceIDManager );

	ircode = m_Size_p->SetRootID(m_Size_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_Size_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	return 0;
}
