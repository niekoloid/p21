/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_POLYLINEC.cpp						作成日：2000.04.17

	１．クラス概要
		POLYLINEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_POLYLINEC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_POLYLINEC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_POLYLINEC::SXFMapE_POLYLINEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_POLYLINEC::SXFMapE_POLYLINEC()
{
	m_EntityName = DEF_POLYLINE;

	m_PointCount = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_POLYLINEC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_POLYLINEC::SXFMapE_POLYLINEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数  ：	型				引数名				内容
				SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_POLYLINEC::SXFMapE_POLYLINEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_POLYLINE;

	m_PointCount = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_POLYLINEC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_POLYLINEC::~SXFMapE_POLYLINEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_POLYLINEC::~SXFMapE_POLYLINEC()
{
	for(int i=0;i<m_PointArray_p.GetSize();i++){
		if( m_PointArray_p[i] != NULL)
			delete m_PointArray_p[i];
	}
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_POLYLINEC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_POLYLINEC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_POLYLINEC::SetParameter( )
{

	SXFMapEntAConvC convent(m_EntityArray);

	//引数エラー
	if ( convent.GetCString(0,m_PolylineName) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetSetInst(1, m_PointCount, m_PointArray_Inst) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	for(int i=0;i<m_PointCount;i++){
		SXFMapE_CARTESIAN_POINTC* temp_p = 
			new SXFMapE_CARTESIAN_POINTC(m_InstanceIDManager);
		m_PointArray_p.Add(temp_p);

		int ircode = temp_p->SetRootID(m_PointArray_Inst[i]);
		if ( ircode < 0 )
			return ircode ;
		ircode = temp_p->SetParameter();
		if ( ircode < 0 )
			return ircode ;
	}

	return 0;
}
