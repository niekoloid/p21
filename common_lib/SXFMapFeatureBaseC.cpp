/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapFeatureBaseC.cpp						作成日：2000.04.17

	１．クラス概要
		ルートエンティティID、フィーチャの種別（アセンブリ、定義テーブル、一般）、
		フィーチャ名を管理する

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapFeatureBaseC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapFeatureBaseC.cpp						作成日：2000.04.17

	１．機能概要
		コンストラクタ

	２．インターフェイス
		void	SXFMapFeatureBaseC::SXFMapFeatureBaseC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapFeatureBaseC::SXFMapFeatureBaseC()
{
//
//	<初期化>
//
	m_TypeName.Empty();
	m_Type = NONFEATURE;
	m_StructData = NULL;
//	m_FeatureKind	 =0; 
//	m_RootEntityP	=NULL ;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapFeatureBaseC.cpp						作成日：2000.04.17

	１．機能概要
		コンストラクタ

	２．インターフェイス
		void	SXFMapFeatureBaseC::SXFMapFeatureBaseC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapBaseC(IN_InstanceIDManeger)
					

	引数  ：	型				引数名				内容
				SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

//	<インスタンスＩＤへのポインタを登録し生成する>
SXFMapFeatureBaseC::SXFMapFeatureBaseC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapBaseC(IN_InstanceIDManeger)
{
	m_TypeName.Empty();
	m_Type = NONFEATURE;
	m_StructData = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapFeatureBaseC.cpp						作成日：2000.04.17

	１．機能概要
		デストラクタ

	２．インターフェイス
		void	SXFMapFeatureBaseC::~SXFMapFeatureBaseC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapFeatureBaseC::~SXFMapFeatureBaseC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapFeatureBaseC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャ名の設定

	２．インターフェイス
		int		SXFMapFeatureBaseC::SetFeatureName(CString IN_FeatureName)

	引数  ：	型			引数名				内容
				CString 	IN_FeatureName　	ﾌｨｰﾁｬ名

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapFeatureBaseC::SetFeatureName(
			CString IN_FeatureName)
{
	m_TypeName = IN_FeatureName;
	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapFeatureBaseC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャ名の取得

	２．インターフェイス
		int		SXFMapFeatureBaseC::GetFeatureName()

	引数  ：	型			引数名				内容
			なし

	復帰値：フィーチャ名

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
CString SXFMapFeatureBaseC::GetFeatureName()
{
	return (m_TypeName) ;
}
