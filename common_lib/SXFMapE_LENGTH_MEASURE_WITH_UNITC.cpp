/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_LENGTH_MEASURE_WITH_UNITC.cpp						作成日：2001.06.17

	１．クラス概要
		LENGTH_MEASURE_WITH_UNITを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2001.06.17	

**/
#include "stdafx.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_LENGTH_MEASURE_WITH_UNITC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LENGTH_MEASURE_WITH_UNITC.cpp						作成日：2001.06.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_LENGTH_MEASURE_WITH_UNITC::SXFMapE_LENGTH_MEASURE_WITH_UNITC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.06.17	
**/
SXFMapE_LENGTH_MEASURE_WITH_UNITC::SXFMapE_LENGTH_MEASURE_WITH_UNITC()
{
	m_EntityName = DEF_LENGTH_MEASURE_WITH_UNIT;

	m_Width = 0.0;
	m_UnitComponent_Inst = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LENGTH_MEASURE_WITH_UNITC.cpp						作成日：2001.06.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_LENGTH_MEASURE_WITH_UNITC::SXFMapE_LENGTH_MEASURE_WITH_UNITC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数 ：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.06.17	
**/
SXFMapE_LENGTH_MEASURE_WITH_UNITC::SXFMapE_LENGTH_MEASURE_WITH_UNITC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_LENGTH_MEASURE_WITH_UNIT;

	m_Width = 0.0;
	m_UnitComponent_Inst = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LENGTH_MEASURE_WITH_UNITC.cpp						作成日：2001.06.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_LENGTH_MEASURE_WITH_UNITC::~SXFMapE_LENGTH_MEASURE_WITH_UNITC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.06.17	
**/
SXFMapE_LENGTH_MEASURE_WITH_UNITC::~SXFMapE_LENGTH_MEASURE_WITH_UNITC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LENGTH_MEASURE_WITH_UNITC.cpp						作成日：2001.06.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_LENGTH_MEASURE_WITH_UNITC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.06.17	
**/
int SXFMapE_LENGTH_MEASURE_WITH_UNITC::SetParameter( )
{

	SXFMapEntAConvC convent(m_EntityArray);

	CString tempstring;
	//引数エラー
	if ( convent.GetCString(0,tempstring) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	int left = tempstring.Find('(');
	int right = tempstring.Find(')');

	CString widthstring = tempstring.Mid(left+1,right-left-1);

	m_Width = atof(widthstring);

	//線幅が異常
	if(m_Width<0){
		SXFErrorMsgC::RecordError(	SXFWIDTHERROR,
									m_EntityName,
									1,
									m_Width);
		return SXFWIDTHERROR;
	}

	//引数エラー
	if ( convent.GetInst(1,m_UnitComponent_Inst) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	return 0;
}
