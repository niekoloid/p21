/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC.cpp						作成日：2000.04.17

	１．クラス概要
		PRE_DEFINED_POINT_MARKER_SYMBOLを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC::SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC::SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC()
{
	m_EntityName = DEF_PRE_DEFINED_POINT_MARKER_SYMBOL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC::SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC(
							SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数  ：	型				引数名				内容
				SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC::SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_PRE_DEFINED_POINT_MARKER_SYMBOL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC::~SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC::~SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC::SetParameter( )
{

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

//	<ポイントマーカーコードの判定>
//     wr1: SELF.name IN ['asterisk','circle','dot','plus','square',
//               'triangle','x'];

	if (m_Name=="asterisk") {
		m_code = 1;
	}
	else if (m_Name=="circle") {
		m_code = 2;
	}
	else if (m_Name=="dot") {
		m_code = 3;
	}
	else if (m_Name=="plus") {
		m_code = 4;
	}
	else if (m_Name=="square") {
		m_code = 5;
	}
	else if (m_Name=="triangle") {
		m_code = 6;
	}
	else if (m_Name=="x") {
		m_code = 7;
	}
	else {
		//err ポイントマーカーの名前が正しくない
	}

	return 0;
}
