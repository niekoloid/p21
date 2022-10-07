/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TERMSYMBOLC.cpp					作成日：2000.04.17

	１．クラス概要
		フィーチャの矢印を管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_ColorBaseC.h"
#include "SXFMapF_TERMSYMBOLC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TERMSYMBOLC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_TERMSYMBOLC::SXFMapF_TERMSYMBOLC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_TERMSYMBOLC::SXFMapF_TERMSYMBOLC()
{

	m_Type = dimension_terminator_symbol ;
	m_TypeName = "dimension_terminator_symbol";

	m_flag = 0;				//矢印１２フラグ（０：初期値,１：端点１側, ２：端点２側)
	m_arr_code;				//矢印コード
	m_start_x = 0.0;	    //配置位置X座標
	m_start_y = 0.0;		//配置位置Y座標
	m_scale = 0.0;			//矢印配置倍率
	m_vecter_x =0.0;		//矢印のベクトルX
	m_vecter_y =0.0;		//矢印のベクトルY

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TERMSYMBOLC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_TERMSYMBOLC::~SXFMapF_TERMSYMBOLC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_TERMSYMBOLC::~SXFMapF_TERMSYMBOLC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TERMSYMBOLC.cpp							作成日：2000.05.13

	１．機能概要
		補助線のフラグ設定
	２．インターフェイス
		BOOL SXFMapF_LINEC::Set12flg(
			CString& IN_name )		//	BODY の NAMEパラメタ 


	引数  ：	型			引数名				内容
				CString& 	IN_name

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.05.13	大村(FQS)
**/

//	<補助線の端点１，２どちらか？を表わすフラグ設定>
BOOL SXFMapF_TERMSYMBOLC::Set12flg(CString& IN_name)
{

	CStringArray pojflg;
	CString a1(" ");
	CString a2("$$SXF_arw_1");
	CString a3("$$SXF_arw_2");
	pojflg.Add((LPCTSTR)a1);
	pojflg.Add((LPCTSTR)a2);
	pojflg.Add((LPCTSTR)a3);

//端点１２フラグ（0:初期値,1:端点１側, 2:端点２側)
	m_flag = 0;
	for(int i=1;i<=2;i++){
		if( IN_name==pojflg.GetAt(i)){
			m_flag=i;
			break;
		}
	}
	return TRUE;
}
