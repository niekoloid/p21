/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC.cpp						作成日：2000.04.17

	１．クラス概要
		PRESENTATION_LAYER_ASSIGNMENTを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC::SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC::SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC()
{
	m_EntityName = DEF_PRESENTATION_LAYER_ASSIGNMENT;

	m_AssignedItemsCount = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC::SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC(
								SXFInstanceIDC* IN_InstanceIDManeger)
  		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数  ：	型				引数名				内容
				SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC::SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC(
		SXFInstanceIDC* IN_InstanceIDManeger)
  		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
	m_EntityName = DEF_PRESENTATION_LAYER_ASSIGNMENT;

	m_AssignedItemsCount = 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC::~SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC::~SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC::SetParameter( )
{

/*
  ENTITY presentation_layer_assignment;
      name           : label;
      description    : text;
      assigned_items : SET [1:?] OF layered_item;
  END_ENTITY; -- presentation_layer_assignment */
  
//#1440 = PRESENTATION_LAYER_ASSIGNMENT
//('LayerCurve', 'layer associated with label, balloon, polyline and bezier', 
//(#1168, #1177, .........));

	SXFMapEntAConvC convent(m_EntityArray);
	INT_PTR size;
	size = m_EntityArray->GetSize();

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

 //[1]='layer associated with label'
 //[2]=' balloon'
 //[3]=' polyline and bezier'
//		=>[1]+[2]+[3]

	CString tmpcstring, comma;
	comma =',';

	for ( int i=1 ; i <size-1 ;i++){
		//引数エラー
		if ( convent.GetCString(i,tmpcstring) < 0 ){
			SXFErrorMsgC::RecordError( SXFPARAMS,
										m_EntityName,
										2,
										m_RootID,
										m_EntityName
										);
			return SXFPARAMS;
		}
		if (i<size-2)tmpcstring+=comma;
		m_Description+=tmpcstring;
	}

//	name,description の中に ', 'が入っていると、
//	EntityDataはそこで分割される。
//	=>  EntityDataの後ろからデータを取る。

	if ( convent.GetSetInst( (int)(size-1),m_AssignedItemsCount,
		m_AssignedItems ) < 0 ){
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
