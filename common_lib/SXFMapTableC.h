/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapTableC.h						作成日：2000.04.21

	１．クラス概要
		定義テーブルのマッピングを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.21	

**/
#ifndef _SXFMapTableC_CLASS_
#define _SXFMapTableC_CLASS_

#include <afx.h>
#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFComInfoC;
class SXFTableManagerC;//ID_218_000706_ins

class SXFMapTableC: public SXFMapEntityBaseC{
public :
//
//	<デフォルトコンストラクタ>
	SXFMapTableC( ) ;

//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapTableC(
		SXFInstanceIDC* IN_InstanceIDManeger,
		SXFComInfoC* IN_ComInfoC,
		SXFTableManagerC* IN_TableManager) ;

//	<コンストラクタ：ルートＩＤとフィーチャ種別を登録し生成する>
	SXFMapTableC(int,int) ;

//

//	<デストラクタ>
	virtual	~SXFMapTableC() ;

//	<アセンブリ要素のルートＩＤの登録>
//	int		SetAssemblyRootID(int) ;
//	<一般要素のルートＩＤの登録とBody種別判定>
//	int		SetGeometryRootID(int) ;
//
//	<フィーチャ構造体への値の設定>
	int	SetFeatureParameter(int& OUT_Type,	LPVOID&	OUT_Class);

//
//	<定義テーブル要素のルートEntityへのポインタの取得>
//	void*	GetBodyP();


//	<Layerのエレメント＞
//	CArray<int,int>	m_LayerElements;
	CUIntArray	m_LayerElements;

private :

protected :

//	<SXFComInfoCへのポインタ>
		SXFComInfoC* m_ComInfoC;

//	<Table種別>
	int			m_Type ;

//	<Bodyへのポインタ>
	void*		m_BodyP ;

	SXFTableManagerC* m_TableManager;


} ;
#endif
