/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_ANNOTATION_FILL_AREAC.cpp						作成日：2000.04.21

	１．クラス概要
	ANNOTATION_FILL_AREAを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.21	

**/

#include "stdafx.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_ANNOTATION_FILL_AREAC.h"
#include "SXFMapE_COMPOSITE_CURVEC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ANNOTATION_FILL_AREAC.cpp						作成日：2000.04.21

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		SXFMapE_ANNOTATION_FILL_AREAC::SXFMapE_ANNOTATION_FILL_AREAC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/

SXFMapE_ANNOTATION_FILL_AREAC::SXFMapE_ANNOTATION_FILL_AREAC()
{
	m_EntityName = DEF_ANNOTATION_FILL_AREA;

	m_BoundaryCont = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ANNOTATION_FILL_AREAC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_ANNOTATION_FILL_AREAC::SXFMapE_ANNOTATION_FILL_AREAC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数：	型					引数名					内容
			SXFInstanceIDC* 	IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

SXFMapE_ANNOTATION_FILL_AREAC::SXFMapE_ANNOTATION_FILL_AREAC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_ANNOTATION_FILL_AREA;
	m_BoundaryCont = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ANNOTATION_FILL_AREAC.cpp						作成日：2000.04.21

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_ANNOTATION_FILL_AREAC::~SXFMapE_ANNOTATION_FILL_AREAC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/
SXFMapE_ANNOTATION_FILL_AREAC::~SXFMapE_ANNOTATION_FILL_AREAC()
{
	for(int i=0;i<m_Boundary_P.GetSize();i++){
		if( m_Boundary_P[i] != NULL)
			delete m_Boundary_P[i];
	}
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ANNOTATION_FILL_AREAC.cpp						作成日：2000.04.21

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		void	SXFMapE_ANNOTATION_FILL_AREAC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/

int SXFMapE_ANNOTATION_FILL_AREAC::SetParameter( )
{

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
	if ( convent.GetSetInst(1, m_BoundaryCont, m_Boundary_Inst) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
								m_EntityName,
								2,
								m_RootID,
								m_EntityName
								);
		return SXFPARAMS;
	}
	
	//オブジェクト生成
	for(int i=0;i<m_BoundaryCont;i++){
		SXFMapE_COMPOSITE_CURVEC* temp_p = 
			new SXFMapE_COMPOSITE_CURVEC(m_InstanceIDManager);
		m_Boundary_P.Add(temp_p);

		int ircode = temp_p->SetRootID(m_Boundary_Inst[i]);
		if ( ircode < 0 )
			return ircode ;
		ircode = temp_p->SetParameter();
		if ( ircode < 0 )
			return ircode ;
	}

	return 0;
}
