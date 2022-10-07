/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_CURVE_STYLE_FONT_PATTERNC.cpp						作成日：2000.04.17

	１．クラス概要
		EntityDataを型変換する

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_CURVE_STYLE_FONT_PATTERNC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONT_PATTERNC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_CURVE_STYLE_FONT_PATTERNC::SXFMapE_CURVE_STYLE_FONT_PATTERNC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_CURVE_STYLE_FONT_PATTERNC::SXFMapE_CURVE_STYLE_FONT_PATTERNC()
{
//	<初期化>
	m_EntityName = DEF_CURVE_STYLE_FONT_PATTERN;
//#81 = CURVE_STYLE_FONT_PATTERN(4., 2.);
//<エンティティデータ>
//	m_name.Empty();		//nameパラメタ
	m_visi = 0;		//表示部分の長さ
	m_invisi = 0;	//非表示部分の長さ

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONT_PATTERNC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_CURVE_STYLE_FONT_PATTERNC::SXFMapE_CURVE_STYLE_FONT_PATTERNC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_CURVE_STYLE_FONT_PATTERNC::SXFMapE_CURVE_STYLE_FONT_PATTERNC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<初期化>
	m_EntityName = DEF_CURVE_STYLE_FONT_PATTERN;
//#81 = CURVE_STYLE_FONT_PATTERN(4., 2.);
//<エンティティデータ>
//	m_name.Empty();		//nameパラメタ
	m_visi = 0;		//表示部分の長さ
	m_invisi = 0;	//非表示部分の長さ
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONT_PATTERNC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_CURVE_STYLE_FONT_PATTERNC::~SXFMapE_CURVE_STYLE_FONT_PATTERNC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_CURVE_STYLE_FONT_PATTERNC::~SXFMapE_CURVE_STYLE_FONT_PATTERNC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONT_PATTERNC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_CURVE_STYLE_FONT_PATTERNC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/


int SXFMapE_CURVE_STYLE_FONT_PATTERNC::SetParameter()

{
//	ADD(S)	バグ修正	K.Naono	01.09.26
	if( m_EntityArray->GetSize() != 2 ) {
		//エンティティパラメタの数に謝りがあります。
			SXFErrorMsgC::RecordError(
				SXFPARAMS,			//errメッセージ番号
				m_EntityName,		//エンティティ名
				2,					//パラメタの個数
				m_RootID,			//パラメタ
				m_EntityName
				);
		return SXFPARAMS;	//-55003
	}
//	ADD(E)	バグ修正	K.Naono	01.09.26

//#81 = CURVE_STYLE_FONT_PATTERN(4., 2.);
	SXFMapEntAConvC convent(m_EntityArray);
	//<name>
//	convent.GetCString(0,m_name);
	convent.GetDouble(0,m_visi);
	convent.GetDouble(1,m_invisi);

//	m_visi ;	//表示部分の長さ
//	m_invisi ;	//非表示部分の長さ
/*	int num;
	CArray<double,double> array;
	convent.GetSetDouble(0,num,array);
	if ( num >=2 ){
		m_visi   = array[0];
		m_invisi = array[1];
	}
	else{
		//エンティティパラメタの数に謝りがあります。
			SXFErrorMsgC::RecordError(
				SXFPARAMS,			//errメッセージ番号
				m_EntityName,		//エンティティ名
				2,					//パラメタの個数
				m_RootID,			//パラメタ
				m_EntityName
				);
		return SXFPARAMS;	//-55003
	}*/
	return 0;
}
