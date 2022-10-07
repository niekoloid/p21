/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapFeatureBaseC.h						作成日：2000.04.17

	１．クラス概要
		ルートエンティティID、フィーチャの種別（アセンブリ、定義テーブル、一般）、
		フィーチャ名を管理する

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapFeatureBaseC_CLASS_
#define _SXFMapFeatureBaseC_CLASS_

#include <afx.h>

#include "SXFF_FeatureTypeE.h"
#include "SXFMapBaseC.h"

class SXFInstanceIDC;

class SXFMapFeatureBaseC : public SXFMapBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapFeatureBaseC( ) ;
	
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapFeatureBaseC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<コンストラクタ：ルートフィーチャＩＤを登録する>
	SXFMapFeatureBaseC(int) ;
//

//	<デストラクタ>
//
	virtual	~SXFMapFeatureBaseC() ;

//	<フィーチャ種別の設定>
//	int	SetFetureKind(int);
//
//	<フィーチャ種別の取得>
//	int	GetFetureKind();
//
//	<フィーチャ名の設定>
	int	SetFeatureName(CString);
//
//	<フィーチャ名の取得>
	CString	GetFeatureName();
	
//
//	<フィーチャのルートエンティティへのポインタの設定>
//	int	SetRootEntityP(void*);

/////// メンバ変数 //////////////////////////////////////////////
//
//	<フィーチャ名>
	CString	m_TypeName;

//	<フィーチャタイプ>
	E_type m_Type;

//	<フィーチャ構造体へのポインタ>
	void*	m_StructData;	
//
//	<フィーチャ種別>
//	int		m_FeatureKind;
//	0:不明 1:定義テーブル要素 2:アセンブリ要素
//	3:一般要素 99:その他（非表示、単位系）

//	<フィーチャのルートエンティティへのポインタ>
//	void*	m_RootEntityP;

private :

protected :

} ;
#endif
