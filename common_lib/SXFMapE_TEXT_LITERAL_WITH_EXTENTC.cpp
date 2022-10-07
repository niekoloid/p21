/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_TEXT_LITERAL_WITH_EXTENTC.cpp						作成日：2000.04.17

	１．クラス概要
		TEXT_LITERAL_WITH_EXTENTを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_TEXT_LITERAL_WITH_EXTENTC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_LITERAL_WITH_EXTENTC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_TEXT_LITERAL_WITH_EXTENTC::SXFMapE_TEXT_LITERAL_WITH_EXTENTC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_TEXT_LITERAL_WITH_EXTENTC::SXFMapE_TEXT_LITERAL_WITH_EXTENTC()
{
	m_EntityName = DEF_TEXT_LITERAL_WITH_EXTENT;

	m_Placement_Inst = 0;
	m_Placement_p = NULL;
	m_Font_Inst = 0;
	//m_Font_p = NULL;
	m_PlanarExtent_Inst = 0;
	m_PlanarExtent_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_LITERAL_WITH_EXTENTC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_TEXT_LITERAL_WITH_EXTENTC::SXFMapE_TEXT_LITERAL_WITH_EXTENTC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数  ：	型				引数名				内容
				SXFInstanceIDC* IN_InstanceIDManeger		ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_TEXT_LITERAL_WITH_EXTENTC::SXFMapE_TEXT_LITERAL_WITH_EXTENTC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_TEXT_LITERAL_WITH_EXTENT;

	m_Placement_Inst = 0;
	m_Placement_p = NULL;
	m_Font_Inst = 0;
	//m_Font_p = NULL;
	m_PlanarExtent_Inst = 0;
	m_PlanarExtent_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_LITERAL_WITH_EXTENTC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_TEXT_LITERAL_WITH_EXTENTC::~SXFMapE_TEXT_LITERAL_WITH_EXTENTC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_TEXT_LITERAL_WITH_EXTENTC::~SXFMapE_TEXT_LITERAL_WITH_EXTENTC()
{
	if(m_Placement_p != NULL)
		delete m_Placement_p;
	if(m_PlanarExtent_p != NULL)
		delete m_PlanarExtent_p;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_LITERAL_WITH_EXTENTC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_TEXT_LITERAL_WITH_EXTENTC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_TEXT_LITERAL_WITH_EXTENTC::SetParameter( )
{

	int ircode;

//	Text Literalの中に ', 'が入っていると、
//	EntityDataはそこで分割される。
//	=>  EntityDataの後ろからデータを取る。
//#485 = TEXT_LITERAL_WITH_EXTENT(
//	'$$SXF_baseline centre', 
//	'Part21 \X2\30EC30D930EB\X0\1',
// #484, 'baseline centre', .RIGHT., #180, #481);

	INT_PTR size;
	size = m_EntityArray->GetSize();
	//引数エラー
	if ( size <7 ) {
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

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
	if ( convent.GetCString(1,m_Literal ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetInst((int)(size-5),m_Placement_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	m_Placement_p = new SXFMapE_AXIS2_PLACEMENT_2DC(m_InstanceIDManager);

	ircode = m_Placement_p->SetRootID(m_Placement_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_Placement_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	//引数エラー
	if ( convent.GetCString((int)(size - 4) ,m_Alignment ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetCString((int)(size-3),m_Path ) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetInst((int)(size-2),m_Font_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetInst((int)(size-1),m_PlanarExtent_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	m_PlanarExtent_p = new SXFMapE_PLANAR_EXTENTC(m_InstanceIDManager);

	ircode = m_PlanarExtent_p->SetRootID(m_PlanarExtent_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_PlanarExtent_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	return 0;
}
